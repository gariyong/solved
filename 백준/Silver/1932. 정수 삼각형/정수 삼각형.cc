#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int** dp;
	int** triangle;

	cin >> n;
	dp = new int* [n];
	triangle = new int* [n];

	for (int i = 0; i < n; i++) {
		triangle[i] = new int[i + 1];
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		dp[i] = new int[i + 1];
	}
	
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
	}


	int sum = -1;
	for (int i = 0; i < n; i++) {
		sum = max(sum, dp[n - 1][i]);
	}

	cout << sum;

	for (int i = 0; i < n; i++) {
		delete[] triangle[i];
		delete[] dp[i];
	}
	delete[] triangle;
	delete[] dp;

	return 0;
}