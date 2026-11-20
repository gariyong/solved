	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>


	int main()
	{
		char arr[100];

		scanf("%s", &arr);
		int len = 0;

		while (arr[len] != '\0') {
			len++;
		}

		printf("%d", len);
	}

