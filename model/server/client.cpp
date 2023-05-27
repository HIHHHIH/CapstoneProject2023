/*
	 [프로젝트 속성]->[구성 속성]->[링커]->[입력]->[추가 종속성]에 ws2_32.lib를 추가
	 [프로젝트 속성]->[구성 속성]->[매니페스트 도구]->[입력 및 출력] ->[매니페스트 포함]을 아니요로 변경
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