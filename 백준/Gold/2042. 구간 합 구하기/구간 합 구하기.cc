#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll init_tree(vector<ll>& arr, vector<ll>& tree, int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;

	return tree[node] = init_tree(arr, tree, node * 2, start, mid) + init_tree(arr, tree, node * 2 + 1, mid + 1, end);
}

ll sum_tree(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum_tree(tree, node * 2, start, mid, left, right) + sum_tree(tree, node * 2 + 1, mid + 1, end, left, right);
}

ll update_tree(vector<ll>& tree, int node, int start, int end, int idx, ll val) {
	if (idx < start || idx > end) return tree[node];
	if (start == end) return tree[node] = val;
	
	int mid = (start + end) / 2;

	return tree[node] = update_tree(tree, node * 2, start, mid, idx, val) + update_tree(tree, node * 2 + 1, mid + 1, end, idx, val);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	vector <ll> tree(n * 4 + 1);
	init_tree(arr, tree, 1, 1, n);

	for (int i = 0; i < m + k; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;

		if (a == 1) {
			update_tree(tree, 1, 1, n, b, c);
			arr[b] = c;
		}
		else if (a == 2) {
			cout << sum_tree(tree, 1, 1, n, b, c) << '\n';
		}
	}

	return 0;
}