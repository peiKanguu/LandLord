#pragma once
// 玩家类，管理玩家的操作和状态
#include "Card.h"
#include <vector>
#include <string>

class Player {
public:
    Player(const std::string& name);
    void addCard(const Card& card);
    void addCards(const std::vector<Card>& cards);
    int makeBid(int highestBid); // 叫分
    std::vector<Card> playCards(const std::vector<Card>& lastPlayedCards); // 出牌
    bool hasWon() const; // 判断是否获胜
    const std::string& getName() const;
    void resetHand(); // 重置手牌

private:
    std::string name;
    std::vector<Card> hand;
    bool won;

    bool isValidPlay(const std::vector<Card>& playedCards, const std::vector<Card>& lastPlayedCards);
};
