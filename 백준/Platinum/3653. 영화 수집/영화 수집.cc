#include <iostream>
#include <vector>

using namespace std;

void update(int start, int end, int node, int idx, int val, vector<int>& tree) {
	if (start > idx || end < idx) return;
	if (start == end) {
		tree[node] = val;
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, val, tree);
	update(mid + 1, end, node * 2 + 1, idx, val, tree);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int start, int end, int left, int right, int node, vector<int>& tree) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2, tree) + query(mid + 1, end, left, right, node * 2 + 1, tree);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		int nm = n + m;
		vector<int> movies_pos(n + 1);
		vector<int> tree(nm * 4 + 1, 0);
		for (int i = 1; i <= n; i++) {
			movies_pos[i] = m + i;
			update(1, nm, 1, movies_pos[i], 1, tree);
		}

		int top = m;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;

			cout << query(1, nm, 1, movies_pos[x] - 1, 1, tree) << ' ';
			update(1, nm, 1, movies_pos[x], 0, tree);

			movies_pos[x] = top--;
			update(1, nm, 1, movies_pos[x], 1, tree);
		}

		cout << '\n';
	}

	return 0;
}