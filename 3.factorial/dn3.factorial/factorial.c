#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int facCal(unsigned long long a);

int main(void)
{
	unsigned long long getNum = 1uLL;
	for (getNum; getNum != 0uLL;)
	{
		printf("���丮�� �����Դϴ�. ���丮���� ����ϰ� ���� 50 ������ ���ڸ� �Է��ϼ���. (����� 0 �Է�) : ");
		scanf("%d", &getNum);
		facCal(getNum);
	}
}

int facCal(a)
{
	unsigned long long result = 1uLL;
	for (unsigned long long i = 1uLL; i <= a; i++)
	{
		result *= i;
	}
	if (a != 0uLL)
		printf("��� : %50d\n\n", result);
}