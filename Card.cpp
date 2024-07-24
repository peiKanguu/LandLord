#include "Card.h"

// ���캯��
Card::Card(CardValue value, CardSuit suit)
	: value(value), suit(suit), x(0), y(0), isfront(true), isselected(false) {} // ʹ�ó�ʼ���б��ʼ�����г�Ա����

// card���==����
bool Card::operator==(const Card& other) const
{
	return (value == other.value) && (suit == other.suit);
}

// ��ȡ����
int Card::getValue() const
{
	return this->value;
}

// ��ȡ��ɫ
int Card::getSuit() const
{
	return this->suit;
}

// ���ÿ���λ��
void Card::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

// ����������
void Card::setFrontSide(bool flag)
{
	this->isfront = flag;
}

// ����ѡ��״̬
void Card::setSelected(bool flag)
{
	this->isselected = flag;
}

//// �����������
//void Card::setPlayer(Player& player)
//{
//	this->owner = player;
//}
