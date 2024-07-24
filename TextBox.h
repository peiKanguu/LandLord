#pragma once
#include <string>
#include <easyx.h>

class TextBox {
public:
    TextBox(int x, int y, int width, int height);
    ~TextBox();

    void draw() const;
    void handleInput();
    std::string getText() const;

private:
    int x, y; // 输入框的左上角坐标
    int width, height; // 输入框的宽度和高度
    std::string text; // 输入框中的文本
    bool isActive; // 输入框是否处于激活状态，激活了才能输入信息
    void drawBorder() const; //绘制边框
};