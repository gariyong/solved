	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

	int main() {
		int arr[8];
		int flag = 0;
		
		for (int i = 0; i < 8; i++) {
			scanf("%d", &arr[i]);
		}
		if (arr[0] == 1) {
			for (int i = 0; i < 8; i++) {
				if(arr[i] != i+1){
					flag++;
					break;
				}
			}
			if (flag == 1) {
				printf("mixed");
			}
			else {
				printf("ascending");
			}
		}
		else if (arr[0] == 8) {
			for (int i = 0; i < 8; i++) {
				if (arr[i] != 8 - i) {
					flag++;
					break;
				}
			}
			if (flag == 1) {
				printf("mixed");
			}
			else {
				printf("descending");
			}
		}
		else {
			printf("mixed");
		}

		return 0;
	}