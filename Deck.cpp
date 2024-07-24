#include "Deck.h"

//构造函数
Deck::Deck() : currentCardIndex(0) {}

// 添加单张卡牌
void Deck::add(Card& card) 
{
    cardvec.push_back(card);
}

// 添加多张卡牌
void Deck::add(Deck& cards)
{
    cardvec.insert(cardvec.end(), cards.cardvec.begin(), cards.cardvec.end());
}

// 删除单张卡牌
void Deck::remove(Card& card)
{
    auto it = std::find(cardvec.begin(), cardvec.end(), card);
    if (it != cardvec.end()) {
        cardvec.erase(it);
    }
}

// 删除多张卡牌
void Deck::remove(Deck& cards)
{
    for (auto& it : cards.cardvec) {
        auto exist = std::find(cardvec.begin(), cardvec.end(), it);
        if (exist != cardvec.end()) {
            cardvec.erase(exist);
        }
    }
}

// 排序
void Deck::cardsort() {
    std::sort(cardvec.begin(), cardvec.end(), [](const Card& a, const Card& b) {
        return a.getValue() < b.getValue();
        });
}