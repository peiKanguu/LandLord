#pragma once

// 牌堆类，管理一副扑克牌的操作
class Deck {
public:
    // 构造函数
    Deck();

    // 洗牌
    void shuffle();

    // 发牌
    // 返回值：发出的一张牌
    Card deal();

private:
    std::vector<Card> cards; // 卡牌堆
    int currentCardIndex; // 当前发牌位置
};