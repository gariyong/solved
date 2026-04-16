#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
	int from;
	int to;
	int cost;
}Node;

bool bellmanFord(int n, vector<Node>& node) {
	vector<int> distance(n + 1, 0);
	int len = node.size();

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < len; j++) {
			Node e = node[j];
			if (distance[e.from] + e.cost < distance[e.to]) {
				distance[e.to] = distance[e.from] + e.cost;
			}
		}
	}

	for (int i = 0; i < len; i++) {
		Node e = node[i];
		if (distance[e.from] + e.cost < distance[e.to]) {
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;

	cin >> tc;

	while (tc--) {
		int n, m, w;
		vector<Node> node;
		
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++) {
			int u, v, t;

			cin >> u >> v >> t;

			node.push_back({ u, v, t });
			node.push_back({ v, u, t });
		}

		for (int i = 0; i < w; i++) {
			int u, v, t;

			cin >> u >> v >> t;

			node.push_back({ u, v, -t });
		}

		if (bellmanFord(n, node)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}