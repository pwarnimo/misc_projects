#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int socket_desc;
	struct sockaddr_in server;

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_desc == -1) {
		fprintf(stderr, "Could no create socket!\n");
		exit(1);
	}

	server.sin_addr.s_addr = inet_addr("176.22.242.89");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
		puts("connect error");
		exit(1);
	}

	puts("connected");

	exit(0);
}
