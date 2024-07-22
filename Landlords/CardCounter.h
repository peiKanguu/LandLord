#pragma once
#include<map>
#include<string>
#include"Card.h"

// �������࣬������¼����ʾ�Ѵ������
class CardCounter {
public:
    // ���캯��
    CardCounter();

    // ��¼һ���Ʊ����
    // ������card��������Ŀ��ƣ�
    void cardPlayed(const Card& card);

    // ��ȡ�Ѵ�����Ƶ�����
    // ������card��Ҫ��ѯ�Ŀ��ƣ�
    // ����ֵ���ÿ����Ѵ��������
    int getCardCount(const Card& card) const;

    // ��ʾ�����Ѵ�����Ƽ�������
    void display() const;

private:
    std::map<std::string, int> cardCounts; // ��¼ÿ���Ʊ����������

    // ���ɿ��Ƶ�Ψһ��ʶ��
    // ������card��Ҫ���ɱ�ʶ���Ŀ��ƣ�
    // ����ֵ�����Ƶ�Ψһ��ʶ��
    std::string generateCardKey(const Card& card) const;
};