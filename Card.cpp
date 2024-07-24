#include "Card.h"

// 构造函数
Card::Card(CardValue value, CardSuit suit)
	: value(value), suit(suit), x(0), y(0), isfront(true), isselected(false) {} // 使用初始化列表初始化所有成员变量

// card类的==重载
bool Card::operator==(const Card& other) const
{
	return (value == other.value) && (suit == other.suit);
}

// 获取点数
int Card::getValue() const
{
	return this->value;
}

// 获取花色
int Card::getSuit() const
{
	return this->suit;
}

// 设置卡牌位置
void Card::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

// 设置正反面
void Card::setFrontSide(bool flag)
{
	this->isfront = flag;
}

// 设置选中状态
void Card::setSelected(bool flag)
{
	this->isselected = flag;
}

//// 设置所属玩家
//void Card::setPlayer(Player& player)
//{
//	this->owner = player;
//}
