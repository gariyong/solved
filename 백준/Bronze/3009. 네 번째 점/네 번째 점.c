#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int diff_one(int*);

int main()
{
	int arr_x[3], arr_y[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &arr_x[i], &arr_y[i]);
	}
	int x = diff_one(arr_x);
	int y = diff_one(arr_y);

	printf("%d %d", x, y);

	return 0;
}

int diff_one(int* arr) {
	if (arr[0] == arr[1]) {
		return arr[2];
	}
	else if (arr[0] == arr[2]) {
		return arr[1];
	}
	else {
		return arr[0];
	}
}
