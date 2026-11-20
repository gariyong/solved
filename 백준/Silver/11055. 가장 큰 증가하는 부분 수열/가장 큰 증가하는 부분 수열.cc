#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int* num;
	int* dp;

	cin >> n;
	num = new int[n + 1];
	dp = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		dp[i] = num[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[i], dp[j] + num[i]);
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = max(dp[i], sum);
	}

	cout << sum;

	delete[] dp;
	delete[] num;

	return 0;
}