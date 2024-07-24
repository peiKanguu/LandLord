#pragma once
#include"Button.h"

class AccountGUI {
public:
    AccountGUI(std::function<void()> returnCallback)
        : exitButton(1185, 47, 64, 64, L"X", nullptr, 20, L"Arial", BLACK, LIGHTGRAY, DARKGRAY, [this]() { exitButtonClick(); }),
        returnButton(31, 47, 64, 64, L"<", nullptr, 20, L"Arial", BLACK, LIGHTGRAY, DARKGRAY, [this]() { returnToPrevious(); }),
        confirmButton(470, 456, 337, 30, L"ȷ��", nullptr, 20, L"Arial", BLACK, LIGHTGRAY, DARKGRAY, [this]() { confirmButtonClick(); }),
        returnCallback(returnCallback) {
    }

    void show() {
        cleardevice();
        COLORREF backgroundLightYellow = RGB(255, 255, 204);
        setbkcolor(backgroundLightYellow);
        cleardevice();

        // ���İ�
        COLORREF lightOrange = RGB(255, 204, 153);
        setfillcolor(lightOrange);
        solidrectangle(428, 142, 852, 521); // ͼƬ�����İװ��λ�úʹ�С����

        settextcolor(BLACK);
        setbkmode(OPAQUE); // ��ʽΪ��͸��
        setbkcolor(lightOrange); // �����ɫΪǳ��ɫ
        settextstyle(18, 0, _T("Arial"));

        // �ǳ�����
        outtextxy(470, 185, _T("�����ǳƣ�"));
		// ��Ҫ���������ؼ�


        // �Ա�����
        setbkcolor(lightOrange);
        outtextxy(470, 273, _T("�����Ա�"));
        // ��Ҫ����������ؼ�

        // ��������
        outtextxy(470, 361, _T("�������գ�"));
        // ��Ҫ����������ؼ�

        exitButton.draw();
        returnButton.draw();
		confirmButton.draw();
    }

    void handleMouseClick(int mouseX, int mouseY) {
        if (exitButton.isClicked(mouseX, mouseY)) {
            exitButton.click();
        }

        if (returnButton.isClicked(mouseX, mouseY)) {
            returnButton.click();
        }

        show();
    }

private:
    Button exitButton;
    Button returnButton;
	Button confirmButton;
    std::function<void()> returnCallback; // �ص����������ڷ�����һ������

    void returnToPrevious() {
        // Return to the previous screen
        returnCallback(); // Call the return callback function
    }

	void confirmButtonClick() {
		// Save the account settings
		// Save the nickname
	}

    void exitButtonClick() {
        closegraph();
        exit(0);
    }
};
