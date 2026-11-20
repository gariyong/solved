#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& nodes, vector<bool>& visit, int cur, vector<int>& result, int& cnt) {
	visit[cur] = true;
	result[cur] = cnt++;

	for (int next : nodes[cur]) {
		if (!visit[next]) {
			dfs(nodes, visit, next, result, cnt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, start;
	cin >> n >> m >> start;

	vector<vector<int>> nodes(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}

	vector<bool> visit(n + 1, false);
	vector<int> result(n + 1, 0);

	for(int i = 1; i <= n; i++) {
		sort(nodes[i].begin(), nodes[i].end());
	}

	int cnt = 1;
	dfs(nodes, visit, start, result, cnt);

	for(int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}