#include <iostream>
#include <vector>
#include <algorithm>

typedef struct object {
	int w;
	int v;
}object;

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<object>objects(n);
	for (int i = 0; i < n; i++) {
		cin >> objects[i].w >> objects[i].v;
	}

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - objects[i - 1].w >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - objects[i - 1].w] + objects[i - 1].v);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];

	return 0;
}