#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX = 500000;
int tree[MAX * 4 + 1];

int query(int start, int end, int left, int right, int node) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int node, int target) {
	if (target < start || target > end) return ;
	if (start == end) {
		tree[node]++;
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, target);
	update(mid + 1, end, node * 2 + 1, target);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	unordered_map<int, int> machine;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		machine[x] = i;
	}

	 long long result = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		int idx = machine[x];
		result += query(1, n, idx + 1, n, 1);
		update(1, n, 1, idx);
	}

	cout << result;

	return 0;
}