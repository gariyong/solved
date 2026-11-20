#include <iostream>

using namespace std;

int dp[1025][1025] = { {0} };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dp[i][j];
			dp[i][j] += dp[i][j - 1];
		}
	}

	while (m--) {
		int x1, x2, y1, y2;
		int sum = 0;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int nx = 0; nx <= x2 - x1; nx++) {
			sum += dp[x1 + nx][y2] - dp[x1 + nx][y1 - 1];
		}

		cout << sum << '\n';
	}

	return 0;
}