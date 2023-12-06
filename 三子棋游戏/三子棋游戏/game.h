#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

void INBOARD(char board[ROW][COL], int row, int col);
void PUTBOARD(char board[ROW][COL], int row, int col);

void PLAYER(char board[ROW][COL], int row, int col);
void COMPUTER(char board[ROW][COL], int row, int col);
char WIN(char board[ROW][COL], int row, int col);