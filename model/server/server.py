import numpy as np
import subprocess
from socket import *
import threading
import os
import shutil

port = 8080

def handler(connected_socket, addr):
    print("Enter Handler")

    # model run
    out_path = "output/" + str(num)
    while os.path.exists(out_path):
        shutil.rmtree(out_path)
        num += 1
        out_path = "output/" + str(num)
    input_text = "the person walked forward and is picking up his toolbox."
    subprocess.call(["python","-m","sample.generate","--model_path","./save/humanml_trans_enc_512/model000200000.pt","--num_samples","1","--num_repetitions","1","--text_prompt",input_text])

    # SMPL_to_Fbx
    input_pkl_base = './output/' + str(num) + '/'
    fbx_source_base = './fbx/SMPL_m_unityDoubleBlends_lbs_10_scale5_207_v1.0.0.fbx'
    output_base = './output/' + str(num) + '/'
    subprocess.call(["python","Convert.py","--input_pkl_base",input_pkl_base,"--fbx_source_path",fbx_source_base,"--output_base",output_base])

    final_path = output_base + str(num) + '.npy.fbx'
    fp = open(final_path,'r')
    # send fbx file to client
    lines = fp.readlines()
    for line in lines:
        datasize = str(len(line))
        connected_socket.sendall(datasize.encode())
        ans = connected_socket.recv(3)
        connected_socket.sendall(line.encode())
    datasize = "0"
    connected_socket.sendall(datasize.encode())

    print("Send Finish")

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
    accept_func()