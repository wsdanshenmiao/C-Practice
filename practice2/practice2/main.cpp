#include <stdio.h>
#include <graphics.h>
#include "tools.hpp"

int main()
{
	initgraph(1920, 1280, EX_SHOWCONSOLE);
	setbkcolor(RGB(138, 138, 138));
	cleardevice();

	//����ͼƬ����
	IMAGE picture;
	//����ͼƬ
	//����·�������̷���·��    ���·����
	loadimage(&picture, "assets/key.jpg");
	//���ͼƬ
	putimage(0, 0, &picture);

	//����ͼ͸����ͼ
	IMAGE player[2];
	loadimage(player + 0, "assets/planeNormal_1.jpg");
	loadimage(player + 1, "assets/planeNormal_2.jpg");
	putimage(100, 100, player + 0, NOTSRCERASE);//�Ȼ�������ͼ
	putimage(100, 100, player + 1, SRCERASE);//�ڻ���ԭͼ

	//PNG͸����ͼ
	IMAGE img_png;
	loadimage(&img_png, "assets/�������Σ���ħ���Ի����ػ棩.png");
	//putimage(200, 200, &img_png);
	drawImg(200, 200, &img_png);

	getchar();

	return 0;
}