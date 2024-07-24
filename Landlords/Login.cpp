#include "Login.h"

bool Login::authenticate(const std::string& account, const std::string& password, MYSQL* con)
{
    char* passwd;
    char sql[1024];

    sprintf_s(sql, sizeof(sql), "select Password from player where account = %s", account.c_str());

    if (mysql_query(con, sql)) { 
        std::cerr << "²éÑ¯ÃÜÂëÊ§°Ü" << std::endl;
        std::cerr << mysql_error(con) << std::endl;
        return false;
    }

    MYSQL_RES* res = mysql_store_result(con);
    MYSQL_ROW row;
    row = mysql_fetch_row(res);
    passwd = row[0];

    if (strcmp(passwd, password.c_str()) == 0) return true;
    else return false;
}