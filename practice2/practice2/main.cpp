#include <stdio.h>
#include <graphics.h>

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

	getchar();

	return 0;
}