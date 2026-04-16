#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

const int INF = 1e9;

void dijkstra(vector<vector<pair<int, int>>>& nodes, vector<vector<int>>& path, int start, int n) {
	vector<int> dist(n + 1, INF);
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>	q;
	q.push({ 0, start });

	while (!q.empty()) {
		auto [cost, cur] = q.top();
		q.pop();

		if (cost > dist[cur]) continue;

		for (auto [next, n_cost] : nodes[cur]) {

			if (dist[cur] + n_cost < dist[next]) {
				dist[next] = dist[cur] + n_cost;
				q.push({ dist[next], next });

				if (cur == start) {
					path[start][next] = next;
				}
				else {
					path[start][next] = path[start][cur];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int,int>>>nodes(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		nodes[u].push_back({ v, w });
		nodes[v].push_back({ u, w });
	}

	vector<vector<int>> path(n + 1, vector<int>(n + 1));
	for (int start = 1; start <= n; start++) {
		dijkstra(nodes, path, start, n);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << '-';
			}
			else {
				cout << path[i][j];
			}

			if (j < n) {
				cout << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}