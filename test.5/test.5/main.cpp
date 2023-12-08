#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <easyx.h>
#include <graphics.h>

//定义消息结构体变量
ExMessage msg = { 0 };

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
	settextstyle(40, 0, ("微软雅黑"));
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

void centertext()
{
	int rightx = 450;
	int righty = 250;
	int width = 200;
	int height = 100;
	setfillcolor(RGB(0, 0, 0));
	solidrectangle(rightx, righty, rightx + width, righty + height);
	settextcolor(WHITE);
	char arr[] = "Center Text";
	int wspace = (width - textwidth(arr))/2;
	int hspace = (height - textheight(arr))/2;
	outtextxy(rightx + wspace, righty + hspace, arr);
}

void mousecontrol()
{
	//定义消息结构体变量
	ExMessage msg = { 0 };
	//获取消息
	while (1) {
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				printf("鼠标左键按下%d %d\n", msg.x, msg.y);
				break;
			case WM_RBUTTONDOWN:
				printf("鼠标右键按下\n");
				break;
			case WM_MBUTTONDOWN:
				printf("鼠标中键按下\n");
				break;
			case WM_MOUSEWHEEL:
				printf("鼠标滚轮 %d\n", msg.wheel);
				break;
			case WM_LBUTTONDBLCLK:
				printf("鼠标左键双击\n");
				break;
			case WM_RBUTTONDBLCLK:
				printf("鼠标右键双击\n");
				break;
			case WM_MOUSEMOVE:
				//printf("鼠标移动\n");
				break;
			}
		}
	}
}

int inarea(int mx, int my, int x, int y, int width, int height)//判断是否在指定区域
{
	if (x < mx && mx < x + width && y < my && my < y + height) {
		return 1;
	}
	else {
		return 0;
	}
}

int button(int x, int y, int width, int height, const char* text)
{
	if (inarea(msg.x, msg.y, x, y, width, height)) {
		setfillcolor(RGB(215, 216, 221));
	}
	else {
		setfillcolor(WHITE);
	}
	//绘制按钮
	fillrectangle(x, y, x + width, y + height);
	//绘制文本
	settextcolor(BLACK);
	int wspace = (width - textwidth(text)) / 2;
	int hspace = (height - textheight(text)) / 2;
	outtextxy(x + wspace, y + hspace, text);
	//判断按钮是否被按下
	if (msg.message == WM_LBUTTONDOWN && inarea(msg.x, msg.y, x, y, width, height)) {
		return 1;
	}
	else {
		return 0;
	}
}


int main()
{
	//创建一个图形窗口
	initgraph(1000, 600, EX_SHOWCONSOLE | EX_DBLCLKS);

	//设置窗口背景颜色
	setbkcolor(RGB(217, 146, 219));

	//用背景颜色填充屏幕
	cleardevice();

	//设置背景模式
	setbkmode(TRANSPARENT);
	//drawshape();
	//drawtext();
	//centertext();
	//mousecontrol();

	int i = 0;
	int circlex = 500;
	int circley = 100;
	int circler = 50;
	int speed = 4;//速度
	int vx = 0;
	int vy = 0;
	
	while (1) {	
		peekmessage(&msg, EX_MOUSE | EX_KEY);
		//双缓冲绘图，所有绘图代码必须放在begin和end之间
		BeginBatchDraw();
		cleardevice();
		if (button(200, 400, 150, 80, "Start Game!")) {
			printf("Start Game!%d \n", i++);
		}		
		if (button(650, 400, 150, 80, "Eed Game!")) {
			printf("End Game!\n");
		}
		
		setfillcolor(YELLOW);
		solidcircle(circlex, circley, circler);
		circlex += speed * vx;
		circley += speed * vy;

		EndBatchDraw();

		//按键消息
		if (msg.message == WM_KEYDOWN) {
			printf("keydown\n");
			switch (msg.vkcode) {
			case VK_UP:
				vy = -1;
				break;
			case VK_DOWN:
				vy = 1;
				break;
			case VK_LEFT:
				vx = -1;
				break;
			case VK_RIGHT:
				vx = 1;
				break;
			case VK_SPACE:
				break;
			case 'A':
				break;
			}
		}
		else if (msg.message == WM_KEYUP) {
			printf("keyup\n");
			switch (msg.vkcode) {
			case VK_UP:
				vy = 0;
				break;
			case VK_DOWN:
				vy = 0;
				break;
			case VK_LEFT:
				vx = 0;
				break;
			case VK_RIGHT:
				vx = 0;
				break;
			}
		}
		Sleep(10);
		//把消息类型置为零
		msg.message = 0;
	}

	getchar();
	return 0;
}