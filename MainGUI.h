#pragma once
#include"Button.h"

class MainGUI {
public:
    MainGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button loginButton;
    Button registerButton;
    Button exitButton;
    Button devOptionsButton;
};