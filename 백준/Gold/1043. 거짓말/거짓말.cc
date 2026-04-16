#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int>& parent) {
	if (parent[x] == x) {
		return x;
	}

	return parent[x] = find(parent[x], parent);
}

void unionSet(int a, int b, vector<int>& parent) {
	a = find(a, parent);
	b = find(b, parent);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	int n, m, t;

	cin >> n >> m >> t;
	vector<int> parent(n + 1);
	vector<int> truth(t);
	vector<vector<int>> party(m);
	vector<int> truthroot;

	for (int i = 0; i < t; i++) {
		cin >> truth[i];
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x;

		cin >> x;

		int first;
		for (int j = 0; j < x; j++) {
			int p;

			cin >> p;
			party[i].push_back(p);

			if (j == 0) {
				first = p;
			}
			else {
				unionSet(first, p, parent);
			}
		}
	}

	for (int i = 0; i < t; i++) {
		truthroot.push_back(find(truth[i], parent));
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		bool flag = true;

		int size = (int)party[i].size();
		for (int j = 0; j < size; j++) {
			int p = party[i][j];
			int root = find(p, parent);

			int size_t = truthroot.size();
			for (int k = 0; k < size_t; k++) {
				if (root == truthroot[k]) {
					flag = false;
					break;
				}
			}

			if (!flag) {
				break;
			}
		}

		if (flag) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}