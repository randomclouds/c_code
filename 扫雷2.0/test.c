#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include "game.h"

void menu() {
	printf("***************************\n");
	printf("***********1.play**********\n");
	printf("***********0.exit**********\n");
	printf("***************************\n");
}

void game() {
	//��������
	char mineboard[ROWS][COLS] = { 0 };
	char showboard[ROWS][COLS] = { 0 };
	//��ʼ��
	set(mineboard, ROWS, COLS, '0');
	set(showboard, ROWS, COLS, '*');
	//������,��������Լ������ 1 ����,�����׵ļ���
	boom(mineboard, ROW, COL);
	//��ӡ
	print(mineboard, ROW, COL);
	print(showboard, ROW, COL);
	//��ʼ��Ϸ
	find(mineboard, showboard, ROW, COL);


}

int main() {
	int i = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("������������������һ��:>");
		scanf("%d", &i);
		switch (i) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("�Ƿ�����\n");
			break;
		}
	} while (i);
	return 0;
}