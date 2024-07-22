#pragma once
#include"Button.h"

class RegisterGUI {
public:
    RegisterGUI();
    void show(); // 绘制界面（参考原型图）

private:
     Button confirmButton;
     Button exitButton;
     Button rentrunButton;
};