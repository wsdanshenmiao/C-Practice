#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define COUNT 1

#define ROWS ROW+2
#define COLS COL+2

VCSH(char visted[ROWS][COLS], int rows, int cols, int set);
void CSH(char board[ROWS][COLS], int rows, int cols, char set);
void DISPLAYBOARD(char board[ROWS][COLS], int row, int col);//��ӡ����
void SETIN(char board[ROWS][COLS], int row, int col);//������
void PLAYER(char show[ROWS][COLS], char in[ROWS][COLS], char visted[ROWS][COLS], int row, int col);
int GET_COUNT(char in[ROWS][COLS], int x, int y,int count);//����������Χ����
void BOOM(char in[ROWS][COLS], char show[ROWS][COLS], char visted[ROWS][COLS], int x, int y);



//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
////��
//#define EASY_ROW 9
//#define EASY_COL 9
//#define EASY_COUNT 15
//
////�м�
//#define MID_ROW 15
//#define MID_COL 15
//#define MID_COUNT 30
//
////����
//#define DIF_ROW 21
//#define DIF_COL 21
//#define DIF_COUNT 40
//
////��
//#define EASY_ROWS EASY_ROW+2
//#define EASY_COLS EASY_COL+2
////�м�
//#define MID_ROWS MID_ROW+2
//#define MID_COLS MID_COL+2
////����
//#define DIF_ROWS DIF_ROW+2
//#define DIF_COLS DIF_COL+2
//
////��ʼ������
//extern void InitBoard(char board[DIF_ROWS][DIF_COLS], int rows, int cols, char ch);
////��ӡ����
//extern void DisPlayBoard(char board[DIF_ROWS][DIF_COLS], int row, int col);
////�����
//extern void SetMine(char mine[DIF_ROWS][DIF_COLS], int row, int col, int cnt);
////�Ų���
//extern void FindMine(char mine[DIF_ROWS][DIF_COLS], char show[DIF_ROWS][DIF_COLS], int row, int col, int cnt, int visted[DIF_ROWS][DIF_COLS]);
//extern int MineCount(char mine[DIF_ROWS][DIF_COLS], int x, int y);
//extern void Expend(char mine[DIF_ROWS][DIF_COLS], char show[DIF_ROWS][DIF_COLS], int x, int y, int visted[DIF_ROWS][DIF_COLS]);
