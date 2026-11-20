#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char arr[2];
	double sum = 0;
	scanf("%s", arr);
	
	if (arr[1] == '+') {
		sum += 0.3;
	}
	else if (arr[1] == '-') {
		sum -= 0.3;
	}
	if (arr[0] == 'A') {
		sum += 4;
	}
	else if (arr[0] == 'B') {
		sum += 3;
	}
	else if (arr[0] == 'C') {
		sum += 2;
	}
	else if (arr[0] == 'D') {
		sum += 1;
	}
	else {
		sum = 0;
	}

	printf("%.1f", sum);

	return 0;
}