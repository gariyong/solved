#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num, n_10, n_1, n, count = 0;
	
	scanf("%d", &num);

	if (num / 10 == 0) {
		num *= 10;
		n = num;
	}
	else {
		n = num;
	}
	


	while (1) {
		n_10 = n / 10;
		n_1 = n % 10;
		n = n_1 * 10 + ((n_10 + n_1) % 10);
		count++;
		if (n == num) {
			printf("%d", count);
			break;
		}
	}

	return 0;
}

