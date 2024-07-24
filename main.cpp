#include "Card.h"
#include "Deck.h"

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<cstdint>
#include<chrono>				//精准帧率控制
#include<graphics.h>			//包含easyx,easyx包含Windows.h
#include<time.h>				//倒计时的头文件
#include<conio.h>				//包含控制台输入输出的头文件
#include<mmsystem.h>			//音乐的头文件
#pragma comment(lib, "winmm.lib")//音乐的库文件
using namespace std;

int main()
{
	std::cout << "程序入口" << std::endl;
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