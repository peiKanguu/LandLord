#include "Card.h"
#include <algorithm>
#include <vector>

// �ƶ��࣬����һ���˿��ƵĲ���
class Deck {
public:
    // ���캯��
    Deck();

    // ��ӵ����˿���
    void add(Card& card);
    void add(Deck& cards);

    // ɾ���˿���
    void remove(Card& card);     //ɾ������
    void remove(Deck& cards);    //ɾ������

    // ����
    void cardsort();

    // ϴ��
    void shuffle();

    // ����
    // ����ֵ��������һ����
    Card deal();

private:
    std::vector<Card> cardvec; // ���ƶ�
    int currentCardIndex; // ��ǰ����λ��
};