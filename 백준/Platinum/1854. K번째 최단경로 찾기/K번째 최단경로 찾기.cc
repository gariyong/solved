#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<priority_queue<int>>& dist, int start, int k) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
	q.push({ 0 , 1 });
	dist[1].push(0);
	
	while (!q.empty()) {
		auto [cost, cur] = q.top();
		q.pop();

		for (auto& node : graph[cur]) {
			int n_cost = cost + node.first;
			int next = node.second;

			if (dist[next].size() < k) {
				dist[next].push(n_cost);
				q.push({ n_cost, next });
			}
			else if (dist[next].top() > n_cost) {
				dist[next].pop();
				dist[next].push(n_cost);
				q.push({ n_cost, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> graph(n + 1);
	vector<priority_queue<int>> dist(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ c, b });
	}

	dijkstra(graph, dist, 1, k);

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i].top() << '\n';
		}
	}

	return 0;
}