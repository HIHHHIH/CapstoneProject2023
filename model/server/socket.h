#include <iostream>
#include <cstdlib>
#include <winsock2.h>

WSADATA wsaData;
SOCKET hSocket;
SOCKADDR_IN servAddr;
int port = 8080;
char addr[] = "127.0.0.1";
int strLen;

void connect_server() {
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		printf("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		printf("socket() error!");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(addr);
	servAddr.sin_port = htons(port);

	if (connect(hSocket, (SOCKADDR*)& servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		printf("connect() error!");
}

int recv_data_size() {
	char datasize[30];
	strLen = recv(hSocket, message, sizeof(message) - 1, 0);
	if (strLen <= 0)
		printf("read() error!");
	return atoi(datasize);
}