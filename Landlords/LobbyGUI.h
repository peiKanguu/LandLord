#pragma once
#include"Button.h"

class LobbyGUI {
public:
    LobbyGUI();
    void show(); // ���ƽ��棨�ο�ԭ��ͼ��

private:
    Button confirmButton;
    Button exitButton;
    Button settingButton;
    Button matchButton;
    Button AIMatchButton; // �˻�
    Button accountButton;
    Button rentrunButton;
};