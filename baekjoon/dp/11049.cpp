// 巩力 : https://www.acmicpc.net/problem/11049
// 力格 : 青纺 蚌祭 鉴辑

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

typedef struct Matrix {
	int n;
	int m;
}Matrix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Matrix>matrix(n);
	for (int i = 0; i < n; i++) {
		cin >> matrix[i].n >> matrix[i].m;
	}

	vector<vector<int>>dp(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int len = 2; len <= n; len++) {
		for (int start = 0; start <= n - len; start++) {
			int end = start + len - 1;

			for (int k = start; k < end; k++) {
				int cost = dp[start][k] + dp[k + 1][end] + (matrix[start].n * matrix[k].m * matrix[end].m);

				dp[start][end] = min(cost, dp[start][end]);
			}
		}
	}

	cout << dp[0][n - 1];

	return 0;
}