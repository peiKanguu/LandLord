#pragma once
#include"Button.h"

class SettlementGUI {
public:
    SettlementGUI();
    void show(); // ���ƽ��棨�ο�ԭ��ͼ��

private:
    Button continueButton; // ������Ϸ��ť
    Button exitButton;     // �˳���Ϸ��ť
    Button returnButton;   // ���ش�����ť
    Button settingButton;
};