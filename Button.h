#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <functional>
#include <easyx.h>

class Button {
public:
    // 使用颜色背景的构造函数
    Button(int x, int y, int width, int height, const std::string& label, std::function<void()> onClick);

    // 使用图片背景的构造函数
    Button(int x, int y, int width, int height, const std::string& label, const std::string& imagePath, std::function<void()> onClick);

    ~Button();

    void draw() const;
    bool isClicked(int mouseX, int mouseY) const;
    void click() const;

private:
    int x, y; // 按钮的左上角坐标
    int width, height; // 按钮的宽度和高度
    std::string label; // 按钮的标签
    std::function<void()> onClick; // 按钮的点击事件回调函数
    IMAGE* backgroundImage; // 按钮的背景图片
};

#endif // BUTTON_H