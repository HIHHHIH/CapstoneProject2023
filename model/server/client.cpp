/*
	 [������Ʈ �Ӽ�]->[���� �Ӽ�]->[��Ŀ]->[�Է�]->[�߰� ���Ӽ�]�� ws2_32.lib�� �߰�
	 [������Ʈ �Ӽ�]->[���� �Ӽ�]->[�Ŵ��佺Ʈ ����]->[�Է� �� ���] ->[�Ŵ��佺Ʈ ����]�� �ƴϿ�� ����
*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <winsock2.h>
#include "socket_client.h"

using namespace std;

int main(int argc, char* argv[]) {
	connect_server();
	printf("connected!\n");

	int bufsize = recv_data_size();
	cout << bufsize << endl;

	char* recv_buf = (char*)malloc(sizeof(char) * (bufsize + 1));
	recv_data(recv_buf, bufsize);

	printf("%s", recv_buf);
	free(recv_buf);

	return 0;
}