#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;

struct Node {
	int max_val;
	int min_val;
};

int arr[MAX + 1];
Node tree[MAX * 4 + 1];

Node init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = { arr[start], arr[start] };
	}
	int mid = (start + end) / 2;
	Node left = init(start, mid, node * 2);
	Node right = init(mid + 1, end, node * 2 + 1);

	return tree[node] = { max(left.max_val, right.max_val), min(left.min_val, right.min_val) };
}

Node find(int start, int end, int left, int right, int node) {
	if (left > end || right < start) return { 0, 1000000001 };
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	Node a = find(start, mid, left, right, node * 2);
	Node b = find(mid + 1, end, left, right, node * 2 + 1);

	return { max(a.max_val, b.max_val), min(a.min_val, b.min_val) };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	init(1, n, 1);

	while (m--) {
		int a, b;
		cin >> a >> b;

		Node result = find(1, n, a, b, 1);
		cout << result.min_val << ' ' << result.max_val << '\n';
	}

	return 0;
}