#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	while (1) {
		char num[6] = { NULL };
		scanf("\n%s", num);
		if (num[0] == '0') {
			break;
		}
		int len = strlen(num), flag = 1;
		for (int i = 0; i < len / 2; i++) {
			if (num[i] != num[len - 1 - i]) {
				flag = 0;
			}
		}
		if (flag == 1) {
			printf("yes\n");
		}
		else if (flag == 0) {
			printf("no\n");
		}
	}

	return 0;
}