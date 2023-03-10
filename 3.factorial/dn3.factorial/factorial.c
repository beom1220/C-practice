#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int facCal(unsigned long long a);

int main(void)
{
	unsigned long long getNum = 1uLL;
	for (getNum; getNum != 0uLL;)
	{
		printf("팩토리얼 계산기입니다. 팩토리얼을 계산하고 싶은 50 이하의 숫자를 입력하세요. (종료는 0 입력) : ");
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
		printf("결과 : %50d\n\n", result);
}