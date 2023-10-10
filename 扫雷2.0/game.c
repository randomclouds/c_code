#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include "game.h"


//初始化
void set(char board[ROWS][COLS], int rows, int cols, char str) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = str;
		}
	}
}

//打印
void print(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("------------扫雷游戏------------\n");
	for (i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------\n");
}

//布置炸弹
void boom(char board[ROWS][COLS], int row, int col) {
	int booms = EASY;
	while (booms) {
		//利用时间来进行随机的布雷
		int i = rand() % 9 + 1;
		int j = rand() % 9 + 1;
		if (board[i][j] != '1') {
			board[i][j] = '1';
			booms--;
		}
	}
}
//计算
char cal(char mineboard[ROWS][COLS], int x, int y) {
	return mineboard[x - 1][y - 1] + mineboard[x - 1][y] + mineboard[x - 1][y + 1] +
		mineboard[x][y - 1] + mineboard[x][y + 1] + mineboard[x + 1][y - 1] +
		mineboard[x + 1][y] + mineboard[x + 1][y + 1] - 7 * '0';
}

//游戏主体
void find(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = ROW * COL - EASY;
	int* w = &win;

	//执行
	int flag = 1;
	int i = 0;
	int j = 0;
	while (win) {
		printf("输入坐标:");
		scanf("%d %d", &x, &y);
		//限制玩家取点的范围
		if (x <= row && x >= 1 && y <= col && y >= 1) {
			if (showboard[x][y] == '*') {
				if (mineboard[x][y] == '1') {
					printf("你输了\n");
					print(mineboard, ROW, COL);
					break;
				}
				else {
					showall(mineboard, showboard, x, y, w);
					print(showboard, ROW, COL);
				}
			}
			else {
				printf("坐标非法\n");
			}
		}
	}
	if (win == 0) {
		print(mineboard, ROW, COL);
		printf("恭喜胜利,感谢游玩:>\n");
	}
}

//这是一个拓展的功能
void showall(char mineboard[ROWS][COLS],char showboard[ROWS][COLS], int x, int y, int* w) {
	int i = 0;
	int j = 0;
	
	if (showboard[x][y] == '*') {
		showboard[x][y] = cal(mineboard, x, y);
		(*w)--;
		if (showboard[x][y] == '0') {
			for (i = -1; i <=1; i++){
				for (j = -1; j <= 1; j++) {
					//保证拓展的功能不会在打印的范围以外发生
					if (x + i >= 1 && x + i <= 9 && y + j >= 1 && y + j <= 9) {
						showall(mineboard, showboard, x + i, y + j, w);
					}
				}
			}
		}
	}
	
}