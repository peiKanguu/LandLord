#include"Register.h"

bool Register::addUser(const std::string& account, const std::string& username, const std::string& password, MYSQL* con)
{
    char sql[1024];
    sprintf_s(sql, sizeof(sql), "insert into player(Account, Name, Password) values('%s', '%s', '%s')", account.c_str(), username.c_str(), password.c_str());
    if (mysql_query(con, sql)) {
        std::cerr << "ÕË»§ÖØ¸´" << std::endl;
        return false;
    }
    return true;
}