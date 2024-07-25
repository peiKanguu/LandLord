#pragma once

#include <functional>
#include <graphics.h>
#include <string>

class Button {
public:
    Button(int x, int y, int width, int height, const std::wstring& text, IMAGE* img = nullptr, int fontSize = 20, const std::wstring& font = L"Arial", COLORREF fontColor = BLACK, COLORREF fillColor = LIGHTGRAY, COLORREF hoverColor = DARKGRAY, std::function<void()> onClick = nullptr)
        : x(x), y(y), width(width), height(height), text(text), image(img), fontSize(fontSize), font(font), fontColor(fontColor), fillColor(fillColor), hoverColor(hoverColor), onClick(onClick) {}

    void draw(bool isHovered = false) const {
        COLORREF currentFillColor = isHovered ? hoverColor : fillColor;
        if (image) {
            putimage(x, y, width, height, image, 0, 0);
        }
        else {
            setfillcolor(currentFillColor);
            solidrectangle(x, y, x + width, y + height);
        }
        setbkmode(TRANSPARENT);
        settextcolor(fontColor);
        settextstyle(fontSize, 0, font.c_str());
        outtextxy(x + (width / 2 - textwidth(text.c_str()) / 2), y + (height / 2 - textheight(text.c_str()) / 2), text.c_str());
    }

    bool isClicked(int mouseX, int mouseY) const {
        return mouseX >= x && mouseY >= y && mouseX <= x + width && mouseY <= y + height;
    }

    bool isHovered(int mouseX, int mouseY) const {
        return mouseX >= x && mouseY >= y && mouseX <= x + width && mouseY <= y + height;
    }

    void click() const {
        if (onClick) {
            onClick();
        }
    }

private:
    int x, y;
    int width, height;
    std::wstring text;
    IMAGE* image;
    int fontSize;
    std::wstring font;
    COLORREF fontColor;
    COLORREF fillColor;
    COLORREF hoverColor;
    std::function<void()> onClick; // 按钮的点击事件回调函数
};