#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, k, flag = 0, cnt = 0;

	scanf("%d %d", &n, &k);
	int* num = (int*)calloc(n, sizeof(int));

	printf("<");
	while (flag != n)
	{
		int i;
		for (i = 0; i < n; i++ ) {
			if (num[i] == 0) {
				cnt++;
				if (cnt == k && flag == n - 1) {
					printf("%d", i + 1);
					flag++;
				}
				else if (cnt == k) {
					printf("%d, ", i + 1);
					num[i] = 1;
					cnt = 0;
					flag++;
				}
			}
		}
		
	}
	printf(">");
	free(num);

	return 0;
}