#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
vector <int> graph[MAX];
int parent[MAX];

void dfs(int cur, int prev) {
	parent[cur] = prev;

	int len = (int)graph[cur].size();
	for (int i = 0; i < len; i++) {
		int next = graph[cur][i];
		
		if (next != prev) {
			dfs(next, cur);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;

		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 0);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}