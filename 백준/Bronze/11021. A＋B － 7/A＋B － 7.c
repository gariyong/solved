	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

	int main()
	{
		int count;
		int n1, n2;

		scanf("%d", &count);

		for (int i = 1; i <= count; i++) {
			scanf("%d %d", &n1, &n2);
			printf("Case #%d: %d\n", i, (n1 + n2));
		}

		return 0;
	}
