#include<iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

pair<vector<int>, vector<int>> dijkstra(vector<vector<pair<int, int>>>& nodes, int n, int start, int block_u = -1, int block_v = -1) {
	vector<int> dist(n + 1, INF);
	vector<int> parent(n + 1, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	
	q.push({ 0, start });
	dist[start] = 0;
	while (!q.empty()) {
		auto [cost, cur] = q.top();
		q.pop();

		if (cost > dist[cur]) continue;

		for (auto [w, next] : nodes[cur]) {
			if (cur == block_u && next == block_v || cur == block_v && next == block_u) continue;

			if (dist[next] > cost + w) {
				dist[next] = cost + w;
				parent[next] = cur;
				q.push({ dist[next], next });
			}
		}
	}

	return { dist, parent };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>>nodes(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		nodes[u].push_back({ w, v });
		nodes[v].push_back({ w, u });
	}

	auto [dist, parent] = dijkstra(nodes, n, 1);

	if (dist[n] == INF) {
		cout << -1;

		return 0;
	}

	int origin = dist[n];

	vector<pair<int, int>> path;
	int cur = n;
	while (parent[cur] != -1) {
		path.push_back({ cur, parent[cur] });
		cur = parent[cur];
	}

	int result = 0;
	bool flag = false;

	for (auto [u, v] : path) {
		auto [dist2, _] = dijkstra(nodes, n, 1, u, v);

		if (dist2[n] == INF) {
			flag = true;
			break;
		}
		
		result = max(result, dist2[n] - origin);
	}

	if (flag) {
		cout << -1;
	}
	else {
		cout << result;
	}

	return 0;
}