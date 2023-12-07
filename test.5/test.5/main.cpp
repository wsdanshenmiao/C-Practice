#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <easyx.h>
#include <graphics.h>

void drawshape()
{
	//绘制一个点
	putpixel(50, 50, RED);

	//设置线条颜色
	setlinecolor(BLUE);
	//设置线条样式
	setlinestyle(PS_SOLID, 3);
	//绘制一条线
	line(0, 0, getwidth(), getheight());

	//绘制一个矩形
	rectangle(100, 50, 100 + 50, 50 + 50);//无填充矩形
	setfillcolor(YELLOW);//填充颜色
	fillrectangle(100, 50, 100 + 50, 50 + 50);//有填充矩形
	solidrectangle(200, 50, 200 + 50, 50 + 50);//无边框矩形
	roundrect(300, 50, 300 + 50, 50 + 50, 20, 20);//圆角矩形
	fillroundrect(300, 100, 300 + 50, 100 + 50, 20, 20);
	solidroundrect(300, 200, 300 + 50, 200 + 50, 20, 20);

	//绘制一个园
	circle(200, 400, 100);
	fillcircle(400, 400, 100);
	solidcircle(100, 100, 20);

	//椭圆
	ellipse(500, 500, 500 + 30, 500 + 10);
	fillellipse(500, 400, 500 + 30, 400 + 10);
	solidellipse(500, 300, 500 + 30, 300 + 10);

	//折线
	POINT points[] = { {30,30},{50,70},{200,130} };
	polyline(points, 3);
}

void drawtext()
{
	printf("to c or no to c,this is a question\n");
	//设置文字大小
	settextstyle(40, 0, ("华文行楷"));
	//设置文字颜色
	settextcolor(BLUE);
	//设置背景模式
	setbkmode(TRANSPARENT);
	//绘制文字
	outtextxy(10, 10, "to c or no to c,this is a question");
	//有一个int型的数字，输出到图形窗口上
	int a = 66;
	char b[50] = "";
	sprintf(b, "%d", a);
	outtextxy(50, 50, b);
}

int main()
{
	initgraph(680, 580, EX_SHOWCONSOLE);//创建一个图形窗口
	setbkcolor(RGB(217, 146, 219));//设置窗口背景颜色
	cleardevice();//用背景颜色填充屏幕
	//drawshape();
	drawtext();

	getchar();
	return 0;
}