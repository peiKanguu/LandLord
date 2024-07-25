#ifndef SETTINGGUI_H
#define SETTINGGUI_H

#include "Button.h"

#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include <windows.h>
#include <vector>
#include <fstream>
#include <sstream>

class SettingGUI {
public:
    SettingGUI(std::function<void()> returnCallback)
        : bgmOn(true), sfxOn(true), bgmVolume(50), sfxVolume(50), draggingBGM(false), draggingSFX(false),
        exitButton(1185, 47, 64, 64, L"X", nullptr, 20, L"Arial", BLACK, LIGHTGRAY, DARKGRAY, [this]() { exitButtonClick(); }),
        returnButton(31, 47, 64, 64, L"<", nullptr, 20, L"Arial", BLACK, LIGHTGRAY, DARKGRAY, [this]() { returnToPrevious(); }),
        bgmFilePath(L"C:\\CODE\\LandLords\\Landlords\\background.mp3"),
        returnCallback(returnCallback) {

        // Load volume settings from file
        loadVolumeSettings();
    }

    void show() {
        cleardevice();
        COLORREF backgroundLightBlue = RGB(157, 174, 245);
        setbkcolor(backgroundLightBlue);
        cleardevice();

        // 中心白板
        setfillcolor(WHITE);
        solidrectangle(261, 135, 1019, 501);

        settextcolor(BLACK);
        setbkmode(OPAQUE); // 样式为不透明
        setbkcolor(WHITE); // 填充颜色为白色
        settextstyle(28, 0, _T("PingFang SC"));

        // 背景音乐文本和控件
        outtextxy(328, 172, _T("背景音乐"));
        drawToggleSwitch(500, 172, bgmOn);
        drawSlider(328, 220, bgmVolume);

        // 游戏音效文本和控件
        outtextxy(328, 356, _T("游戏音效"));
        drawToggleSwitch(500, 356, sfxOn);
        drawSlider(328, 404, sfxVolume);

        exitButton.draw();
        returnButton.draw();
    }

    void handleMouseClick(int mouseX, int mouseY) {
        if (mouseX >= 500 && mouseX <= 641 && mouseY >= 172 && mouseY <= 208) {
            bgmOn = !bgmOn;
            toggleBGM();
        }
        else if (mouseX >= 500 && mouseX <= 641 && mouseY >= 356 && mouseY <= 392) {
            sfxOn = !sfxOn;
            // toggleSFX();
        }
        else if (mouseX >= 328 && mouseX <= 953 && mouseY >= 220 && mouseY <= 240) {
            draggingBGM = true;
            bgmVolume = (mouseX - 328) / 6.25;
            setBGMVolume(bgmVolume);
        }
        else if (mouseX >= 328 && mouseX <= 953 && mouseY >= 404 && mouseY <= 424) {
            draggingSFX = true;
            sfxVolume = (mouseX - 328) / 6.25;
            // setSFXVolume(sfxVolume);
        }

        if (exitButton.isClicked(mouseX, mouseY)) {
            exitButton.click();
        }

        if (returnButton.isClicked(mouseX, mouseY)) {
            returnButton.click();
        }

        show();
    }

    void handleMouseMove(int mouseX, int mouseY) {
        if (draggingBGM && mouseX >= 328 && mouseX <= 953 && mouseY >= 220 && mouseY <= 240) {
            bgmVolume = (mouseX - 328) / 6.25;
            setBGMVolume(bgmVolume);
            show();
        }
        if (draggingSFX && mouseX >= 328 && mouseX <= 953 && mouseY >= 404 && mouseY <= 424) {
            sfxVolume = (mouseX - 328) / 6.25;
            // setSFXVolume(sfxVolume);
            show();
        }
    }

    void handleMouseRelease(int mouseX, int mouseY) {
        draggingBGM = false;
        draggingSFX = false;
    }

private:
    bool bgmOn;
    bool sfxOn;
    int bgmVolume;
    int sfxVolume;
    bool draggingBGM;
    bool draggingSFX;

    std::wstring bgmFilePath;
    // std::vector<std::wstring> sfxFiles;

    Button exitButton;
    Button returnButton;
    std::function<void()> returnCallback; // 回调函数，用于返回上一个界面

    void drawToggleSwitch(int x, int y, bool isOn) {
        COLORREF greenColor = RGB(0, 226, 102);
        COLORREF lightGrayColor = RGB(232, 232, 232);

        int radius = 14; // 半圆的半径
        int rectWidth = 113; // 矩形的宽度

        // 绘制左侧半圆
        setfillcolor(isOn ? greenColor : lightGrayColor);
        solidcircle(x + radius, y + radius, radius);

        // 绘制右侧半圆
        solidcircle(x + rectWidth - radius, y + radius, radius);

        // 绘制中间的矩形
        solidrectangle(x + radius, y, x + rectWidth - radius, y + 2 * radius);

        // 绘制圆形的开关
        setfillcolor(WHITE);
        solidcircle(isOn ? (x + rectWidth - radius - 2) : (x + radius + 2), y + radius, radius - 2);
    }

    void drawSlider(int x, int y, int value) {
        COLORREF lightGreenColor = RGB(162, 239, 77);
        COLORREF lightGrayColor = RGB(232, 232, 232);

        setfillcolor(lightGrayColor);
        solidrectangle(x, y, x + 625, y + 20);
        setfillcolor(lightGreenColor);
        solidrectangle(x, y, x + static_cast<int>(value * 6.25), y + 20);
        setfillcolor(BLACK);
        solidcircle(x + static_cast<int>(value * 6.25), y + 10, 15);
    }

    void toggleBGM() {
        if (bgmOn) {
            std::wstring command = L"open \"" + bgmFilePath + L"\" type mpegvideo alias bgm";
            mciSendString(command.c_str(), nullptr, 0, nullptr);
            mciSendString(L"play bgm repeat", nullptr, 0, nullptr);
        }
        else {
            mciSendString(L"stop bgm", nullptr, 0, nullptr);
            mciSendString(L"close bgm", nullptr, 0, nullptr);
        }
    }

    void setBGMVolume(int volume) {
        // Set BGM volume
        std::wstring command = L"setaudio bgm volume to " + std::to_wstring(volume * 10);
        mciSendString(command.c_str(), nullptr, 0, nullptr);
    }

    // void toggleSFX() {
    //     if (sfxOn) {
    //         // Play sound effects
    //         for (const auto& sfxFile : sfxFiles) {
    //             mciSendString(L"open \"" + sfxFile + L"\" type mpegvideo alias sfx", nullptr, 0, nullptr);
    //             mciSendString(L"play sfx", nullptr, 0, nullptr);
    //         }
    //     }
    //     else {
    //         // Stop sound effects
    //         mciSendString(L"stop sfx", nullptr, 0, nullptr);
    //         mciSendString(L"close sfx", nullptr, 0, nullptr);
    //     }
    // }

    // void setSFXVolume(int volume) {
    //     // Set SFX volume
    //     for (const auto& sfxFile : sfxFiles) {
    //         std::wstring command = L"setaudio sfx volume to " + std::to_wstring(volume * 10);
    //         mciSendString(command.c_str(), nullptr, 0, nullptr);
    //     }
    // }

    void saveVolumeSettings() {
        std::wofstream outFile(L"volume_settings.txt");
        outFile << bgmVolume << L'\n' << sfxVolume;
    }

    void loadVolumeSettings() {
        std::wifstream inFile(L"volume_settings.txt");
        if (inFile) {
            inFile >> bgmVolume >> sfxVolume;
        }
    }

    void returnToPrevious() {
        // Save settings and return to previous screen
        saveVolumeSettings();
        returnCallback(); // Call the return callback function
    }

    void exitButtonClick() {
        saveVolumeSettings();
        closegraph();
        exit(0);
    }
};

#endif // SETTINGGUI_H