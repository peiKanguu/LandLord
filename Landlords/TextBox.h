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
    int x, y; // ���������Ͻ�����
    int width, height; // �����Ŀ�Ⱥ͸߶�
    std::string text; // ������е��ı�
    bool isActive; // ������Ƿ��ڼ���״̬�������˲���������Ϣ
    void drawBorder() const; //���Ʊ߿�
};