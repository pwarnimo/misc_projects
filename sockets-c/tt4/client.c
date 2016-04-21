#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 4848
#define BUF_SIZE 2000

int main(int argc, char *argv[]) {
	struct sockaddr_in addr;
	struct sockaddr_in cl_addr;
	int sockfd;
	int ret;
	char buffer[BUF_SIZE];
	char *serverAddr;
	struct hostent *server;

	if (argc < 2) {
		fprintf(stderr, "Usage: client <IP Address>\n");
		exit(1);
	}

	serverAddr = argv[1];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
		fprintf(stderr, "ERR: Function socket(..) has failed!\n");
		exit(1);
	}

	printf("> Socket has been created.\n");

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(serverAddr);
	addr.sin_port = PORT;

	ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

	if (ret < 0) {
		fprintf(stderr, "ERR: Could not establish connection with the server!\ņ");
		exit(1);
	}

	printf("> Connected to the server.\n");

	memset(buffer, 0, BUF_SIZE);
	printf("Enter your message(s): ");

	while (fgets(buffer, BUF_SIZE, stdin) != NULL) {
		ret = sendto(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&addr, sizeof(addr));

		if (ret < 0) {
			fprintf(stderr, "ERR: Function sendto(..) has failed!\n");
		}

		ret = recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL);

		if (ret < 0) {
			fprintf(stderr, "ERR: Function recvfrom(..) has failed!\n");
		}
		else {
			printf("> Data received: ");
			fputs(buffer, stdout);
			printf("\n");
		}
	}

	return 0;
}
