#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	int socket_desc;
	struct sockaddr_in server;
	char *message;
	char server_reply[2000];

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_desc == -1) {
		fprintf(stderr, "Unable to create socket!\n");
		exit(1);
	}

	server.sin_addr.s_addr = inet_addr("176.22.242.89");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	
}
