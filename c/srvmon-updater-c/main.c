#include <stdio.h>
#include <stdlib.h>
#include "database.h"

int main(int argc, char* argv[]) {
	printf("SRVMON UPDATER 0.1 - C Edition\n");
	printf("Copyright (C) 2015  Pol Warnimont\n");
	printf("The SRVMON UPDATER comes with ABSOLUTELY NO WARRANTY!\n");

	getServersFromDB();

	printList();

	/*addToList(1,"tst1","192.168.1.1", true);
	addToList(2,"tst2","192.168.1.2", true);
	addToList(3,"tst3","192.168.1.3", true);
	addToList(4,"tst4","192.168.1.4", true);
	addToList(5,"tst5","192.168.1.5", true);

	printList();

	Server *ptr = NULL;*/


	/*ptr = searchInList(3, NULL);

	if (ptr == NULL) {
		printf("No host with ID = %d found!\n", 3);
	}
	else {
		printf("OK -> %d = %s\n", 3, ptr->hostname);
	}*/

	/*int ret = deleteFromList(3);

	printList();*/

	return(EXIT_SUCCESS);
}
