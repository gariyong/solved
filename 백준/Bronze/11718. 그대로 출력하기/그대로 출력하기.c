#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char word;

	while (scanf("%c", &word) != -1) {
		printf("%c", word);
	}

	return 0;
}
