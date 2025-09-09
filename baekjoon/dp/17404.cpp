// 문제 : https://www.acmicpc.net/problem/17404
// 제목 : RGB거리 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> cost(n + 1, vector<int>(3));
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	int answer = INF;

	// 이전 집의 색과 현재 집의 색을 비교하는 부분을 구현하는 부분에 어려움이 있었음
	// dp가 이전 값을 이용해서 현재 값을 구하는 점화식이므로, 이전 집의 색과 현재 집의 색이 다를 때만 비용을 더하도록 구현 << 이 부분을 잘 생각해내야 했음
	for (int start_color = 0; start_color < 3; ++start_color) {
		vector<vector<int>> dp(n + 1, vector<int>(3, INF));

		dp[1][start_color] = cost[1][start_color];
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				for (int prev_color = 0; prev_color < 3; ++prev_color) {
					if (j != prev_color) {
						dp[i][j] = min(dp[i][j], dp[i - 1][prev_color] + cost[i][j]);
					}
				}
			}
		}

		for (int end_color = 0; end_color < 3; end_color++) {
			if (end_color != start_color) {
				answer = min(answer, dp[n][end_color]);
			}
		}
	}

	cout << answer;

	return 0;
}