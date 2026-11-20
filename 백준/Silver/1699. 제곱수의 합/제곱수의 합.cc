#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
	vector<int> dp(100001, INF);
	int n;
	
	cin >> n;

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = (int)min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];

	return 0;
}