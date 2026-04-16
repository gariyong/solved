#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int>coins(n);
	for(int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	vector<int>dp(k + 1, MAX);
	dp[0] = 0;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coins[j] >= 0) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}

	if(dp[k] == MAX) {
		cout << -1;
	} else {
		cout << dp[k];
	}

	return 0;
}