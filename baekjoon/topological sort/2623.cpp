// 문제 : https://www.acmicpc.net/problem/2623
// 제목 : 음악프로그램

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	vector<int>indegree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int x;
		int prev = -1;
		cin >> x;

		vector<int> schedule(x);
		for (int j = 0; j < x; j++) {
			cin >> schedule[j];
		}

		for (int j = 0; j < x - 1; j++) {
			adj[schedule[j]].push_back(schedule[j + 1]);
			indegree[schedule[j + 1]]++;
		}
	}
	vector<int> sequence;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		sequence.push_back(cur);

		for (int next : adj[cur]) {
			indegree[next]--;

			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	if (sequence.size() != n) {
		cout << 0;
	}
	else {
		for (int x : sequence) {
			cout << x << "\n";
		}
	}

	return 0;
}