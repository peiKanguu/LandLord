#ifndef CARD_H
#define CARD_H
// 卡牌类，表示一张扑克牌
/*需要表示的信息：
    1.点数
    2.花色
    3.所属者
    4.正反面
    5.位置
    6.是否被选中（弹起）*/

class Card {
public:
    // 花色类型
    enum CardSuit {
        Diamond,
        Club,
        Heart,
        Spade
    };

    // 点数类型
    enum CardValue {
        Card_3,
        Card_4,
        Card_5,
        Card_6,
        Card_7,
        Card_8,
        Card_9,
        Card_10,
        Card_J,
        Card_Q,
        Card_K,
        Card_A,
        Card_2,
        Card_SJ, //小王
        Card_BJ, //大王
    };

    // 构造函数
    // 参数：value（卡牌值），suit（花色）
    Card(CardValue value, CardSuit suit);
    // 获取卡牌值
    int getValue() const;
    // 获取卡牌花色
    int getSuit() const;
    // 改变卡牌位置
    void setPosition(int x, int y);
    // 改变卡牌正反面
    void setFrontSide(bool flag);
    // 改变卡牌选中状态
    void setSelected(bool flag);
    // 改变卡牌所属玩家
    //void setPlayer(Player& owner);
    // 等号运算重载
    bool operator==(const Card& other) const;

private:
    CardValue value;  // 卡牌值
    CardSuit suit;    // 卡牌花色
    int x, y;         // 卡牌位置
    bool isfront;     // 是否正面 1:正 0：反
    bool isselected;  // 是否被选中 1：选中
    //Player& owner;     // 所属玩家
};

#endif