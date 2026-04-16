#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct application {
	int m;
	int c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<application> app(n);
	for (int i = 0; i < n; i++) {
		cin >> app[i].m;
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;

		sum += c;
		app[i].c = c;
	}

	vector<int> dp(sum + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int cost = sum; cost >= app[i].c; cost--) {
			dp[cost] = max(dp[cost], dp[cost - app[i].c] + app[i].m);
		}
	}

	int result = -1;
	for (int cost = 0; cost <= sum; cost++) {
		if (dp[cost] >= m) {
			result = cost;
			break;
		}
	}

	cout << result;

	return 0;
}