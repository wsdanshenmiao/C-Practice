#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "- This, a sample string.";
	char* pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
	return 0;
}


//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <graphics.h>
//#include <time.h>
////����
////˫����
////֡�ʿ���
//
//int main()
//{
//	initgraph(1080, 680, EX_SHOWCONSOLE);
//	setbkcolor(RGB(138, 138, 138));
//	setbkmode(TRANSPARENT);
//	cleardevice();
//
//	//FPS 60֡
//	const clock_t FPS = 1000 / 60;//ÿһ֡���ѵ�ʱ��
//	int startTime = 0;
//	int endTime = 0;//��ǰִ֡�е�ʱ��
//
//	int score = 0;
//	char str[50] = "";
//	while (1) {
//		startTime = clock();
//
//		sprintf(str, "Score:%d", score++);
//		settextcolor(BLACK);
//		settextstyle(50, 0, "΢���ź�");
//
//		//˫�����ֹ����
//		BeginBatchDraw();
//		cleardevice();
//
//		outtextxy(1040 - textwidth("Score:%d"), 0, str);
//
//		EndBatchDraw();
//
//		endTime = clock() - startTime;
//		if (endTime > 0) {
//			Sleep(FPS - endTime);
//		}
//	}
//
//	return 0;
//}