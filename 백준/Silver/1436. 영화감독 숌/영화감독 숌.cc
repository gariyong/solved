#include <iostream>

using namespace std;

int main() {
	int n, i;
	int count = 0;

	cin >> n;

	for (i = 666; count < n; i++) {
		int tmp = i;
		while (tmp != 0) {
			if (tmp % 1000 == 666) {
				count++;
				break;
			}
			tmp /= 10;
		}
	}

	cout << i - 1;

	return 0;
}