#ifndef DATABASE_H_
#define DATABASE_H_

#include <stdbool.h>

static const char *dbserver = "127.0.0.1";
static const char *dbuser = "sqlusr";
static const char *dbpass = "q1w2e3!";
static const char *dbname = "srvmon";

bool connectToDB();
bool closeConnection();
bool getServersFromDB();

#endif
