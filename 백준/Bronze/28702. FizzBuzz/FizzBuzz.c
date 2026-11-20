#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char arr[3][9];
	int n;
	int num;

	for (int i = 3; i >= 1; i--) {
		scanf("\n%s", &arr[3-i]);
		if (arr[3-i][0] > '0' && arr[3-i][0] <= '9') {
			n = i;
		}
	}
	num = atoi(arr[3 - n]) + n;

	if (num % 3 == 0 && num % 5 == 0) {
		printf("FizzBuzz");
	}
	else if (num % 3 == 0) {
		printf("Fizz");
	}
	else if (num % 5 == 0) {
		printf("Buzz");
	}
	else {
		printf("%d", num);
	}

	return 0;
}