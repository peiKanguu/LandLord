#pragma once
#include"Button.h"
class SettingGUI {
public:
    SettingGUI();
    void show(); // ���ƽ��棨�ο�ԭ��ͼ��

private:
    Button volumeButton; // ����������ť
    Button soundButton;  // ������Ч��ť
    Button exitButton;
    Button returnButton;
};