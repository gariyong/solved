#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int  num, k, count = 0;

	scanf("%d %d", &num, &k);

	for (int i = 1; i <= 10000; i++) {
		if (num % i == 0) {
			count++;
			if (count == k) {
				printf("%d", i);
				
				break;
			}
		}
	}
	if (count != k) {
		printf("0");
	}

	return 0;
}
