#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int dp[101] = { 0 };
	for (int i = 1; i <= 100; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i - 10 >= 0) dp[i] = min(dp[i], dp[i - 10] + 1);
		if (i - 25 >= 0) dp[i] = min(dp[i], dp[i - 25] + 1);
	}

	while (t--) {
		long long cost;
		cin >> cost;

		int cnt = 0;
		while (cost > 0) {
			cnt += dp[cost % 100];
			cost /= 100;
		}

		cout << cnt << '\n';
	}

	return 0;
}