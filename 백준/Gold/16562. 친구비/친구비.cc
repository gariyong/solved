#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, vector<int>& cost, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);

	if (a != b) {
		if (cost[a] < cost[b]) {
			parent[b] = a;
		}
		else {
			parent[a] = b;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> parent(n + 1);
	for (int i = 0; i <= n; i++) parent[i] = i;

	vector<int> cost(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	while (m--) {
		int v, w;
		cin >> v >> w;

		unite(parent, cost, v, w);
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (find(parent, i) == i) sum += cost[i];
	}

	(sum <= k) ? cout << sum : cout << "Oh no";

	return 0;
}