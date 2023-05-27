/*
	 [프로젝트 속성]->[구성 속성]->[링커]->[입력]->[추가 종속성]에 ws2_32.lib를 추가
	 [프로젝트 속성]->[구성 속성]->[매니페스트 도구]->[입력 및 출력] ->[매니페스트 포함]을 아니요로 변경
*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <winsock2.h>
#include "socket.h"

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