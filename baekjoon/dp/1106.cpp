// 문제: https://www.acmicpc.net/problem/1106
// 제목: 호텔

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
	int c, n;

	cin >> c >> n;
	vector<pair<int, int>> city(n);

	for (int i = 0; i < n; ++i) {
		cin >> city[i].first >> city[i].second;
	}

	vector<int> dp(c + 101, INF);
	dp[0] = 0;

	for (int i = 1; i <= c + 100; i++) {
		for (int j = 0; j < n; j++) {
			int cost = city[j].first;
			int people = city[j].second;

			if (i >= people && dp[i - people] != INF) {
				dp[i] = min(dp[i], dp[i - people] + cost);
			}
		}
	}

	int result = INF;
	for (int i = c; i <= c + 100; i++) {
		result = min(result, dp[i]);
	}

	cout << result << '\n';

	return 0;
}