#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, sugar = 0;

	scanf("%d", &n);

	while (1) {
		if (n % 5 == 0) {
			sugar += n / 5;
			printf("%d", sugar);
            break;
		}

		n -= 3;
		sugar++;
		
		if (n < 0) {
			printf("-1");
			break;
		}
	}

	return 0;
}