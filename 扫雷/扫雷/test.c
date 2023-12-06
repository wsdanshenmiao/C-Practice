#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("*************************************\n");
	printf("***********1.play   0.exit***********\n");
	printf("*************************************\n");
}

void game()
{
	char in[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	char visted[ROWS][COLS] = { 0 };
	VCSH(visted, ROWS, COLS, '0');
	DISPLAYBOARD(visted, ROWS, COLS);
	CSH(in,ROWS,COLS,'0');//初始化数组
	CSH(show, ROWS, COLS, '*');//初始化数组
	DISPLAYBOARD(show, ROW, COL);//打印雷盘
	SETIN(in, ROW, COL);//放置雷
	DISPLAYBOARD(in, ROW, COL);
	PLAYER(show, in, visted, ROW, COL);
}

void test()
{
	int input = 1;
	srand((unsigned int)time(NULL));
	for (;input;)
	{
		menu();
		printf("请选择.");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏.\n");
			game();
			break;
		case 0:
			printf("结束游戏.\n");
			break;
		default:
			printf("输入错误，请重新选择.\n");
			break;
		}
	}
}

int main()

{
	test();
	return 0;
}



//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "game.h"
//
//int ROW = 0;
//int COL = 0;
//int ROWS = 0;
//int COLS = 0;
//int count = 0;
//
//void game_rule()
//{
//	printf("***********游戏规则: ***********\n");
//	printf("游戏开始前，你可以选择游戏难度,\n");
//	printf("设有简单，中级，困难三种难度，每\n");
//	printf("种难度棋盘大小和雷的数目都不一样,\n");
//	printf("当你把所有非雷位置找出时，既赢下\n");
//	printf("游戏,祝您游戏愉快\n");
//	printf("\n");
//	printf("\n");
//}
//
//void menu()
//{
//	printf("********************************\n");
//	printf("********   1. play     *********\n");
//	printf("********   0. exit     *********\n");
//	printf("********************************\n");
//}
//
//void select_diffcult()
//{
//	printf("************难度系数***********\n");
//	printf("**********  1. 简单   *********\n");
//	printf("**********  2. 中级   *********\n");
//	printf("**********  3. 困难   *********\n");
//	int input = 0;
//	do {
//		printf("请选择:>");
//		int select = 0;
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			ROW = EASY_ROW;
//			COL = EASY_COL;
//			ROWS = EASY_ROWS;
//			COLS = EASY_COLS;
//			count = EASY_COUNT;
//			input = 0;
//			break;
//		case 2:
//			ROW = MID_ROW;
//			COL = MID_COL;
//			ROWS = MID_ROWS;
//			COLS = MID_COLS;
//			count = MID_COUNT;
//			input = 0;
//			break;
//		case 3:
//			ROW = DIF_ROW;
//			COL = DIF_COL;
//			ROWS = DIF_ROWS;
//			COLS = DIF_COLS;
//			count = DIF_COUNT;
//			input = 0;
//			break;
//		default:
//			input = 1;
//			break;
//		}
//	} while (input);
//}
//void game()
//{
//	select_diffcult();
//	char mine[DIF_ROWS][DIF_COLS];
//	char show[DIF_ROWS][DIF_COLS];
//	int visted[DIF_ROWS][DIF_COLS];
//	int i = 0;
//	for (i = 0; i < ROWS; i++)
//	{
//		int j = 0;
//		for (j = 0; j < COLS; j++)
//		{
//			if (i == 0)
//				visted[i][j] = 1;
//			else if (j == 0)
//				visted[i][j] = 1;
//			else if (i == ROWS - 1)
//				visted[i][j] = 1;
//			else if (j == COLS - 1)
//				visted[i][j] = 1;
//			else
//				visted[i][j] = 0;
//		}
//	}
//	//初始化棋盘
//	InitBoard(mine, ROWS, COLS, '0');
//	InitBoard(show, ROWS, COLS, '*');
//	//打印棋盘
//	DisPlayBoard(show, ROW, COL);
//	DisPlayBoard(mine, ROW, COL);
//	DisPlayBoard(visted, ROW, COL);
//	//存放雷
//	SetMine(mine, ROW, COL, count);
//	//排查雷
//	FindMine(mine, show, ROW, COL, count, visted);
//}
//
//int main()
//{
//	game_rule();
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}