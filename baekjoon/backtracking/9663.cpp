#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void backtrack(int n, int row, vector<int>& col, int& result) {
	if (row == n) {
		result++;
		return;
	}

	for (int i = 0; i < n; i++) {
		bool safe = true;

		for (int prev = 0; prev < row; prev++) {
			if (col[prev] == i || (int)abs(col[prev] - i) == row - prev) {
				safe = false;
				break;
			}
		}

		if (safe) {
			col[row] = i;
			backtrack(n, row + 1, col, result);
		}
	}
}

int main() {
	int n;
	int result = 0;

	cin >> n;
	vector<int> col(n, -1);

	backtrack(n, 0, col, result);

	cout << result;

	return 0;
}