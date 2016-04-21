#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	int socket_desc;
	struct sockaddr_in server;
	char *message;

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_desc == -1) {
		fprintf(stderr, "Could not create socket!\n");
		exit(1);
	}

	server.sin_addr.s_addr = inet_addr("176.22.242.89");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
		fprintf(stderr, "connect() error!\n");
		exit(1);
	}

	printf("Connected!\n");

	message = "GET / HTTP/1-1\r\n\r\n";

	if (send(socket_desc, message, strlen(message), 0) < 0) {
		fprintf(stderr, "send() has failed!\n");
		exit(1);
	}

	printf("send() was successful!\n");

	exit(0);
}
