#include "PokerTableGUI.h"


IMAGE tableImg[10];

PokerTableGUI::PokerTableGUI() {
	//加载图片
	loadimage(&tableImg[0], "./macro_img/icon_close.png", 200, 100);
	loadimage(&tableImg[1], "./macro_img/icon_set.png", 200, 100);
	loadimage(&tableImg[2], "./macro_img/icon_return.png", 200, 100);
	loadimage(&tableImg[3], "./macro_img/button_orange.png", 200, 100);
	loadimage(&tableImg[4], "./macro_img/desk.png", 1280, 576);
	//初始化按钮参数
	/*ChatButton = Button(1050, 451, 200, 100, "聊天", "./macro_img/button_orange.png", click);
	exitButton = Button(1050, 25, 200, 100, "退出游戏", "./macro_img/icon_close.png",click);
	settingButton = Button(825, 25, 200, 100, "设置", "./macro_img/icon_set.png",click);
	rentrunButton = Button(25, 25, 200, 100, "返回", "./macro_img/icon_return.png",click);*/
}

void PokerTableGUI::show() {
	//绘制背景图
	putimage(0, 0, &tableImg[4]);
	
	////绘制按钮
	//ChatButton.draw();
	//exitButton.draw();
	//settingButton.draw();
	//rentrunButton.draw();
}



