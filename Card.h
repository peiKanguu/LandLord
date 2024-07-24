#ifndef CARD_H
#define CARD_H
// �����࣬��ʾһ���˿���
/*��Ҫ��ʾ����Ϣ��
    1.����
    2.��ɫ
    3.������
    4.������
    5.λ��
    6.�Ƿ�ѡ�У�����*/

class Card {
public:
    // ��ɫ����
    enum CardSuit {
        Diamond,
        Club,
        Heart,
        Spade
    };

    // ��������
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
        Card_SJ, //С��
        Card_BJ, //����
    };

    // ���캯��
    // ������value������ֵ����suit����ɫ��
    Card(CardValue value, CardSuit suit);
    // ��ȡ����ֵ
    int getValue() const;
    // ��ȡ���ƻ�ɫ
    int getSuit() const;
    // �ı俨��λ��
    void setPosition(int x, int y);
    // �ı俨��������
    void setFrontSide(bool flag);
    // �ı俨��ѡ��״̬
    void setSelected(bool flag);
    // �ı俨���������
    //void setPlayer(Player& owner);
    // �Ⱥ���������
    bool operator==(const Card& other) const;

private:
    CardValue value;  // ����ֵ
    CardSuit suit;    // ���ƻ�ɫ
    int x, y;         // ����λ��
    bool isfront;     // �Ƿ����� 1:�� 0����
    bool isselected;  // �Ƿ�ѡ�� 1��ѡ��
    //Player& owner;     // �������
};

#endif