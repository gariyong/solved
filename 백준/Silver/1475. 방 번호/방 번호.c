#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char room_num[8];
	int number[9] = { 0 };
	int set = 0;

	scanf("%[^\n]", &room_num);

	for (int i = 0; i < strlen(room_num); i++) {
		if (room_num[i] - '0' == 9) {
			number[6]++;
		}
		else {
			number[room_num[i] - '0']++;
		}
	}
	
	if (number[6] % 2 == 0) {
		number[6] /= 2;
	}
	else if (number[6] % 2 == 1) {
		number[6] = number[6] / 2 + 1;
	}

	for (int i = 0; i < 9; i++) {
		if (set < number[i]) {
			set = number[i];
		}
	}

	printf("%d", set);

	return 0;
}