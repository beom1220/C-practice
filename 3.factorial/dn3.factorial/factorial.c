#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int facCal(int a);

int main(void)
{
	int getNum = 1;
	for (getNum; getNum != 0;)
	{
		printf("���丮�� �����Դϴ�. ���丮���� ����ϰ� ���� 50 ������ ���ڸ� �Է��ϼ���. (����� 0 �Է�) : ");
		scanf("%d", &getNum);
		if (getNum < 0)
		{
			getNum = 0;
		}
		facCal(getNum);
	}
}

int facCal(a)
{
	int result = 1;
	for (int i = 1; i <= a; i++)
	{
		result *= i;
	}
	if (a != 0)
		printf("��� : %d\n\n", result);
}

// �ϴ� ������ ���ڰ� Ŀ���� ������ (12������ ���������� ����) -> ǥ�� ������ ������ ����� -> �װ� ���� ��ġ�°�.
// 12! = 479,001,600 (4�� 7900�� ����) / 13! = 6,227,020,800 (62�� 2700�� ����) / int ������ 2,147,483,647 (21�� 4700�� ����)
// Ȯ���� ���� ������ int ������ �����. �ٵ� �� long�̳� long long, unsigned long long Ÿ������ �ٲ㵵 �� �Ǵ°�.
// �ƾƾƤ����� �ֳİ� ��.