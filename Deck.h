#include "Card.h"
#include <algorithm>
#include <vector>

// 牌堆类，管理一副扑克牌的操作
class Deck {
public:
    // 构造函数
    Deck();

    // 添加单张扑克牌
    void add(Card& card);
    void add(Deck& cards);

    // 删除扑克牌
    void remove(Card& card);     //删除单张
    void remove(Deck& cards);    //删除多张

    // 排序
    void cardsort();

    // 洗牌
    void shuffle();

    // 发牌
    // 返回值：发出的一张牌
    Card deal();

private:
    std::vector<Card> cardvec; // 卡牌堆
    int currentCardIndex; // 当前发牌位置
};