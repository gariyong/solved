#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 500000;
long long tree[MAX * 4 + 1];

struct Node {
	int val;
	int idx;
};

bool compare(const Node& a, const Node& b) {
	if (a.val == b.val) return a.idx < b.idx;

	return a.val < b.val;
}

void update_arr(int start, int end, int node, int target) {
	if (target < start || end < target) return;

	tree[node]++;
	if (start != end) {
		int mid = (start + end) / 2;

		update_arr(start, mid, node * 2, target);
		update_arr(mid + 1, end, node * 2 + 1, target);
	}
}

long long sum_arr(int start, int end, int left, int right, int node) {
	if (end < left || start > right) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum_arr(start, mid, left, right, node * 2) + sum_arr(mid + 1, end, left, right, node * 2 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Node> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].val;
		arr[i].idx = i + 1;
	}

	sort(arr.begin(), arr.end(), compare);

	long long result = 0;
	for (int i = 0; i < n; i++) {
		result += sum_arr(1, n, arr[i].idx + 1, n, 1);
		update_arr(1, n, 1, arr[i].idx);
	}

	cout << result;

	return 0;
}