#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<char>> map(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	vector<int> indegree(n, 0);
	vector<vector<int>> node(n);
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			if (u == v) continue;
			
			if (map[u][v] != map[v][u] && map[u][v] == 'Y') {
				node[v].push_back(u);
				indegree[u]++;
			}
		}
	}

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int x : node[cur]) {
			indegree[x]--;
			
			if (indegree[x] == 0) {
				q.push(x);
			}
		}
	}

	bool flag = true;
	for (int x : indegree) {
		if (x != 0) {
			flag = false;
			break;
		}
	}

	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}