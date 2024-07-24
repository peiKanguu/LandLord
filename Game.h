#pragma once

// ��Ϸ�࣬����������Ϸ����Ҫ�߼�
#include "Deck.h"
#include "Player.h"
#include"CardCounter.h"
#include <vector>

class Game {
public:
    Game();
    void startGame();   // ��ʼ��Ϸ
    void dealCards();   // ����
    void bidForLandlord(); // �е���
    void determineWinner(); // �ж�ʤ��

private:
    Deck deck;
    std::vector<Player> players; // ����б�
    std::vector<Card> bottomCards; // ����
    int landlordIndex; // �������������
    int currentPlayerIndex; // ��ǰ�������
    int baseScore; // �׷�
    int multiplier; // ����
    std::vector<Card> lastPlayedCards; // ��¼��һ�γ�����
    CardCounter cardCounter; // ������

    bool isValidPlay(const std::vector<Card>& playedCards, const std::vector<Card>& lastPlayedCards); // �������Ƿ���Ч
    void showBottomCards();
    void resetGame();

    // ��Ϸѭ��
    // ������Ϸ����Ҫ���̣�ֱ������һ�ʤ
    void gameLoop();

    // ��ҳ��� 
    // ������player����ǰ��ң� 
    void playerPlay(Player& player);
};

