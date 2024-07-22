#pragma once
#include"Button.h"

class LobbyGUI {
public:
    LobbyGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button confirmButton;
    Button exitButton;
    Button settingButton;
    Button matchButton;
    Button AIMatchButton; // 人机
    Button accountButton;
    Button rentrunButton;
};