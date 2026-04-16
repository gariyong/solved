#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll init(vector<int>& arr, vector<ll>& tree, int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<ll>& tree, int node, int start, int end, int idx, ll val) {
	if (idx < start || idx > end) return;
	if (start == end) {
		tree[node] = val;
		
		return;
	}

	int mid = (start + end) / 2;
	update(tree, node * 2, start, mid, idx, val);
	update(tree, node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	vector <ll> tree(n * 4 + 1);
	init(arr, tree, 1, 1, n);

	while (q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x > y) swap(x, y);

		cout << sum(tree, 1, 1, n, x, y) << '\n';
		update(tree, 1, 1, n, a, b);
		arr[a] = b;
	}

	return 0;
}