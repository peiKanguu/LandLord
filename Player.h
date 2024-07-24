#pragma once
// ����࣬������ҵĲ�����״̬
#include "Card.h"
#include <vector>
#include <string>

class Player {
public:
    Player(const std::string& name);
    void addCard(const Card& card);
    void addCards(const std::vector<Card>& cards);
    int makeBid(int highestBid); // �з�
    std::vector<Card> playCards(const std::vector<Card>& lastPlayedCards); // ����
    bool hasWon() const; // �ж��Ƿ��ʤ
    const std::string& getName() const;
    void resetHand(); // ��������

private:
    std::string name;
    std::vector<Card> hand;
    bool won;

    bool isValidPlay(const std::vector<Card>& playedCards, const std::vector<Card>& lastPlayedCards);
};
