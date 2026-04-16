#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, vector<long long>& dist, int x) {
	if (parent[x] == x) return x;

	int p = parent[x];
	parent[x] = find(parent, dist, parent[x]);
	dist[x] += dist[p];
	return parent[x];
}

void unite(vector<int>& parent, vector<long long>& dist, int a, int b, int w) {
	int p_a = find(parent, dist, a);
	int p_b = find(parent, dist, b);

	if (p_a == p_b) return;

	parent[p_b] = p_a;
	dist[p_b] = dist[a] + w - dist[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		vector<int> parent(n + 1);
		vector<long long> dist(n + 1, 0);

		for (int i = 1; i <= n; i++) parent[i] = i;

		while (m--) {
			char x;
			cin >> x;

			if (x == '!') {
				int a, b, w;
				cin >> a >> b >> w;
				unite(parent, dist, a, b, w);
			}
			else if (x == '?') {
				int a, b;
				cin >> a >> b;

				if (find(parent, dist, a) != find(parent, dist, b)) {
					cout << "UNKNOWN\n";
				}
				else {
					cout << dist[b] - dist[a] << "\n";
				}
			}
		}
	}

	return 0;
}