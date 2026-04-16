#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(vector<vector<int>>(n+1));
	vector<int> indegree(n + 1, 0);

	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		indegree[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 1; i <= n; i++) {
		if(indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> result;
	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		result.push_back(cur);

		for(int next : adj[cur]) {
			indegree[next]--;
			if(indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	for(int node : result) {
		cout << node << " ";
	}

	return 0;
}