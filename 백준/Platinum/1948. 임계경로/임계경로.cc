#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct edge {
	int to;
	int w;
};

int start_to_end(int start, int end, vector<int>& dist, vector<vector<edge>>& graph, vector<int>& degree) {
	queue<int> q;
	
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto& [next, w] : graph[cur]) {
			dist[next] = max(dist[next], dist[cur] + w);
			degree[next]--;

			if (degree[next] == 0) q.push(next);
		}
	}

	return dist[end];
}

int cnt_road(int end, vector<int>& dist, vector<vector<edge>>& rev_graph, int n) {
	vector<bool> visit(n + 1, false);
	queue<int> q;
	int cnt_edge = 0;

	q.push(end);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto& [next, w] : rev_graph[cur]) {
			if (dist[cur] - dist[next] == w) {
				cnt_edge++;

				if (!visit[next]) {
					visit[next] = true;
					q.push(next);
				}
			}
		}
	}

	return cnt_edge;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<edge>> graph(n + 1);
	vector<vector<edge>> rev_graph(n + 1);
	vector<int> degree(n + 1, 0);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
		rev_graph[v].push_back({ u, w });
		degree[v]++;
	}

	int start, end;
	cin >> start >> end;

	vector<int> dist(n + 1, -1);
	cout << start_to_end(start, end, dist, graph, degree) << '\n' << cnt_road(end, dist, rev_graph, n) << '\n';

	return 0;
}