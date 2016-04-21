#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	int sockfd = 0;
	int n = 0;
	char recvBuff[1024];
	struct sockaddr_in serv_addr;

	if (argc != 2) {
		fprintf(stderr, "\nUsage: %s <ip of server>\n", argv[0]);
		exit(1);
	}

	memset(recvBuff, '0', sizeof(recvBuff));

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf(stderr, "\nError: Could not create socket!\n");
		exit(1);
	}

	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000);

	if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
		fprintf(stderr, "\nError: inet_pton() error occured!\n");
		exit(1);
	}

	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "\nError: connect() has failed!\n");
		exit(1);
	}

	while ((n = read(sockfd, recvBuff, sizeof(recvBuff) -1)) > 0) {
		recvBuff[n] = 0;

		if (fputs(recvBuff, stdout) == EOF) {
			fprintf(stderr, "\nError: fputs() error occured!\n");
		}
	}

	if (n < 0) {
		fprintf(stderr, "\nError: read error!\n");
	}

	exit(0);
}
