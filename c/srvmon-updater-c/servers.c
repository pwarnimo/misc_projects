#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servers.h"

Server *head = NULL;
Server *curr = NULL;

Server* createList(int hostid, char hostname[32], char ipaddress[15]) {
	printf("Creating root node.\n");

	Server *ptr = (Server*)malloc(sizeof(Server));

	if (ptr == NULL) {
		fprintf(stderr, "createList() has failed!\n");

		return NULL;
	}

	ptr->hostid = hostid;
	strncpy(ptr->hostname, hostname, sizeof(ptr->hostname));
	strncpy(ptr->ipaddress, ipaddress, sizeof(ptr->ipaddress));

	head = curr = ptr;

	return ptr;
}

Server* addToList(int hostid, char hostname[32], char ipaddress[15], bool addToEnd) {
	if (head == NULL) {
		return createList(hostid, hostname, ipaddress);
	}

	Server *ptr = (Server*)malloc(sizeof(Server));

	if (ptr == NULL) {
		fprintf(stderr, "addToList() has failed!\n");	
	}

	ptr->hostid = hostid;
	strncpy(ptr->hostname, hostname, sizeof(ptr->hostname));
	strncpy(ptr->ipaddress, ipaddress, sizeof(ptr->ipaddress));
	ptr->next = NULL;

	if (addToEnd) {
		printf("Adding node to end of list.\n");
		curr->next = ptr;
		curr = ptr;
	}
	else {
		printf("Adding node.\n");
		ptr->next = head;
		head = ptr;
	}

	return ptr;
}

Server* searchInList(int hostid, Server **prev) {
	Server *ptr = head;
	Server *tmp = NULL;
	bool found = false;

	printf("Searching for host with the ID %d...\n", hostid);

	while (ptr != NULL) {
		if (ptr->hostid == hostid) {
			found = true;
			break;
		}
		else {
			ptr = ptr->next;
		}
	}

	if (found) {
		if (prev) {
			*prev = tmp;
		}
		
		return ptr;
	}
}

int deleteFromList(int hostid) {
	Server *prev = NULL;
	Server *del = NULL;

	printf("Deleting server with ID = %d", hostid);

	del = searchInList(hostid, &prev);
	
	if (del == NULL) {
		return -1;
	}
	else {
		if (prev != NULL) {
			prev->next = del->next;
		}

		if (del == curr) {
			curr = prev;
		} 
		else if (del == head) {
			head = del->next;
		}
	}

	free(del);
	del = NULL;

	return 0;
}

void printList(void) {
	Server *ptr = head;

	while (ptr != NULL) {
		printf("ID = %d -> %s %s\n", ptr->hostid, ptr->hostname, ptr->ipaddress);
		ptr = ptr->next;
	}

	return;
}
