#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, k;
	int coin_price[10] = { 0 };
	int coin_count = 0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin_price[i]);
	}

	while (k > 0) {
		if (k / coin_price[n - 1] != 0) {
			int count = k / coin_price[n - 1];

			k -= coin_price[n - 1] * count;
			coin_count += count;
		}
		n--;
	}

	printf("%d", coin_count);

	return 0;
}