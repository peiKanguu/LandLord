#include "Card.h"
#include "Deck.h"

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<cstdint>
#include<chrono>				//��׼֡�ʿ���
#include<graphics.h>			//����easyx,easyx����Windows.h
#include<time.h>				//����ʱ��ͷ�ļ�
#include<conio.h>				//��������̨���������ͷ�ļ�
#include<mmsystem.h>			//���ֵ�ͷ�ļ�
#pragma comment(lib, "winmm.lib")//���ֵĿ��ļ�
using namespace std;

int main()
{
	std::cout << "�������" << std::endl;
	std::cout << "This is a test" << std::endl;
	Card a(Card::CardValue::Card_3, Card::CardSuit::Club);
	Card b(Card::CardValue::Card_2, Card::CardSuit::Club);
	int flag_a = a.getValue();
	int flag_b = b.getValue();
	cout << flag_a << endl << flag_b;
	Deck cards;
	cards.add(a);
	cards.add(b);

	return 0;
}