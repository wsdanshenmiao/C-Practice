#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <easyx.h>
#include <graphics.h>

//������Ϣ�ṹ�����
ExMessage msg = { 0 };

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
	settextstyle(40, 0, ("΢���ź�"));
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
	//������Ϣ�ṹ�����
	ExMessage msg = { 0 };
	//��ȡ��Ϣ
	while (1) {
		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				printf("����������%d %d\n", msg.x, msg.y);
				break;
			case WM_RBUTTONDOWN:
				printf("����Ҽ�����\n");
				break;
			case WM_MBUTTONDOWN:
				printf("����м�����\n");
				break;
			case WM_MOUSEWHEEL:
				printf("������ %d\n", msg.wheel);
				break;
			case WM_LBUTTONDBLCLK:
				printf("������˫��\n");
				break;
			case WM_RBUTTONDBLCLK:
				printf("����Ҽ�˫��\n");
				break;
			case WM_MOUSEMOVE:
				//printf("����ƶ�\n");
				break;
			}
		}
	}
}

int inarea(int mx, int my, int x, int y, int width, int height)//�ж��Ƿ���ָ������
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
	//���ư�ť
	fillrectangle(x, y, x + width, y + height);
	//�����ı�
	settextcolor(BLACK);
	int wspace = (width - textwidth(text)) / 2;
	int hspace = (height - textheight(text)) / 2;
	outtextxy(x + wspace, y + hspace, text);
	//�жϰ�ť�Ƿ񱻰���
	if (msg.message == WM_LBUTTONDOWN && inarea(msg.x, msg.y, x, y, width, height)) {
		return 1;
	}
	else {
		return 0;
	}
}


int main()
{
	//����һ��ͼ�δ���
	initgraph(1000, 600, EX_SHOWCONSOLE | EX_DBLCLKS);

	//���ô��ڱ�����ɫ
	setbkcolor(RGB(217, 146, 219));

	//�ñ�����ɫ�����Ļ
	cleardevice();

	//���ñ���ģʽ
	setbkmode(TRANSPARENT);
	//drawshape();
	//drawtext();
	//centertext();
	//mousecontrol();

	int i = 0;
	int circlex = 500;
	int circley = 100;
	int circler = 50;
	int speed = 4;//�ٶ�
	int vx = 0;
	int vy = 0;
	
	while (1) {	
		peekmessage(&msg, EX_MOUSE | EX_KEY);
		//˫�����ͼ�����л�ͼ����������begin��end֮��
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

		//������Ϣ
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
		//����Ϣ������Ϊ��
		msg.message = 0;
	}

	getchar();
	return 0;
}