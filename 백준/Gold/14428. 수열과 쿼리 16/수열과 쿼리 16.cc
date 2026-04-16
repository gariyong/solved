#include <iostream>

using namespace std;

const int MAX = 100000;
const int INF = 1e9;
int tree[MAX * 4 + 1];
int num[MAX + 1];

int min_idx(int a, int b) {

	if (a == -1) {
		return b;
	}
	else if (b == -1) {
		return a;
	}

	if (num[a] < num[b]) {
		return a;
	}
	else if (num[b] < num[a]) {
		return b;
	}

	return a < b ? a : b;
}

int init(int start, int end, int node) {
	if (start == end) return tree[node] = start;

	int mid = (start + end) / 2;
	return tree[node] = min_idx(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int idx) {
	if (start > idx || end < idx) return tree[node];
	if (start == end) return tree[node];

	int mid = (start + end) / 2;
	return tree[node] = min_idx(update(start, mid, node * 2, idx), update(mid + 1, end, node * 2 + 1, idx));
}

int query(int start, int end, int left, int right, int node) {
	if (end < left || start > right) return -1;
	if (start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min_idx(query(start, mid, left, right, node * 2), query(mid + 1, end, left, right, node * 2 + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> num[i];
	init(1, n, 1);

	int m;
	cin >> m;

	while (m--) {
		int a;
		cin >> a;

		if (a == 1) {
			int i, v;
			cin >> i >> v;
			num[i] = v;

			update(1, n, 1, i);
		}
		else if (a == 2) {
			int i, j;
			cin >> i >> j;

			cout << query(1, n, i, j, 1) << '\n';
		}
	}

	return 0;
}