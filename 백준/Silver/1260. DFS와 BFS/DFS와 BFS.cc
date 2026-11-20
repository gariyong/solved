#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& nodes, int cur, vector<bool>& visit) {
	cout << cur << ' ';
	visit[cur] = true;
	
	for (int next : nodes[cur]) {
		if(!visit[next]) dfs(nodes, next, visit);
	}
}

void bfs(vector<vector<int>>& nodes, int cur, vector<bool>& visit) {
	visit[cur] = true;
	cout << cur << ' ';

	queue<int> q;
	q.push(cur);
	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for (int next : nodes[node]) {
			if (!visit[next]) {
				visit[next] = true;
				cout << next << ' ';
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> nodes(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
	
		nodes[u].push_back(v);
		nodes[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(nodes[i].begin(), nodes[i].end());
	}

	vector<bool> visit(n + 1, false);
	dfs(nodes, k, visit);
	cout << '\n';

	fill(visit.begin(), visit.end(), false);
	bfs(nodes, k, visit);

	return 0;
}