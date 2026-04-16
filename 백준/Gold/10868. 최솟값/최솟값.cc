#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX = 100000;
int tree[MAX * 4 + 1];
int num[MAX + 1];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = num[start];

	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int query(int start, int end, int left, int right, int node) {
	if (left > end || right < start) return INF;
	if (start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min(query(start, mid, left, right, node * 2), query(mid + 1, end, left, right, node * 2 + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> num[i];
	init(1, n, 1);

	while (m--) {
		int a, b;
		cin >> a >> b;

		cout << query(1, n, a, b, 1) << '\n';
	}

	return 0;
}