#pragma once
#include"Button.h"

class PokerTableGUI {
public:
    PokerTableGUI();
    void show(); // ���ƽ��棨�ο�ԭ��ͼ��

private:
    Button ChatButton;
    Button exitButton;
    Button settingButton;
    Button rentrunButton;
};