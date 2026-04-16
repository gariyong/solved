#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& cost, int n) {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (cost[i][k] < INF && cost[k][j] < INF) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; ++i) {
		cost[i][i] = 0;
	}
	
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		cost[u][v] = min(cost[u][v], w);
	}

	floydWarshall(cost, n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (cost[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << cost[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}