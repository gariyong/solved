#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int dp[50001];
	int n;

	cin >> n;

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];

	return 0;
}