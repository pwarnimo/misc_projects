#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <libconfig.h>
#include "database.h"

int main(int argc, char* argv[]) {
	struct server *curr;
	struct server *root;
	int i;

	root = NULL;

	for (i = 1; i <= 10; i++) {
		curr = (struct server *) malloc(sizeof(struct server));

		curr->hostid = i;
		strncpy(curr->ipaddress, "192.168.1.111", sizeof(curr->ipaddress));

		char buf[32];
		
		sprintf(buf, "Test%d", i);

		strncpy(curr->hostname, buf, sizeof(curr->hostname));
		//strcpy(curr->ipaddress, "test");
		//curr->ipaddress = strcpy"ttt";
		//curr->hostname = "tststs";
		curr->next = root;
		root = curr;
	}

	curr = root;

	while(curr) {
		printf("%d - %s:%s\n", curr->hostid, curr->ipaddress, curr->hostname);
		curr = curr->next;
	}

	/*config_t cfg, *cf;

	cf = &cfg;
	config_init(cf);

	if (!config_read_file(cf, "config.cfg")) {
		fprintf(stderr, "%s:%d - %s\n", config_error_file(cf), config_error_line(cf), config_error_text(cf));
		config_destroy(cf);
		return(EXIT_FAILURE);
	}
	
	connectToDB();

	config_destroy(cf);*/

	testList();

	/*pid_t process_id = 0;
	pid_t sid = 0;

	openlog("srvmon-updater", 0, LOG_USER);

	process_id = fork();

	if (process_id < 0) {
		fprintf(stderr, "fork() failed!\n");
		exit(1);
	}

	if (process_id > 0) {
		printf("Starting SRVMON UPDATER DAEMON\n");
		printf("Copyright (C) 2015  Pol Warnimont\n");
		printf("The SRVMON UPDATER DAEMON comes with ABSOLUTELY NO WARRANTY!\n\n");
		printf("Process ID of child = %d\n", process_id);
		syslog(LOG_INFO, "%s", "Daemon has started!");
		exit(0);
	}

	umask(0);
	sid = setsid();

	if (sid < 0) {
		exit(1);
	}

	chdir("/");

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while (1) {
		syslog(LOG_INFO, "%s", "Executing routines...");
		sleep(20);
	}*/

	return(EXIT_SUCCESS);
}
