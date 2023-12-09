#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <graphics.h>
#include "tools.hpp"
#include <time.h>

int main()
{
	initgraph(1080, 680, EX_SHOWCONSOLE);
	setbkcolor(RGB(223, 223, 225));
	cleardevice();

	int freamDelay = 1000 / 60;
	int freamBegin = 0;
	int freamEnd = 0;

	int freams = 7;//帧数
	int speed = 100;//每张图的时间间隔
	int img_size = 32;//每张图的大小
	int index = 0;//显示的图

	//动画
	IMAGE img_pikaqu;
	loadimage(&img_pikaqu, "assets/pikachu.png");

	while (1) {
		freamBegin = clock();

		BeginBatchDraw();
		cleardevice();

		drawImg(100, 100, img_size, img_size, &img_pikaqu, index * img_size, 0);

		EndBatchDraw();

		index = (clock() / speed) % freams;

		freamEnd = clock() - freamBegin;
		if (freamDelay - freamEnd > 0) {
			Sleep(freamDelay - freamEnd);
		}
	}


	//IMAGE img_enemy[4];
	//char img_enemy0[50];
	//for (int i = 0; i < 4; i++) {
	//	sprintf(img_enemy0, "assets/enemy1_down%d.png", i + 1);
	//	loadimage(img_enemy + i, img_enemy0);
	//}
	//const int freamDelay = 1000 / 16;
	//int freamBegin = 0;
	//int freamEnd = 0;
	//int fream = 4;
	//int speed = 500;
	//int index = 0;
	//while (1) {
	//	freamBegin = clock();
	//	BeginBatchDraw();
	//	cleardevice();
	//	drawImg(100, 100, img_enemy + index);
	//	EndBatchDraw();
	//	index++;
	//	index = clock()/speed % fream;

	//	freamEnd = clock() - freamBegin;
	//	if (freamDelay - freamEnd > 0) {
	//		Sleep(freamDelay - freamEnd);
	//	}
	//}

	getchar();
	return 0;
}