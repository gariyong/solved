	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

int count_len(char*);

	int main()
	{
		int n;
		char arr[1000];

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%s", &arr);
			int len = count_len(arr);

			printf("%c%c\n", arr[0], arr[len - 1]);
		}
	}

	int count_len(char* arr)
	{
		int len = 0;
		while (arr[len] != '\0') {
			len++;
		}

		return len;
	}

