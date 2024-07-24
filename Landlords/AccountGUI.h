#pragma once
#include"Button.h"

class AccountGUI {
public:
    AccountGUI(std::function<void()> returnCallback)
        : exitButton(1185, 47, 64, 64, L"X", nullptr, 20, L"Arial", BLACK, LIGHTGRAY, DARKGRAY, [this]() { exitButtonClick(); }),
        returnButton(31, 47, 64, 64, L"<", nullptr, 20, L"Arial", BLACK, LIGHTGRAY, DARKGRAY, [this]() { returnToPrevious(); }),
        confirmButton(470, 456, 337, 30, L"确认", nullptr, 20, L"Arial", BLACK, LIGHTGRAY, DARKGRAY, [this]() { confirmButtonClick(); }),
        returnCallback(returnCallback) {
    }

    void show() {
        cleardevice();
        COLORREF backgroundLightYellow = RGB(255, 255, 204);
        setbkcolor(backgroundLightYellow);
        cleardevice();

        // 中心板
        COLORREF lightOrange = RGB(255, 204, 153);
        setfillcolor(lightOrange);
        solidrectangle(428, 142, 852, 521); // 图片中中心白板的位置和大小调整

        settextcolor(BLACK);
        setbkmode(OPAQUE); // 样式为不透明
        setbkcolor(lightOrange); // 填充颜色为浅橙色
        settextstyle(18, 0, _T("Arial"));

        // 昵称设置
        outtextxy(470, 185, _T("设置昵称："));
		// 需要绘制输入框控件


        // 性别设置
        setbkcolor(lightOrange);
        outtextxy(470, 273, _T("设置性别："));
        // 需要绘制下拉框控件

        // 生日设置
        outtextxy(470, 361, _T("设置生日："));
        // 需要绘制下拉框控件

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
    std::function<void()> returnCallback; // 回调函数，用于返回上一个界面

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
