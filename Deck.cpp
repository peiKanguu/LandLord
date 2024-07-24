#include "Deck.h"

//���캯��
Deck::Deck() : currentCardIndex(0) {}

// ��ӵ��ſ���
void Deck::add(Card& card) 
{
    cardvec.push_back(card);
}

// ��Ӷ��ſ���
void Deck::add(Deck& cards)
{
    cardvec.insert(cardvec.end(), cards.cardvec.begin(), cards.cardvec.end());
}

// ɾ�����ſ���
void Deck::remove(Card& card)
{
    auto it = std::find(cardvec.begin(), cardvec.end(), card);
    if (it != cardvec.end()) {
        cardvec.erase(it);
    }
}

// ɾ�����ſ���
void Deck::remove(Deck& cards)
{
    for (auto& it : cards.cardvec) {
        auto exist = std::find(cardvec.begin(), cardvec.end(), it);
        if (exist != cardvec.end()) {
            cardvec.erase(exist);
        }
    }
}

// ����
void Deck::cardsort() {
    std::sort(cardvec.begin(), cardvec.end(), [](const Card& a, const Card& b) {
        return a.getValue() < b.getValue();
        });
}