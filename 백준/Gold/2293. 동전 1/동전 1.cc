#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int>coin(n + 1);
	for (int i = 1; i <= n; i++) cin >> coin[i];

	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		int w = coin[i];

		for (int j = w; j <= k; j++) {
			dp[j] += dp[j - w];
		}
	}

	cout << dp[k];

	return 0;
}