#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY 1

//初始化
void set(char board[ROWS][COLS], int rows, int cols, char str);

//布雷
void boom(char board[ROWS][COLS], int row, int col);

//扫雷
void find(char mineboard[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//打印
void print(char board[ROWS][COLS], int row, int col);

//扩展
void showall(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int x, int y, int* w);