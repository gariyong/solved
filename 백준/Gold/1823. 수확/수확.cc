#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> rice_plant(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> rice_plant[i];
	}

	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

	for(int i = 1; i <= n; i++) {
		dp[i][i] = n * rice_plant[i];
	}

	for (int len = 2; len <= n; len++) {
		for (int l = 1; l <= n - len + 1; l++) {
			int r = l + len - 1;
			int day = n - len + 1;

			dp[l][r] = max(dp[l + 1][r] + day * rice_plant[l], dp[l][r - 1] + day * rice_plant[r]);
		}
	}

	cout << dp[1][n];

	return 0;
}