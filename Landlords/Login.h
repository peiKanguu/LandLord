#pragma once
#include<string>

// 登录类，处理用户登录逻辑
class Login {
public:
    // 验证用户登录
    // 参数：username（用户名），password（密码）
    // 返回值：登录是否成功
    static bool authenticate(const std::string& username, const std::string& password);
};