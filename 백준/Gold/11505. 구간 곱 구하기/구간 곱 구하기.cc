#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 1000000;
const ll MOD = 1000000007;

int arr[MAX + 1];
ll tree[MAX * 4 + 1];

ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start] % MOD;

	int mid = (start + end) / 2;
	return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MOD;
}

ll update(int start, int end, int node, int idx, int val) {
	if (start > idx || end < idx) return tree[node];
	if (start == end) return tree[node] = val % MOD;

	int mid = (start + end) / 2;
	return tree[node] = (update(start, mid, node * 2, idx, val) * update(mid + 1, end, node * 2 + 1, idx, val)) % MOD;
}

ll find(int start, int end, int left, int right, int node) {
	if (start > right || end < left) return 1;
	if (start >= left && end <= right) return tree[node];

	return (find(start, (start + end) / 2, left, right, node * 2) * find((start + end) / 2 + 1, end, left, right, node * 2 + 1)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else if (a == 2) {
			cout << find(1, n, b, c, 1) << '\n';
		}
	}

	return 0;
}