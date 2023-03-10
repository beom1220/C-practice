#include <stdio.h>

void evenStar(int);
void oddStar(int);

int main(void)
{
	int num;
	do {
		printf("정수를 입력해주세요. : ");
		scanf_s("%d", &num);
		printf("\n");
	} while (num <= 0);

	if (num % 2 == 0) {
		evenStar(num);
	}
	else {
		oddStar(num);
	}
}

void evenStar(num) {
	for (int i = 2; i <= num; i += 2) {
		for (int j = 0; j < (num - i)/2; j++) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = num-2; i >= 2; i -= 2) {
		for (int j = 0; j < (num - i)/2; j++) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
	}
}

void oddStar(num) {
	for (int i = 1; i <= num; i += 2) {
		for (int j = 0; j < (num - i)/2; j++) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = num-2; i >= 1; i -= 2) {
		for (int j = 0; j < (num - i)/2; j++) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
	}
}