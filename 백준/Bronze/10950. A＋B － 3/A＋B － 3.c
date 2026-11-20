#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int count;
	int n1, n2;

	scanf("%d", &count);

	for (int i = count; i > 0; i--) {
		scanf("%d %d", &n1, &n2);
		printf("%d\n", n1 + n2);
	}
}
