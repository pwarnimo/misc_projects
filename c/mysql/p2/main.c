#include <my_global.h>
#include <mysql.h>
#include <string.h>

#define STRING_SIZE 256

int main(int argc, char *argv[]) {
	MYSQL *mysql;
	MYSQL_STMT *stmt;
	MYSQL_BIND param[1], result[1];
	char *sql;

	mysql = mysql_init(NULL);

	if (mysql_real_connect(mysql, "localhost", "sqlusr", "q1w2e3!", "tst1", 0, NULL, 0) == NULL) {
		fprintf(stderr, "Connection to the DB has failed!\n");
		
		exit(1);
	}

	sql = "SELECT dtFirstName FROM tblPerson WHERE dtLastName = ?";

	int param_count;
	short small_data;
	int int_data;
	char str_data[STRING_SIZE];
	char result_data[STRING_SIZE];
	unsigned long str_length;
	unsigned long data_length;
	my_bool is_null;

	stmt = mysql_stmt_init(mysql);

	if (!stmt) {
		fprintf(stderr, "mysql_stmt_init(), out of memory!\n");

		exit(1);
	}

	if (mysql_stmt_prepare(stmt, sql, strlen(sql))) {
		fprintf(stderr, "mysql_stmt_prepare(), INSERT failed!\n");
		fprintf(stderr, "-FATAL- : %s\n", mysql_stmt_error(stmt));

		exit(1);
	}

	memset(param, 0, sizeof(param));
	memset(result, 0, sizeof(result));

	/* STRING PARAM */
	param[0].buffer_type = MYSQL_TYPE_STRING;
	param[0].buffer = (char *)str_data;
	param[0].buffer_length = STRING_SIZE;
	param[0].is_null = 0;
	param[0].length = &str_length;

	result[0].buffer_type = MYSQL_TYPE_VAR_STRING;
	result[0].buffer = result_data;
	result[0].buffer_length = STRING_SIZE;
	result[0].is_null = 0;
	result[0].length = &data_length;

	if (mysql_stmt_bind_param(stmt, param)) {
		fprintf(stderr, "mysql_stmt_bind_param() has failed!\n");
		fprintf(stderr, "-FATAL- : %s\n", mysql_stmt_error(stmt));

		exit(1);
	}

	if (mysql_stmt_bind_result(stmt, result) != 0) {
		fprintf(stderr, "mysql_stmt_bind_result() has failed!\n");
		fprintf(stderr, "-FATAL- : %s\n", mysql_stmt_error(stmt));

		exit(1);
	}

	strncpy(str_data, "Warnimont", STRING_SIZE);
	str_length = strlen(str_data);

	if (mysql_stmt_execute(stmt)) {
		fprintf(stderr, "mysql_stmt_execute() has failed!\n");
		fprintf(stderr, "-FATAL- : %s\n", mysql_stmt_error(stmt));

		exit(1);
	}

	if (mysql_stmt_fetch(stmt) == 0) {
		printf("%s\n", result_data);
	}
	else {
		printf("No results found!\n");
	}

	if (mysql_stmt_close(stmt)) {
		fprintf(stderr, "Failed while closing the statement!\n");
		fprintf(stderr, "-FATAL- : %s\n", mysql_stmt_error(stmt));

		exit(1);
	}

	exit(0);
}
