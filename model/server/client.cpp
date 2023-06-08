#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <winsock2.h>
#include "socket_client.h"

using namespace std;
char buffer[10000];

int main(int argc, char* argv[]) {
	connect_server();
	printf("connected!\n");

	int size;
	char datasize[20];
	while (1) {
		memset(datasize, 0, 20);
		read_data(datasize, 20);
		char ok[3] = "ok";
		send_data(ok, 3);
		size = atoi(datasize);
		if (size == 0)
			break;
		read_data(buffer, size);
		buffer[size + 1] = '\0';
		printf("%s", buffer);
	}

	return 0;
}