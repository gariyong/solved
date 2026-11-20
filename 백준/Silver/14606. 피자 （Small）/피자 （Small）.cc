#include <iostream>
#include <cmath>

using namespace std;

int dp[11];

int main() {
	int n;

	cin >> n;

	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= 10; i++) {
		if (i % 2 == 0) {
			dp[i] = (int)pow(i / 2, 2) + (dp[i / 2] * 2);
		}
		else {
			dp[i] = (i / 2) * (i / 2 + 1) + (dp[i / 2] + dp[i / 2 + 1]);
		}
	}

	cout << dp[n];

	return 0;
}