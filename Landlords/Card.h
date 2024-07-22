#pragma once

// �����࣬��ʾһ���˿���
class Card {
public:
    // ���캯��
    // ������value������ֵ����suit����ɫ��
    Card(int value, const std::string& suit);

    // ��ȡ����ֵ
    // ����ֵ������ֵ
    int getValue() const;

    // ��ȡ���ƻ�ɫ
    // ����ֵ�����ƻ�ɫ
    std::string getSuit() const;

    // ��ȡ�����ַ�����ʾ
    // ����ֵ�����Ƶ��ַ�����ʾ
    std::string toString() const;

private:
    int value; // ����ֵ
    std::string suit; // ���ƻ�ɫ
};