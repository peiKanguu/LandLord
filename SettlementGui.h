#pragma once
#include"Button.h"

class SettlementGUI {
public:
    SettlementGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button continueButton; // 继续游戏按钮
    Button exitButton;     // 退出游戏按钮
    Button returnButton;   // 返回大厅按钮
    Button settingButton;
};