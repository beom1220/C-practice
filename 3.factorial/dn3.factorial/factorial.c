#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int facCal(int);
int printCheck(int);
int printStart(int);
int facArray[100][100];

int main(void)
{
	int getNum = 1;
	for (getNum; getNum != 0;)
	{
		printf("���丮�� �����Դϴ�. ���丮���� ����ϰ� ���� 50 ������ ���ڸ� �Է��ϼ���. (����� 0 �Է�) : ");
		scanf("%d", &getNum);
		if (getNum <= 0)
		{
			getNum = 0;
		}
		else {
			facCal(getNum);
		}
	}
}

int facCal(k)
{
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= 98; j++) {
			facArray[0][1] = 1;
			facArray[i][j] = facArray[(i - 1)][j] * i;
		}
		for (int j = 1; j < 99; j++) {
			int hNum = facArray[i][j] / 100;
			facArray[i][j] -= hNum * 100;
			int tNum = facArray[i][j] / 10;
			facArray[i][j] -= tNum * 10;
			facArray[i][j + 1] += tNum;
			facArray[i][j + 2] += hNum;
		}
	} printCheck(k);
}

printCheck(k) {
	for (int j = 100; j >= 1; j--) {
		if (facArray[k][j] != 0) {
			printStart(k, j);
			j = 0;
		}
	}
}

printStart(k, j) {
	printf("��� ����� ");
	for (j; j >= 1; j--) {
		printf("%d", facArray[k][j]);
	}
	printf("�Դϴ�.\n\n");
}