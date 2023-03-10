#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int facCal(int a);

int main(void)
{
	int getNum = 1;
	for (getNum; getNum != 0;)
	{
		printf("팩토리얼 계산기입니다. 팩토리얼을 계산하고 싶은 50 이하의 숫자를 입력하세요. (종료는 0 입력) : ");
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
		printf("결과 : %d\n\n", result);
}

// 일단 문제는 숫자가 커지면 터진다 (12까지만 정상적으로 나옴) -> 표현 가능한 범위를 벗어났다 -> 그걸 어케 고치는가.
// 12! = 479,001,600 (4억 7900만 가량) / 13! = 6,227,020,800 (62억 2700만 가량) / int 범위는 2,147,483,647 (21억 4700만 가량)
// 확실히 터진 이유는 int 범위를 벗어나서. 근데 왜 long이나 long long, unsigned long long 타입으로 바꿔도 안 되는가.
// 아아아ㅏㅏㅏ 왜냐고 왜.