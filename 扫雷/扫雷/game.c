#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

VCSH(char visted[ROWS][COLS], int rows, int cols, int set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (i == 0 || j ==0 || i == rows - 1 || j == cols - 1)
			{
				visted[i][j] = '1';
			}
			else
			{
				visted[i][j] = set;
			}
		}
	}
}

void CSH(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DISPLAYBOARD(char board[ROWS][COLS], int row, int col)//打印雷盘
{
	int i, j;
	for (j = 0; j <= col; j++)
	{
		printf(" %d  ", j);
	}
	printf("\n\n");
	for (i = 0; i < row; i++)
	{
		printf(" %d  ", i + 1);
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i+1][j+1]);
			if (j < col-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			printf("    ");
		}
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void SETIN(char board[ROWS][COLS], int row, int col)//放置雷
{
	int count=COUNT;
	
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int GET_COUNT(char in[ROWS][COLS], int x, int y)//计算坐标周围的雷
{
	int cnt = in[x - 1][y - 1] +
		in[x - 1][y] +
		in[x - 1][y + 1] +
		in[x][y - 1] +
		in[x][y + 1] +
		in[x + 1][y - 1] +
		in[x + 1][y] +
		in[x + 1][y + 1] - 8 * '0';
	return cnt;
	//int count = 0;
	//int i, j;
	//for (i=-1;i<2;i++)
	//{
	//	for (j = -1; j < 2; j++)
	//	{
	//		if (in[x + i][y + j] == '1')
	//		{
	//			count++;
	//		}
	//	}
	//}
	//return count;
}

void BOOM(char in[ROWS][COLS], char show[ROWS][COLS], char visted[ROWS][COLS], int x, int y)
{
	int count = GET_COUNT(in, x, y);
	char vist[ROWS][COLS] = { 0 };
	//int i, j;
	if (count > 0) 
	{
		show[x][y] = count + '0';
	}
	else
	{
		show[x][y] = ' ';
		if (visted[x - 1][y - 1] == 0)
		{
			vist[x - 1][y - 1] = 1;
			visted[x - 1][y - 1] = 1;
		}
		if (visted[x - 1][y] == 0)
		{
			vist[x - 1][y] = 1;
			visted[x - 1][y] = 1;
		}
		if (visted[x - 1][y + 1] == 0)
		{
			vist[x - 1][y + 1] = 1;
			visted[x - 1][y + 1] = 1;
		}
		if (visted[x][y - 1] == 0)
		{
			vist[x][y - 1] = 1;
			visted[x][y - 1] = 1;
		}
		if (visted[x][y + 1] == 0)
		{
			vist[x][y + 1] = 1;
			visted[x][y + 1] = 1;
		}
		if (visted[x + 1][y - 1] == 0)
		{
			vist[x + 1][y - 1] = 1;
			visted[x + 1][y - 1] = 1;
		}
		if (visted[x + 1][y] == 0)
		{
			vist[x + 1][y] = 1;
			visted[x + 1][y] = 1;
		}
		if (visted[x + 1][y + 1] == 0)
		{
			vist[x + 1][y + 1] = 1;
			visted[x + 1][y + 1] = 1;
		}


		if (vist[x - 1][y - 1] == 1)
		{
			BOOM(in, show, x - 1, y - 1, visted);
		}
		if (vist[x - 1][y] == 1)
		{
			BOOM(in, show, x - 1, y, visted);
		}
		if (vist[x - 1][y + 1] == 1)
		{
			BOOM(in, show, x - 1, y + 1, visted);
		}
		if (vist[x][y - 1] == 1)
		{
			BOOM(in, show, x, y - 1, visted);
		}
		if (vist[x][y + 1] == 1)
		{
			BOOM(in, show, x, y + 1, visted);
		}
		if (vist[x + 1][y - 1] == 1)
		{
			BOOM(in, show, x + 1, y - 1, visted);
		}
		if (vist[x + 1][y] == 1)
		{
			BOOM(in, show, x + 1, y, visted);
		}
		if (vist[x + 1][y + 1] == 1)
		{
			BOOM(in, show, x + 1, y + 1, visted);
		}
		//	for (i = -1; i < 2; i++)
		//	{
		//		for (j = -1; j < 2; j++)
		//		{
		//			if (visted[x + i][y + j] == '0')
		//			{
		//				visted[x + i][y + j] = '1';
		//				vist[x + i][y + j] = '1';
		//			}
		//		}
		//	}
		//	for (i = -1; i < 2; i++)
		//	{
		//		for (j = -1; j < 2; j++)
		//		{
		//			if (visted[x + i][y + j] == '1')
		//			{
		//				BOOM(in,show,visted, x + i, y + j);
		//			}
		//		}
		//	}
	}
}

void PLAYER(char show[ROWS][COLS], char in[ROWS][COLS], char visted[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win<row*col-COUNT)
	{
		int x, y;
		printf("请输入坐标.\n");
		scanf("%d%d", &x, &y);
		if (0 < x && x <= row && 0 < y <= col)
		{
			if (in[x][y] == '1')
			{
				DISPLAYBOARD(in, ROW, COL);
				printf("LOST!!!\n");
				break;
			}
			else
			{
				visted[x][y] == 1;
				//show[x][y] = count + '0';
				BOOM(in, show, visted, x, y);
				DISPLAYBOARD(show, ROW, COL);
				win++;
			}
			if (win == row * col - COUNT)
			{
				DISPLAYBOARD(show, ROW, COL);
				printf("YOU WIN!!!\n");
			}
		}
		else
		{
			printf("输入错误,请重新输入.\n");
		}
	}
}




//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "game.h"
//
//void InitBoard(char board[DIF_ROWS][DIF_COLS], int rows, int cols, char ch)
//{
//	int i = 0;
//	for (i = 0; i < rows; i++)
//	{
//		int j = 0;
//		for (j = 0; j < cols; j++)
//		{
//			board[i][j] = ch;
//		}
//	}
//}
//
//void DisPlayBoard(char board[DIF_ROWS][DIF_COLS], int row, int col)
//{
//	int i = 0;
//	printf("   ");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%2d ", i);
//	}
//	printf("\n");
//	printf("  |");
//	for (i = 1; i <= row; i++)
//	{
//		printf("---");
//	}
//	printf("\n");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%2d|", i);
//		int j = 0;
//		for (j = 1; j <= col; j++)
//		{
//			printf(" %c ", board[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void SetMine(char mine[DIF_ROWS][DIF_COLS], int row, int col, int cnt)
//{
//	while (cnt > 0)
//	{
//		int x = 0;
//		int y = 0;
//		x = rand() % row + 1;
//		y = rand() % col + 1;
//		if (mine[x][y] == '0')
//		{
//			mine[x][y] = '1';
//			cnt--;
//		}
//	}
//}
//
//int MineCount(char mine[DIF_ROWS][DIF_COLS], int x, int y)
//{
//	int cnt = mine[x - 1][y - 1] +
//		mine[x - 1][y] +
//		mine[x - 1][y + 1] +
//		mine[x][y - 1] +
//		mine[x][y + 1] +
//		mine[x + 1][y - 1] +
//		mine[x + 1][y] +
//		mine[x + 1][y + 1] - 8 * '0';
//	return cnt;
//
//}
//
//void Expend(char mine[DIF_ROWS][DIF_COLS], char show[DIF_ROWS][DIF_COLS], int x, int y, int visted[DIF_ROWS][DIF_COLS])
//{
//	//visted[x][y] == 1;
//	int vist[DIF_ROWS][DIF_COLS] = { 0 };
//	int cnt = MineCount(mine, x, y);
//	if (cnt > 0)
//		show[x][y] = cnt + '0';
//	else
//	{
//		show[x][y] = ' ';
//		if (visted[x - 1][y - 1] == 0)
//		{
//			vist[x - 1][y - 1] = 1;
//			visted[x - 1][y - 1] = 1;
//		}
//		if (visted[x - 1][y] == 0)
//		{
//			vist[x - 1][y] = 1;
//			visted[x - 1][y] = 1;
//		}
//		if (visted[x - 1][y + 1] == 0)
//		{
//			vist[x - 1][y + 1] = 1;
//			visted[x - 1][y + 1] = 1;
//		}
//		if (visted[x][y - 1] == 0)
//		{
//			vist[x][y - 1] = 1;
//			visted[x][y - 1] = 1;
//		}
//		if (visted[x][y + 1] == 0)
//		{
//			vist[x][y + 1] = 1;
//			visted[x][y + 1] = 1;
//		}
//		if (visted[x + 1][y - 1] == 0)
//		{
//			vist[x + 1][y - 1] = 1;
//			visted[x + 1][y - 1] = 1;
//		}
//		if (visted[x + 1][y] == 0)
//		{
//			vist[x + 1][y] = 1;
//			visted[x + 1][y] = 1;
//		}
//		if (visted[x + 1][y + 1] == 0)
//		{
//			vist[x + 1][y + 1] = 1;
//			visted[x + 1][y + 1] = 1;
//		}
//
//
//		if (vist[x - 1][y - 1] == 1)
//		{
//			Expend(mine, show, x - 1, y - 1, visted);
//		}
//		if (vist[x - 1][y] == 1)
//		{
//			Expend(mine, show, x - 1, y, visted);
//		}
//		if (vist[x - 1][y + 1] == 1)
//		{
//			Expend(mine, show, x - 1, y + 1, visted);
//		}
//		if (vist[x][y - 1] == 1)
//		{
//			Expend(mine, show, x, y - 1, visted);
//		}
//		if (vist[x][y + 1] == 1)
//		{
//			Expend(mine, show, x, y + 1, visted);
//		}
//		if (vist[x + 1][y - 1] == 1)
//		{
//			Expend(mine, show, x + 1, y - 1, visted);
//		}
//		if (vist[x + 1][y] == 1)
//		{
//			Expend(mine, show, x + 1, y, visted);
//		}
//		if (vist[x + 1][y + 1] == 1)
//		{
//			Expend(mine, show, x + 1, y + 1, visted);
//		}
//	}
//}
//
//void FindMine(char mine[DIF_ROWS][DIF_COLS], char show[DIF_ROWS][DIF_COLS], int row, int col, int cnt, int visted[DIF_ROWS][DIF_COLS])
//{
//	while (1)
//	{
//		int x = 0;
//		int y = 0;
//		printf("请输入:>");
//		scanf("%d%d", &x, &y);
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (1 == visted[x][y])
//			{
//				printf("该位子已被占用\n");
//			}
//			else if (mine[x][y] == '1')
//			{
//				show[x][y] = '$';
//				DisPlayBoard(show, row, col);
//				printf("你踩到雷了\n");
//				break;
//			}
//			else
//			{
//				visted[x][y] == 1;
//				Expend(mine, show, x, y, visted);
//				DisPlayBoard(show, row, col);
//			}
//		}
//		else
//		{
//			printf("超出范围\n");
//		}
//		int count = 0;
//		int i = 0;
//		for (i = 1; i <= row; i++)
//		{
//			int j = 0;
//			for (j = 1; j <= col; j++)
//			{
//				if (show[i][j] == '*')
//				{
//					count++;
//				}
//			}
//		}
//		if (count == cnt)
//		{
//			printf("恭喜你，你赢了\n");
//			break;
//		}
//	}
//}
