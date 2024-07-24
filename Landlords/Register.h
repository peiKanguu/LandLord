#pragma once
#include<string>
#include "SQL.h"

// 注册类，处理用户注册逻辑
class Register {
public:
    // 注册新用户
    // 参数：username（用户名），password（密码）
    // 返回值：注册是否成功
    static bool addUser(const std::string& account, const std::string& username, const std::string& password, MYSQL* con);
};
