#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct info {
	int k;
	int s;
}info;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;
	cin >> n >> t;

	vector<info> chapters(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> chapters[i].k >> chapters[i].s;
	}

	vector<vector<int>>dp(n + 1, vector<int>(t + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			if (j < chapters[i].k) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - chapters[i].k] + chapters[i].s);
			}
		}
	}

	cout << dp[n][t];

	return 0;
}