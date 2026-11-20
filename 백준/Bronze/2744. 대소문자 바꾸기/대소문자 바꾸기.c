#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char arr[101];

	scanf("%s", arr);

	int len = strlen(arr);

	for (int i = 0; i < len; i++) {
		if ('a' <= arr[i] && arr[i] <= 'z') {
			arr[i] -= ('a' - 'A');
		}
		else if ('A' <= arr[i] && arr[i] <= 'Z') {
			arr[i] += ('a' - 'A');
		}
	}

	printf("%s", arr);

	return 0;
}