#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void *connection_handler(void *);

int main(int argc, char *argv[]) {
	int socket_desc;
	int new_socket;
	int c;
	int *new_sock;
	struct sockaddr_in server;
	struct sockaddr_in client;
	char *message;

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_desc == -1) {
		fprintf(stderr, "ERR: Function socket() has failed!\n");
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
		fprintf(stderr, "ERR: Function bind() has failed!\n");
		exit(1);
	}

	printf("Bind done.\n");

	listen(socket_desc, 3);

	printf("Waiting for incoming connections...\n");

	c = sizeof(struct sockaddr_in);

	while ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c))) {
		printf("Connection accepted.\n");

		message = "Assigning connection handler...\n";
		write(new_socket, message, strlen(message));

		pthread_t sniffer_thread;
		new_sock = malloc(1);
		*new_sock = new_socket;

		if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *)new_sock) <0) {
			fprintf(stderr, "ERR: Function pthread_create() has failed!\n");
			exit(1);
		}

		printf("Handler assigned.\n");
	}

	if (new_socket < 0) {
		fprintf(stderr, "ERR: Function accept() has failed!\n");
		exit(1);
	}
	
	exit(0);
}

void *connection_handler(void *socket_desc) {
	int sock = *(int *)socket_desc;
	int read_size;
	char *message;
	char client_message[2000];

	message = "Connection handler initialized.\n";
	write(sock, message, strlen(message));

	while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
		write(sock, client_message, strlen(client_message));
	}

	if (read_size == 0) {
		printf("Client has disconnected.\n");
		fflush(stdout);
	}
	else if (read_size == -1) {
		fprintf(stderr, "ERR: Function recv() has failed!\n");
		exit(1);
	}

	free(socket_desc);

	return 0;
}
