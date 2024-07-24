#include<iostream>
#include "SQL.h"
#include "Login.h"
#include "Register.h"

int main()
{
	MYSQL* con = SQL::connectSQL();
	if (Register::addUser("123456", "ÕÅÈı", "123456", con))std::cout << "×¢²á³É¹¦" << std::endl;
	else std::cout << "×¢²áÊ§°Ü" << std::endl;

	if (Login::authenticate("123456", "123456", con))std::cout << "YES" << std::endl;
	else std::cout << "µÇÂ¼Ê§°Ü" << std::endl;

	return 0;
}