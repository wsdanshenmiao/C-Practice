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
	CSH(in,ROWS,COLS,'0');//��ʼ������
	CSH(show, ROWS, COLS, '*');//��ʼ������
	DISPLAYBOARD(show, ROW, COL);//��ӡ����
	SETIN(in, ROW, COL);//������
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
		printf("��ѡ��.");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ.\n");
			game();
			break;
		case 0:
			printf("������Ϸ.\n");
			break;
		default:
			printf("�������������ѡ��.\n");
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
//	printf("***********��Ϸ����: ***********\n");
//	printf("��Ϸ��ʼǰ�������ѡ����Ϸ�Ѷ�,\n");
//	printf("���м򵥣��м������������Ѷȣ�ÿ\n");
//	printf("���Ѷ����̴�С���׵���Ŀ����һ��,\n");
//	printf("��������з���λ���ҳ�ʱ����Ӯ��\n");
//	printf("��Ϸ,ף����Ϸ���\n");
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
//	printf("************�Ѷ�ϵ��***********\n");
//	printf("**********  1. ��   *********\n");
//	printf("**********  2. �м�   *********\n");
//	printf("**********  3. ����   *********\n");
//	int input = 0;
//	do {
//		printf("��ѡ��:>");
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
//	//��ʼ������
//	InitBoard(mine, ROWS, COLS, '0');
//	InitBoard(show, ROWS, COLS, '*');
//	//��ӡ����
//	DisPlayBoard(show, ROW, COL);
//	DisPlayBoard(mine, ROW, COL);
//	DisPlayBoard(visted, ROW, COL);
//	//�����
//	SetMine(mine, ROW, COL, count);
//	//�Ų���
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
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}