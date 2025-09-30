// 문제 : https://www.acmicpc.net/problem/1162
// 제목 : 도로포장

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

long long dijkstra(vector<vector<pair<int, int>>>& graph, int n, int k) {
	priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> q;
	vector<vector<long long>>dp(k + 1, vector<long long>(n + 1, INF));
	dp[0][1] = 0;

	q.push({ 0, { 0, 1 } });
	while (!q.empty()) {
		auto [cost, data] = q.top();
		auto [cnt, cur] = data;
		q.pop();

		if (cost > dp[cnt][cur]) continue;

		for (auto [next_cost, next] : graph[cur]) {
			long long new_cost = cost + next_cost;

			if (new_cost < dp[cnt][next]) {
				dp[cnt][next] = new_cost;
				q.push({ new_cost, {cnt, next} });
			}

			if (cnt < k) {
				if (cost < dp[cnt + 1][next]) {
					dp[cnt + 1][next] = cost;
					q.push({ cost, {cnt + 1, next} });
				}
			}
		}
	}

	long long min_time = INF;
	for (int i = 0; i <= k; i++) {
		min_time = min(min_time, dp[i][n]);
	}

	return min_time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ w, v });
		graph[v].push_back({ w, u });
	}

	cout << dijkstra(graph, n, k);

	return 0;
}