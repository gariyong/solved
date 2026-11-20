#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main()
{
	char arr[101];

	scanf("%s", &arr);
	
	int len = strlen(arr);
	int check =1;

	for (int i = 0; i < len / 2; i++) {
		if (arr[i] != arr[len - i-1]) {
			check = 0;
			break;
		}
	}
	if (check == 0) {
		printf("%d", check);
	}
	else {
		printf("%d", check);
	}

	return 0;
}
