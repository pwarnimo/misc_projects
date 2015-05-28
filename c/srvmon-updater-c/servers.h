#ifndef SERVERS_H_
#define SERVERS_H_

#include <stdbool.h>

typedef struct Server {
	int hostid;
	char hostname[32];
	char ipaddress[32];
	struct Server *next;
} Server;

Server* createList(int hostid, char hostname[32], char ipaddress[15]);
Server* addToList(int hostid, char hostname[32], char ipaddress[15], bool addToEnd);
Server* searchInList(int hostid, Server **prev);

int deleteFromList(int hostid);

void printList(void);

#endif
