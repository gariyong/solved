#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int n;
	int arr[30];

	for (int i = 1; i <= 30; i++) {
		arr[i - 1] = i;
	}

	for (int j = 0; j < 28; j++) {
		scanf("%d", &n);
		
		for (int k = 0; k < 30; k++) {
			if (n == arr[k]) {
				arr[k] = 0;
			}
		}
	}
	
	for (int l = 0; l < 30; l++) {
		if (arr[l] != 0) {
			printf("%d\n", arr[l]);
		}
	}
}
