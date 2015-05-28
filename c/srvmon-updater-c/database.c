#include <stdio.h>
#include <mysql/mysql.h>
#include "database.h"
#include "servers.h"

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

bool connectToDB() {
	printf("Connecting to DB...\n");

	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, dbserver, dbuser, dbpass, dbname, 0, NULL, 0)) {
		fprintf(stderr, "mysql_real_connect() has failed!\n");
		return false;
	}

	printf("Connection established!\n");

	return true;
}

bool closeConnection() {
	mysql_free_result(res);
	mysql_close(conn);

	printf("DB connection closed!\n");
}

bool getServersFromDB() {
	printf("Gettings servers from DB...\n");
	
	connectToDB();

	if (mysql_query(conn, "CALL getServer(-1,false,@err)")) {
		fprintf(stderr, "mysql_query() has failed!\n");
		
		return false;
	}

	res = mysql_use_result(conn);

	while ((row = mysql_fetch_row(res)) != NULL) {
		//addToList(atoi(row[0]),row[1],row[2], true);
	}

	closeConnection();

	return true;
}
