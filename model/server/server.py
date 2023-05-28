import numpy as np
import subprocess
from socket import *
import threading
import os
import shutil
# from sample.generate import generate_motion
# from utils.parser_util import generate_args

port = 8080

def handler(connected_socket, addr):
    print("Enter Handler")
    # model run
    data = np.load('results.npy', allow_pickle=True)

    print("send data to ", addr)

    data = np.array2string(data)
    datasize = str(len(data))
    print("datasize: ", datasize)
    connected_socket.sendall(datasize.encode())

    ans = connected_socket.recv(1024)
    print(ans)

    connected_socket.sendall(data.encode())
    print("Finished")
    connected_socket.close()

def accept_func():
    server_socket = socket(AF_INET, SOCK_STREAM)
    server_socket.bind(('', port))

    server_socket.listen(5)

    while 1:
        try:
            connected_socket, addr = server_socket.accept()
        except KeyboardInterrupt:
            server_socket.close()

        t = threading.Thread(target=handler, args=(connected_socket, addr))
        t.daemon = True
        t.start()


if __name__ == '__main__':
    num = 0
    out_path = "output/" + str(num)
    while os.path.exists(out_path):
        shutil.rmtree(out_path)
        num += 1
        out_path = "output/" + str(num)
    input_text = "the person walked forward and is picking up his toolbox."
    subprocess.call(["python","-m","sample.generate","--model_path","./save/humanml_trans_enc_512/model000200000.pt","--num_samples","1","--num_repetitions","1","--text_prompt",input_text])
    #args = generate_args()
    #args.text_prompt = "the person walked forward and is picking up his toolbox."
    #generate_motion(args)
    #print("RUN")
    #accept_func()