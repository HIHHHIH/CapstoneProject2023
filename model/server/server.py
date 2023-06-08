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
    fp = open('sample00_rep00_smpl_params.npy (1).fbx','r')
    lines = fp.readlines()
    #cnt = 0
    for line in lines:
        datasize = str(len(line))
        connected_socket.sendall(datasize.encode())
        ans = connected_socket.recv(3)
        connected_socket.sendall(line.encode())
        #if cnt == 5:
        #    break
        #cnt = cnt + 1
    datasize = "0"
    connected_socket.sendall(datasize.encode())
    """
    print("Enter Handler")
    datasize = "20"
    connected_socket.sendall(datasize.encode())
    """

    """
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
    """

    '''
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
    '''

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
    """
    fp = open('sample00_rep00_smpl_params.npy (1).fbx','r')
    lines = fp.readlines()
    cnt = 0
    for line in lines:
        print(len(line))
        print(line)
        if cnt == 5:
            break
        cnt = cnt + 1
        #connected_socket.sendall(datasize.encode())
        #connected_socket.sendall(line.encode())
    #datasize = "0"
    #connected_socket.sendall(datasize.encode())
    """

    #accept_func()
    #num = 0
    '''
    out_path = "output/" + str(num)
    while os.path.exists(out_path):
        shutil.rmtree(out_path)
        num += 1
        out_path = "output/" + str(num)
    input_text = "the person walked forward and is picking up his toolbox."
    subprocess.call(["python","-m","sample.generate","--model_path","./save/humanml_trans_enc_512/model000200000.pt","--num_samples","1","--num_repetitions","1","--text_prompt",input_text])
    '''
    
    '''
    # SMPL_to_Fbx
    input_pkl_base = './output/' + str(num) + '/'
    fbx_source_base = './fbx/SMPL_m_unityDoubleBlends_lbs_10_scale5_207_v1.0.0.fbx'
    output_base = './output/' + str(num) + '/'
    subprocess.call(["python","Convert.py","--input_pkl_base",input_pkl_base,"--fbx_source_path",fbx_source_base,"--output_base",output_base])
    #'''
    
    #args = generate_args()
    #args.text_prompt = "the person walked forward and is picking up his toolbox."
    #generate_motion(args)
    #print("RUN")
    #accept_func()