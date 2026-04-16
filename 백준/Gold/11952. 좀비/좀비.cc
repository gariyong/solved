#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

const int INF = 1e9;

struct city {
	bool is_danger = false;
	int danger_dist = INF;
};

long long dijkstra(int start, int end, vector<vector<int>>& nodes, vector<city>& cities, int P, int Q, int s) {
	vector<long long> dist(nodes.size(), 1e18);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;

	dist[start] = 0;
	q.push({ 0, start });

	while (!q.empty()) {
		auto [cur_cost, cur] = q.top();
		q.pop();

		if (dist[cur] < cur_cost) continue;

		for (int next : nodes[cur]) {
			if (cities[next].is_danger) continue;

			long long cost;
			if (next == end) {
				cost = 0;
			}
			else if (cities[next].danger_dist <= s) {
				cost = Q;
			}
			else {
				cost = P;
			}

			if (dist[next] > cur_cost + cost) {
				dist[next] = cur_cost + cost;
				q.push({ dist[next], next });
			}
		}
	}

	return dist[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k, s;
	cin >> n >> m >> k >> s;

	vector<city> cities(n + 1);
	vector<vector<int>> nodes(n + 1);

	int P, Q;
	cin >> P >> Q;
	
	vector<int> danger_city(k);
	for (int i = 0; i < k; i++) {
		cin >> danger_city[i];
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}

	queue<int> q;
	for (int x : danger_city) {
		cities[x].is_danger = true;
		cities[x].danger_dist = 0;
		q.push(x);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : nodes[cur]) {
			if (cities[next].danger_dist == INF) {
				cities[next].danger_dist = cities[cur].danger_dist + 1;
				q.push(next);
			}
		}
	}

	long long result = dijkstra(1, n, nodes, cities, P, Q, s);

	cout << result;

	return 0;
}