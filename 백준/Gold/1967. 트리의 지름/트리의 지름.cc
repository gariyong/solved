#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

pair<int,int> bfs(vector<vector<pair<int, int>>>& node, int start, int n) {
	queue <int> q;
	vector<int> distance(n + 1, -1);
	int far_node = start;
	int max_dis = 0;

	
	q.push(start);
	distance[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int size = (int)node[cur].size();
		for (int i = 0; i < size; i++) {
			int next = node[cur][i].first;
			int cost = node[cur][i].second;

			if (distance[next] == -1) {
				distance[next] = cost + distance[cur];
				q.push(next);

				if (distance[next] > max_dis) {
					max_dis = distance[next];
					far_node = next;
				}
			}
		}
	}

	return { far_node, max_dis };
}

int main() {
	int n, A;
	int radius;
	vector<vector<pair<int, int>>> node;
	
	cin >> n;
	node.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		node[u].push_back({ v, w });
		node[v].push_back({ u, w });
	}
	
	A = bfs(node, 1, n).first;

	radius = bfs(node, A, n).second;
	
	cout << radius;

	return 0;
}