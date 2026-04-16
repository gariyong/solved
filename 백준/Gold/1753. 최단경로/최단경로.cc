#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>
#include <functional>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& distance) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	distance[start] = 0;
	q.push({ distance[start], start });

	while (!q.empty()) {
		int cur = q.top().second;
		int cur_distance = q.top().first;
		q.pop();

		if (cur_distance > distance[cur]) {
			continue;
		}

		int len = (int)graph[cur].size();
		for (int i = 0; i < len; i++) {
			int cost = graph[cur][i].first;
			int next = graph[cur][i].second;

			if (distance[next] > cur_distance + cost) {
				distance[next] = cur_distance + cost;
				q.push({ distance[next], next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e, start;
	vector<vector<pair<int, int>>> graph;
	vector<int> distance;

	cin >> v >> e >> start;
	graph.resize(v + 1);
	distance.resize(v + 1, INF);

	for (int i = 0; i < e; i++) {
		int x, y, w;

		cin >> x >> y >> w;
		
		graph[x].push_back({ w, y });
	}

	dijkstra(start, graph, distance);

	for (int i = 1; i <= v; i++) {
		if (distance[i] == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << distance[i] << '\n';
		}
	}

	return 0;
}