// 巩力: https://www.acmicpc.net/problem/15681
// 力格: 飘府客 孽府

//dfs + dp
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& subtree_size, int u, int parent) {
	subtree_size[u] = 1;

	for (int v : adj[u]) {
		if (v != parent) {
			dfs(adj, subtree_size, v, u);
			subtree_size[u] += subtree_size[v];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r, q;
	cin >> n >> r >> q;

	vector<vector<int>> adj(n + 1);
	vector<int> subtree_size(n + 1, 0);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(adj, subtree_size, r, -1);

	while (q--) {
		int Q;
		cin >> Q;
		cout << subtree_size[Q] << '\n';
	}

	return 0;
}