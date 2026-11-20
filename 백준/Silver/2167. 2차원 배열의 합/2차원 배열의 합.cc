#include <iostream>

using namespace std;

int main() {
	int n, m, k, i, j, x, y;
	int** arr;
	
	cin >> n >> m;
	arr = new int* [n];
	for (i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> k;
	for (; k > 0; k--) {
		int sum = 0;
		cin >> i >> j >> x >> y;
		for (; i <= x; i++) {
			for (int J = j; J <= y; J++) {
				sum += arr[i - 1][J - 1];
			}
		}
		cout << sum << '\n';
	}

	return 0;
}