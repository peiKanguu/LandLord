#include<iostream>
#include "SQL.h"
#include "Login.h"
#include "Register.h"

int main()
{
	MYSQL* con = SQL::connectSQL();
	if (Register::addUser("123456", "����", "123456", con))std::cout << "ע��ɹ�" << std::endl;
	else std::cout << "ע��ʧ��" << std::endl;

	if (Login::authenticate("123456", "123456", con))std::cout << "YES" << std::endl;
	else std::cout << "��¼ʧ��" << std::endl;

	return 0;
}