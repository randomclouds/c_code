#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include "game.h"


//��ʼ��
void set(char board[ROWS][COLS], int rows, int cols, char str) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = str;
		}
	}
}

//��ӡ
void print(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("------------ɨ����Ϸ------------\n");
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

//����ը��
void boom(char board[ROWS][COLS], int row, int col) {
	int booms = EASY;
	while (booms) {
		//����ʱ������������Ĳ���
		int i = rand() % 9 + 1;
		int j = rand() % 9 + 1;
		if (board[i][j] != '1') {
			board[i][j] = '1';
			booms--;
		}
	}
}
//����
char cal(char mineboard[ROWS][COLS], int x, int y) {
	return mineboard[x - 1][y - 1] + mineboard[x - 1][y] + mineboard[x - 1][y + 1] +
		mineboard[x][y - 1] + mineboard[x][y + 1] + mineboard[x + 1][y - 1] +
		mineboard[x + 1][y] + mineboard[x + 1][y + 1] - 7 * '0';
}

//��Ϸ����
void find(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = ROW * COL - EASY;
	int* w = &win;

	//ִ��
	int flag = 1;
	int i = 0;
	int j = 0;
	while (win) {
		printf("��������:");
		scanf("%d %d", &x, &y);
		//�������ȡ��ķ�Χ
		if (x <= row && x >= 1 && y <= col && y >= 1) {
			if (showboard[x][y] == '*') {
				if (mineboard[x][y] == '1') {
					printf("������\n");
					print(mineboard, ROW, COL);
					break;
				}
				else {
					showall(mineboard, showboard, x, y, w);
					print(showboard, ROW, COL);
				}
			}
			else {
				printf("����Ƿ�\n");
			}
		}
	}
	if (win == 0) {
		print(mineboard, ROW, COL);
		printf("��ϲʤ��,��л����:>\n");
	}
}

//����һ����չ�Ĺ���
void showall(char mineboard[ROWS][COLS],char showboard[ROWS][COLS], int x, int y, int* w) {
	int i = 0;
	int j = 0;
	
	if (showboard[x][y] == '*') {
		showboard[x][y] = cal(mineboard, x, y);
		(*w)--;
		if (showboard[x][y] == '0') {
			for (i = -1; i <=1; i++){
				for (j = -1; j <= 1; j++) {
					//��֤��չ�Ĺ��ܲ����ڴ�ӡ�ķ�Χ���ⷢ��
					if (x + i >= 1 && x + i <= 9 && y + j >= 1 && y + j <= 9) {
						showall(mineboard, showboard, x + i, y + j, w);
					}
				}
			}
		}
	}
	
}