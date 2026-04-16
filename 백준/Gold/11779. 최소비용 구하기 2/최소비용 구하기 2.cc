#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& parent, int start, int n) {
	vector<int> distance(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>q;

	distance[start] = 0;
	q.push({ 0, start });

	while (!q.empty()) {
		auto [cost, cur] = q.top();
		q.pop();

		if (distance[cur] < cost) {
			continue;
		}

		int size = (int)graph[cur].size();
		
		for (int i = 0; i < size; i++) {
			auto [n_cost, next] = graph[cur][i];

			if (distance[next] > cost + n_cost) {
				distance[next] = cost + n_cost;
				q.push({ distance[next], next });
				parent[next] = cur;
			}
		}
	}

	return distance;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, start, end;
	vector<int>path;
	
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<int> parent(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		graph[u].push_back({ w, v });
	}
	
	cin >> start >> end;

	auto distance = dijkstra(graph, parent, start, n);

	cout << distance[end] << '\n';

	for (int cur = end; cur != -1; cur = parent[cur]) {
		path.push_back(cur);
	}
	reverse(path.begin(), path.end());

	cout << path.size() << '\n';
	
	for (int node : path) {
		cout << node << ' ';
	}

	return 0;
}