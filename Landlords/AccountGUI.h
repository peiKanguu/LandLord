#pragma once
#include"Button.h"

class AccountGUI {
public:
    AccountGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button setNickname; // 修改昵称按钮
    Button setGender; // 修改性别
    Button setBirthday; // 修改生日按钮
    Button exitButton;
    Button returnButton;
};