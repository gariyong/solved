#include <iostream>

using namespace std;

int main() {
	int num[10001];

	for (int i = 1; i < 10001; i++) {
		num[i] = i;
	}
	for (int i = 1; i < 10001; i++) {
		int create = i;
		int n = i;

		while (n) {
			create += n % 10;
			n /= 10;
		}
		if (create <= 10000) {
			num[create] = 0;
		}
	}

	for (int i = 1; i < 10001; i++) {
		if (num[i] != 0) {
			cout << num[i] << '\n';
		}
	}

	return 0;
}