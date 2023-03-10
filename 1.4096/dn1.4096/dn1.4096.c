#include <stdio.h>

int main(void)
{
	for (int c = 0; c < 8; c++) {
		for (int b = 0; b < 8; b++) {
			for (int a = 0; a < 8; a++) {
				for (int i = 1; i <= 8; i++) {
					printf("%4d ", i + 64 * a + 8 * b + 512 * c);
				} printf("|");
			}printf("\n");
		}printf("\n\n");
	}
}