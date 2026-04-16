#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int cur, vector<vector<int>>& graph, vector<int>& visit, vector<bool>& is_cut, bool is_root, int& cnt) {
	visit[cur] = ++cnt;
	int turn = cnt;
	int children = 0;

	for (int next : graph[cur]) {
		if (visit[next] == 0) {
			children++;
			int child_turn = dfs(next, graph, visit, is_cut, false, cnt);

			if (!is_root && child_turn >= visit[cur]) {
				is_cut[cur] = true;
			}
			
			turn = min(turn, child_turn);
		}
		else {
			turn = min(turn, visit[next]);
		}
	}


	if (is_root && children >= 2) is_cut[cur] = true;

	return turn;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	cin >> v >> e;

	vector<vector<int>> graph(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int cnt = 0;
	vector<int> visit(v + 1, 0);
	vector<bool> is_cut(v + 1, false);
	for (int i = 1; i <= v; i++) {
		if (visit[i] == 0) dfs(i, graph, visit, is_cut, true, cnt);
	}

	vector<int> result;
	for (int i = 1; i <= v; i++) {
		if (is_cut[i]) result.push_back(i);
	}

	cout << result.size() << '\n';
	for (int x : result) cout << x << ' ';

	return 0;
}