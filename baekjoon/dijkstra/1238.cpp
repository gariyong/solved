#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>
#include <functional>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(vector<vector<int>>& graph, vector<int>& distance, int start, int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	distance[start] = 0;

	q.push({ 0, start });

	while (!q.empty()) {
		auto [cost, cur] = q.top();
		q.pop();

		if (cost > distance[cur]) {
			continue;
		}

		for (int i = 1; i <= n; i++) {
			if (graph[cur][i] != 0) {
				int n_cost = cost + graph[cur][i];

				if (n_cost < distance[i]) {
					distance[i] = n_cost;
					q.push({ n_cost, i });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, x;
	int result = -1;
	cin >> n >> m >> x;
	vector<vector<int>>graph(n + 1, vector<int>(n + 1, 0));
	vector<int>start_distance(n + 1, INF);
	vector<int>end_distance(n + 1, INF);

	for (int i = 0; i < m; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		graph[u][v] = w;
	}

	dijkstra(graph, end_distance, x, n);
	for (int i = 1; i <= n; i++) {
		dijkstra(graph, start_distance, i, n);
		result = max(result, start_distance[x] + end_distance[i]);
		start_distance.assign(n + 1, INF);
	}

	cout << result;

	return 0;
}