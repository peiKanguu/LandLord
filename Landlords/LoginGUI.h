#pragma once
#include"Button.h"

class LoginGUI {
public:
    LoginGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button confirmButton; 
    Button exitButton;
    Button renturnButton;
};

void LoginGUI::show()
{

}