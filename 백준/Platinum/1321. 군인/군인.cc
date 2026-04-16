#include <iostream>
#include <vector>

using namespace std;

const int MAX = 500000;
int tree[MAX * 4 + 1];

int init(vector<int>& unit, int start, int end, int node) {
	if (start == end) return tree[node] = unit[start];

	int mid = (start + end) / 2;
	return tree[node] = init(unit, start, mid, node * 2) + init(unit, mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int idx, int val) {
	if (idx < start || idx > end) return;
	if (start == end) {
		tree[node] += val;
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, val);
	update(mid + 1, end, node * 2 + 1, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int start, int end, int node, int k) {
	if (start == end) return start;

	int mid = (start + end) / 2;
	if (tree[node * 2] >= k) {
		return query(start, mid, node * 2, k);
	}
	else {
		return query(mid + 1, end, node * 2 + 1, k - tree[node * 2]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> unit(n + 1);
	for (int i = 1; i <= n; i++) cin >> unit[i];
	init(unit, 1, n, 1);

	int m;
	cin >> m;

	while (m--) {
		int a;
		cin >> a;

		if (a == 1) {
			int b, c;
			cin >> b >> c;

			update(1, n, 1, b, c);
		}
		else if (a == 2) {
			int x;
			cin >> x;

			cout << query(1, n, 1, x) << '\n';
		}
	}

	return 0;
}