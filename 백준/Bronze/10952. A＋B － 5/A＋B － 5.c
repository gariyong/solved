	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

int main()
{
	int n1, n2;

	scanf("%d %d", &n1, &n2);
	
	while (n1 != 0 || n2 != 0) {
		printf("%d\n", n1 + n2);
		scanf("%d %d", &n1, &n2);
	}

	return 0;
}
