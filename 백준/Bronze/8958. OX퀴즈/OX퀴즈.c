	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>
	#include <stdio.h>

	int main() {
		int test_case;

		scanf("%d", &test_case);

		while (test_case) {
			char arr[80];
			scanf("%s", arr);
			int len = strlen(arr), n = 0, score = 0;

			for (int i = 0; i < len; i++) {
				if (arr[i] == 'O') {
					n++;
					score += n;
				}
				else if (arr[i] == 'X') {
					n = 0;
				}
			}
			printf("%d\n", score);
			test_case--;
		}

		return 0;
	}