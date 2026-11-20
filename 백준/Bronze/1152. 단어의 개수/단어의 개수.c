#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char arr[1000000];
	int count = 0;

	scanf("%[^\n]s", &arr);

	int len = strlen(arr);

	for (int i = 0; i < len; i++) {
		if (arr[i] == ' ') {
			if (i != 0 && i != len - 1) {
				count++;
			}
			if (len == 1) {
				count -= 1;
			}
		}
	}

	printf("%d", count + 1);

	return 0;
}