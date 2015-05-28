#ifndef DATABASE_H_
#define DATABASE_H_

struct server {
	int hostid;
	char hostname[32];
	char ipaddress[15];
	struct server *next;
};

void testList();

#endif
