#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dragon {
	int c;
	int s;
	int n;

	dragon(int c, int s, int n) : c(c), s(s), n(n) {};
};

int find(vector<int>& parent, int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);

	if (a != b) {
		parent[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n, m, k;
		cin >> n >> m >> k;

		if (n == 0 && m == 0 && k == 0) break;

		vector<int> parent(n + 1);
		for (int i = 0; i <= n; i++)parent[i] = i;

		while (m--) {
			int a, b;
			cin >> a >> b;

			unite(parent, a, b);
		}

		vector<dragon> dragons;
		while(k--){
			int a, b, c;
			cin >> a >> b >> c;

			dragons.push_back(dragon(a, b, c));
		}

		vector<vector<dragon>> nodes(n + 1);
		for (auto x : dragons) {
			int city = find(parent, x.c);
			nodes[city].push_back(x);
		}

		long long sum = 0;
		for (auto tree : nodes) {
			if (tree.size() == 0) continue;

			sort(tree.begin(), tree.end(), [](const dragon& a, const dragon& b) {
				return a.n > b.n;
				});

			int warrior;
			int size = (int)tree.size();
			if (tree[0].s <= tree[0].n) {
				warrior = tree[0].s;
			}
			else {
				warrior = tree[0].n + 1;
			}

			for (int i = 1; i < size; i++) {
				auto d = tree[i];

				if (d.n < warrior) {
					continue;
				}
				else {
					warrior = min(warrior + d.s, d.n + 1);
				}
			}

			sum += warrior;
		}

		cout << sum << '\n';
	}

	return 0;
}