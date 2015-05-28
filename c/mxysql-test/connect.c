#include <my_global.h>
#include <my_sys.h>
#include <mysql.h>

static char *host_name = "127.0.0.1";
static char *user_name = "sqlusr";
static char *password = "q1w2e3!";
static char *db_name = "srvmon";

static MYSQL *conn;
static MYSQL_RES *res;
static MYSQL_ROW row;

int main(int argc, char *argv[]) {
	printf("MySQL connect test\n");

	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, host_name, user_name, password, db_name, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	if (mysql_query(conn, "SELECT * FROM tblServer")) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	res = mysql_use_result(conn);

	printf("Results:\n");

	while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s \n", row[1]);
	}

	mysql_free_result(res);
	mysql_close(conn);

	return 0;
}
