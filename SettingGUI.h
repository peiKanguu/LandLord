#pragma once
#include"Button.h"
class SettingGUI {
public:
    SettingGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button volumeButton; // 调节音量按钮
    Button soundButton;  // 交接音效按钮
    Button exitButton;
    Button returnButton;
};