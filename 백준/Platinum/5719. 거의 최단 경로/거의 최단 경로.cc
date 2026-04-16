#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int n, int s, vector<vector<int>>& path) {
	vector<int> dist(n, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>	q;

	dist[s] = 0;
	q.push({ 0,	 s });
	while (!q.empty()) {
		auto [cost, cur] = q.top();
		q.pop();

		if (cost > dist[cur]) continue;

		for (auto [w, next] : graph[cur]) {
			if (cost + w < dist[next]) {
				dist[next] = cost + w;
				q.push({ dist[next], next });
				path[next].clear();
				path[next].push_back(cur);
			}
			else if (cost + w == dist[next]) {
				path[next].push_back(cur);
			}
		}
	}

	return dist;
}

void remove_path(vector<vector<pair<int, int>>>& graph, vector<vector<int>>& path, int s, int d) {
	queue<int> q;
	q.push(d);
	vector<bool> visited(graph.size(), false);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;

		for (int prev : path[cur]) {
			for (auto it = graph[prev].begin(); it != graph[prev].end(); ) {
				if (it->second == cur) {
					it = graph[prev].erase(it);
				}
				else {
					it++;
				}
			}
			if (!visited[prev]) q.push(prev);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) break;
		int s, d;
		cin >> s >> d;

		vector<vector<pair<int, int>>> graph(n);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;

			graph[u].push_back({ w, v });
		}

		vector<vector<int>> path(n);
		auto dist = dijkstra(graph, n, s, path);
		remove_path(graph, path, n, d);
		path.assign(n, {});
		dist = dijkstra(graph, n, s, path);

		if (dist[d] == INF) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[d] << '\n';
		}
	}

	return 0;
}