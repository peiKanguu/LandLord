#include "SQL.h"

MYSQL* SQL::connectSQL()
{
	MYSQL* con = mysql_init(NULL);
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* password = "ckr73444";
	const char* database_name = "landlords";
	unsigned int port = 3306;

	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	
	if (!mysql_real_connect(con, host, user, password, database_name, port, NULL, 0)) 
	{ 
		std::cout << "数据库连接错误!" << std::endl;
	}

	return con;
}

