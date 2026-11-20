#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& node, int x) {
	vector<int> distance(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

	q.push({ x, 0 });
	distance[x] = 0;

	while (!q.empty()) {
		auto [start, cost] = q.top();
		q.pop();
	
		if (distance[start] < cost) {
			continue;
		}

		int len = (int)node[start].size();

		for (int i = 0; i < len; i++) {
			auto [next, n_cost] = node[start][i];
			
			n_cost = distance[start] + 1;
			
			if (distance[next] > n_cost) {
				distance[next] = n_cost;
				q.push({ next, n_cost});
			}
		}
	}

	return distance;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k, x;
	int cnt = 0;
	
	cin >> n >> m >> k >> x;
	vector<vector<pair<int,int>>> node(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;

		cin >> x >> y;
		node[x].push_back({ y, INF });
	}

	auto result = dijkstra(n, node, x);

	for (int i = 1; i <= n; i++) {
		if (result[i] == k) {
			cout << i << '\n';
			cnt++;
		}
	}
	
	if (cnt == 0) {
		cout << -1;
	}

	return 0;
}