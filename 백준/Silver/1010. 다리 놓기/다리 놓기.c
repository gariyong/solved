#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main()
{
	int n;
	int east, west;

	scanf("%d", &n);

	while (n) {
		int brige = 1;
		scanf("%d %d", &west, &east);
		for (int i = 0; i < west; i++) {
			brige *= east - i;
			brige /= i + 1;
		}
		printf("%d\n", brige);
		n--;
	}

	return 0;
}