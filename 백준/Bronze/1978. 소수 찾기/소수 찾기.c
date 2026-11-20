#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, num, count = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int check = -1;

		scanf("%d", &num);
		
		for (int j = 1; j < num; j++) {
			if (j != 1 && num % j == 0) {
				check = 0;
				break;
			}
			check = 1;
		}

		if (check == 1) {
			count++;
		}
	}

	printf("%d", count);

	return 0;
}
