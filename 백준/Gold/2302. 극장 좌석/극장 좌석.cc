#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int m;
	cin >> m;
	
	vector<int> vip(m);
	for (int i = 0; i < m; i++) {
		cin >> vip[i];
	}

	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int prev = 0;
	int result = 1;

	for (int i = 0; i < m; i++) {
		int len = vip[i] - prev - 1;
		result *= dp[len];
		prev = vip[i];
	}
	result *= dp[n - prev];

	cout << result;

	return 0;
}