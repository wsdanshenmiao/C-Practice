#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()//定义菜单
{
	printf("****************************\n");
	printf("******1:play****0:exot******\n");
	printf("****************************\n");
}

void game()//定义游戏
{
	int ret;
	char board[ROW][COL];
	INBOARD(board,ROW,COL);//初始化棋盘
	PUTBOARD(board,ROW,COL);//打印棋盘
	while (1)
	{
		PLAYER(board, ROW, COL);//玩家下棋
		PUTBOARD(board, ROW, COL);
		ret=WIN(board, ROW, COL);//判断输赢
		if(ret!='c')
		{
			break;
		}
		COMPUTER(board, ROW, COL);//电脑下棋
		PUTBOARD(board, ROW, COL);
		ret=WIN(board, ROW, COL);
		if(ret!='c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢。\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢。\n");
	}
	else
	{
		printf("平局。\n");
	}
}

void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("开始游戏。\n");
				game();
				break;
			case 0:
				printf("退出游戏。\n");
				break;
			default:
				printf("输入错误。\n");
				break;
		}
	} while(input);
}

int main()
{
	test();
	return 0;
}