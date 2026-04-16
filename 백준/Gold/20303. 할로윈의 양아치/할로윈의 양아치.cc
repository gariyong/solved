#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct rel {
	int f = 0;
	int c = 0;
};

int find(vector<int>& parent, int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);

	if (a != b) parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> candys(n + 1);
	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> candys[i];
		parent[i] = i;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;

		unite(parent, a, b);
	}

	vector<rel> relations(n + 1);
	for (int i = 1; i <= n; i++) {
		int x = find(parent, i);
		relations[x].c += candys[i];
		relations[x].f++;
	}
	
	vector<int> dp(k, 0);
	for (int i = 1; i <= n; i++) {
		if (relations[i].f <= 0) continue;

		int v = relations[i].f;
		int w = relations[i].c;
		for (int j = k - 1; j >= v; j--) {
			dp[j] = max(dp[j], dp[j - v] + w);
		}
	}

	cout << dp[k - 1];

	return 0;
}