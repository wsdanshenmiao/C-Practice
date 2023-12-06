#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()//����˵�
{
	printf("****************************\n");
	printf("******1:play****0:exot******\n");
	printf("****************************\n");
}

void game()//������Ϸ
{
	int ret;
	char board[ROW][COL];
	INBOARD(board,ROW,COL);//��ʼ������
	PUTBOARD(board,ROW,COL);//��ӡ����
	while (1)
	{
		PLAYER(board, ROW, COL);//�������
		PUTBOARD(board, ROW, COL);
		ret=WIN(board, ROW, COL);//�ж���Ӯ
		if(ret!='c')
		{
			break;
		}
		COMPUTER(board, ROW, COL);//��������
		PUTBOARD(board, ROW, COL);
		ret=WIN(board, ROW, COL);
		if(ret!='c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ�֡�\n");
	}
}

void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("��ʼ��Ϸ��\n");
				game();
				break;
			case 0:
				printf("�˳���Ϸ��\n");
				break;
			default:
				printf("�������\n");
				break;
		}
	} while(input);
}

int main()
{
	test();
	return 0;
}