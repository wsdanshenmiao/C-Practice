#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <easyx.h>
#include <graphics.h>

void drawshape()
{
	//����һ����
	putpixel(50, 50, RED);

	//����������ɫ
	setlinecolor(BLUE);
	//����������ʽ
	setlinestyle(PS_SOLID, 3);
	//����һ����
	line(0, 0, getwidth(), getheight());

	//����һ������
	rectangle(100, 50, 100 + 50, 50 + 50);//��������
	setfillcolor(YELLOW);//�����ɫ
	fillrectangle(100, 50, 100 + 50, 50 + 50);//��������
	solidrectangle(200, 50, 200 + 50, 50 + 50);//�ޱ߿����
	roundrect(300, 50, 300 + 50, 50 + 50, 20, 20);//Բ�Ǿ���
	fillroundrect(300, 100, 300 + 50, 100 + 50, 20, 20);
	solidroundrect(300, 200, 300 + 50, 200 + 50, 20, 20);

	//����һ��԰
	circle(200, 400, 100);
	fillcircle(400, 400, 100);
	solidcircle(100, 100, 20);

	//��Բ
	ellipse(500, 500, 500 + 30, 500 + 10);
	fillellipse(500, 400, 500 + 30, 400 + 10);
	solidellipse(500, 300, 500 + 30, 300 + 10);

	//����
	POINT points[] = { {30,30},{50,70},{200,130} };
	polyline(points, 3);
}

void drawtext()
{
	printf("to c or no to c,this is a question\n");
	//�������ִ�С
	settextstyle(40, 0, ("�����п�"));
	//����������ɫ
	settextcolor(BLUE);
	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//��������
	outtextxy(10, 10, "to c or no to c,this is a question");
	//��һ��int�͵����֣������ͼ�δ�����
	int a = 66;
	char b[50] = "";
	sprintf(b, "%d", a);
	outtextxy(50, 50, b);
}

int main()
{
	initgraph(680, 580, EX_SHOWCONSOLE);//����һ��ͼ�δ���
	setbkcolor(RGB(217, 146, 219));//���ô��ڱ�����ɫ
	cleardevice();//�ñ�����ɫ�����Ļ
	//drawshape();
	drawtext();

	getchar();
	return 0;
}