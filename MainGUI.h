#pragma once
#include"Button.h"

class MainGUI {
public:
    MainGUI();
    void show(); // ���ƽ��棨�ο�ԭ��ͼ��

private:
    Button loginButton;
    Button registerButton;
    Button exitButton;
    Button devOptionsButton;
};