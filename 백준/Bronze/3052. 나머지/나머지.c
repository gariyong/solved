#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int arr[10];
	int result = 0;
	
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
		arr[i] %= 42;
	}

	for (int j = 0; j < 10; j++) {
		int count = 0;
		for (int k = j + 1; k < 10; k++) {
			if (arr[j] == arr[k]) {
				count++;
			}
		}
		if (count == 0) {
			result++;
		}
	}

	printf("%d", result);

	return 0;
}
