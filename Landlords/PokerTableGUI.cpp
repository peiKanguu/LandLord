#include "PokerTableGUI.h"


IMAGE tableImg[10];

PokerTableGUI::PokerTableGUI() {
	//����ͼƬ
	loadimage(&tableImg[0], "./macro_img/icon_close.png", 200, 100);
	loadimage(&tableImg[1], "./macro_img/icon_set.png", 200, 100);
	loadimage(&tableImg[2], "./macro_img/icon_return.png", 200, 100);
	loadimage(&tableImg[3], "./macro_img/button_orange.png", 200, 100);
	loadimage(&tableImg[4], "./macro_img/desk.png", 1280, 576);
	//��ʼ����ť����
	/*ChatButton = Button(1050, 451, 200, 100, "����", "./macro_img/button_orange.png", click);
	exitButton = Button(1050, 25, 200, 100, "�˳���Ϸ", "./macro_img/icon_close.png",click);
	settingButton = Button(825, 25, 200, 100, "����", "./macro_img/icon_set.png",click);
	rentrunButton = Button(25, 25, 200, 100, "����", "./macro_img/icon_return.png",click);*/
}

void PokerTableGUI::show() {
	//���Ʊ���ͼ
	putimage(0, 0, &tableImg[4]);
	
	////���ư�ť
	//ChatButton.draw();
	//exitButton.draw();
	//settingButton.draw();
	//rentrunButton.draw();
}



