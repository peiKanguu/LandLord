#pragma once

// �ƶ��࣬����һ���˿��ƵĲ���
class Deck {
public:
    // ���캯��
    Deck();

    // ϴ��
    void shuffle();

    // ����
    // ����ֵ��������һ����
    Card deal();

private:
    std::vector<Card> cards; // ���ƶ�
    int currentCardIndex; // ��ǰ����λ��
};