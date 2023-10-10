#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

void menu() {
	printf("********************************\n");
	printf("**********1.Add   2.Sub*********\n");
	printf("**********3.Mul   4.Div*********\n");
	printf("**********0.exit      **********\n");
	printf("********************************\n");

}

int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}

int mul(int x, int y) {
	return x * y;
}

int div(int x, int y) {
	return x / y;
}

void cal(int x, int y, int (*p) (int, int)) {
	printf("结果是%d\n", p(x, y));
}

int main() {
	//这是实现一个简单的计算器的程序
	int x = 0, y =0, i = 0;
	do {
		//打印选项
		menu();
		printf("请输入使用的功能\n");
		scanf("%d", &i);

		printf("输入两个数字\n");
		scanf("%d %d", &x, &y);
		switch (i) {
		case 1:
			cal(x, y, add);
			break;
		case 2:
			cal(x, y, sub);
			break;
		case 3:
			cal(x, y, mul);
			break;
		case 4:
			cal(x, y, div);
			break;
		case 0:
			break;
		default:
			printf("输入非法\n");
			break;
		}
	} while (i);

	return 0;
}