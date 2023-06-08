#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
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

void read_data(char* buffer, int size) {
	strLen = recv(hSocket, buffer, size, 0);
	if (strLen <= 0)
		printf("read() error!");
}

void send_data(char* message, int size) {
	send(hSocket, message, size, 0);
}