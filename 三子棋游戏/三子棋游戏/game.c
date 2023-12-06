#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void INBOARD(char board[ROW][COL], int row,int col)
{
	int i;
	for (i = 0; i < row; i++)
	{
		int j;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


void PUTBOARD(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < row - 1)
				{
					printf("|");
				}
			}
		}
			printf("\n");
	}
}

void PLAYER(char board[ROW][COL], int row, int col)
{
	printf("玩家走。\n");
	int x, y;
	while (1)
	{
		printf("请下棋。\n");
		scanf("%d%d", &x, &y);
		if (1 <= x && x <= row && 1 <= y && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用。\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入。\n");
		}
	}
}

void COMPUTER(char board[ROW][COL], int row, int col)
{
	printf("电脑走。\n");
	int x,y;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}


int FULL(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


char WIN(char board[ROW][COL],int row,int col)
{
	int i;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&& board[i][1]!=' ')
		{
			return board[i][1];

		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[i][i] == board[2][i] && board[i][1] != ' ')
		{
			return board[1][i];
		}
	}
	if (1==FULL(board,row,col))
	{
		return 'o';
	}
	else
		return 'c';
}