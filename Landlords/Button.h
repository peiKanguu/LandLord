#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <functional>
#include <easyx.h>

class Button {
public:
    // ʹ����ɫ�����Ĺ��캯��
    Button(int x, int y, int width, int height, const std::string& label, std::function<void()> onClick);

    // ʹ��ͼƬ�����Ĺ��캯��
    Button(int x, int y, int width, int height, const std::string& label, const std::string& imagePath, std::function<void()> onClick);

    ~Button();

    void draw() const;
    bool isClicked(int mouseX, int mouseY) const;
    void click() const;

private:
    int x, y; // ��ť�����Ͻ�����
    int width, height; // ��ť�Ŀ�Ⱥ͸߶�
    std::string label; // ��ť�ı�ǩ
    std::function<void()> onClick; // ��ť�ĵ���¼��ص�����
    IMAGE* backgroundImage; // ��ť�ı���ͼƬ
};

#endif // BUTTON_H