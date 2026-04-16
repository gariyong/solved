#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ranges>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	vector<int> nodes(n + 1, 0);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		nodes[v]++;
	}

	vector<int> semester(n + 1, 1);
	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (nodes[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : graph[cur]) {
			nodes[next]--;

			semester[next] = max(semester[next], semester[cur] + 1);

			if (nodes[next] == 0) {
				q.push(next);
			}
		}
	}

	for(int x : semester | views::drop(1)) {
		cout << x << " ";
	}

	return 0;
}