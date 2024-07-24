#pragma once
#include"Button.h"

class PokerTableGUI {
public:
    PokerTableGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button ChatButton;
    Button exitButton;
    Button settingButton;
    Button rentrunButton;
};