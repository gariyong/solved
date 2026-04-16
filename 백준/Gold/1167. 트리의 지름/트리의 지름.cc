#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int n, vector<vector<pair<int, int>>>& node, vector<int>& distance, vector<bool>& visit, int start) {
	visit[start] = true;
	int size = (int)node[start].size();

	for (int i = 0; i < size; i++) {
		auto [next, cost] = node[start][i];

		if (!visit[next]) {
			distance[next] = distance[start] + cost;
			dfs(n, node, distance, visit, next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int r1 = 0;
	int r2 = 0;

	cin >> n;
	vector<vector<pair<int, int>>> node(n + 1);
	vector<bool> visit(n + 1, false);
	vector<int> distance(n + 1, 0);

	for (int i = 0; i < n; i++) {
		int v, u;

		cin >> v;

		while (cin >> u && u != -1) {
			 int w;

			cin >> w;
			node[v].push_back({ u,w });
		}
	}

	dfs(n, node, distance, visit, 1);

	for (int i = 1; i <= n; i++) {
		r1 = distance[i] > distance[r1] ? i : r1;
	}

	distance.assign(n + 1, 0);
	visit.assign(n + 1, false);

	dfs(n, node, distance, visit, r1);

	for (int i = 1; i <= n; i++) {
		r2 = distance[i] > distance[r2] ? i : r2;
	}

	cout << distance[r2];

	return 0;
}