#pragma once
#include"Button.h"

class AccountGUI {
public:
    AccountGUI();
    void show(); // ���ƽ��棨�ο�ԭ��ͼ��

private:
    Button setNickname; // �޸��ǳư�ť
    Button setGender; // �޸��Ա�
    Button setBirthday; // �޸����հ�ť
    Button exitButton;
    Button returnButton;
};