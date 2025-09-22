// 문제 : https://www.acmicpc.net/problem/2342
// 제목 : Dance Dance Revolution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int moves(int pos, int next) {
	if (pos == next) return 1;
	if (pos == 0) return 2;
	if (abs(pos - next) == 2) return 4;
	return 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> direction;
	int x;
	while (cin >> x && x != 0) {
		direction.push_back(x);
	}

	vector<vector<int>> dp(5, vector<int>(5, INF));
	dp[0][0] = 0;
	for (int next : direction) {
		vector<vector<int>> next_dp(5, vector<int>(5, INF));

		for (int l = 0; l < 5; l++) {
			for (int r = 0; r < 5; r++) {
				if (dp[l][r] == INF) continue;

				if (next != r) {
					next_dp[next][r] = min(next_dp[next][r], dp[l][r] + moves(l, next));
				}

				if (next != l) {
					next_dp[l][next] = min(next_dp[l][next], dp[l][r] + moves(r, next));
				}
			}
		}

		dp.swap(next_dp);
	}

	int res = INF;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			res = min(res, dp[i][j]);
		}
	}

	cout << res;

	return 0;
}