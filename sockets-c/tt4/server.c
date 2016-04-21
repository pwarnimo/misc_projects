#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>

#define PORT 4848
#define BUF_SIZE 2000
#define CLADDR_LEN 100

int main(int argc, char *argv[]) {
	struct sockaddr_in addr;
	struct sockaddr_in cl_addr;
	int sockfd;
	int len;
	int ret;
	int newsockfd;
	char buffer[BUF_SIZE];
	char clientAddr[CLADDR_LEN];
	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
		fprintf(stderr, "ERR: Function socket(..) has failed!\n");
		exit(1);
	}

	printf("> Socket has been created.\n");

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = PORT;

	ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

	if (ret < 0) {
		fprintf(stderr, "ERR: Function bind(..) has failed!\n");
		exit(1);
	}

	printf("> Binding done.\n");
	printf("> Waiting for incoming connections...\n");

	listen(sockfd, 5);

	for (;;) {
		len = sizeof(cl_addr);
		newsockfd = accept(sockfd, (struct sockaddr *)&cl_addr, &len);

		if (newsockfd < 0) {
			fprintf(stderr, "ERR: Function accept(..) has failed!\n");
			exit(1);
		}

		printf("> Connection has been accepted.\n");

		inet_ntop(AF_INET, &(cl_addr.sin_addr), clientAddr, CLADDR_LEN);

		if ((childpid == fork()) == 0) {
			close(sockfd);

			for (;;) {
				memset(buffer, 0, BUF_SIZE);
				ret = recvfrom(newsockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&cl_addr, &len);

				if (ret < 0) {
					fprintf(stderr, "ERR: Function recvfrom(..) has failed!\n");
					exit(1);
				}

				printf("> Received data from %s: %s\n", clientAddr, buffer);

				ret = sendto(newsockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&cl_addr, len);

				if (ret < 0) {
					fprintf(stderr, "ERR: Function sendto(..) has failed!\n");
					exit(1);
				}

				printf("> Data has been sent to %s: %s\n", clientAddr, buffer);
			}
		}

		close(newsockfd);
	}
}
