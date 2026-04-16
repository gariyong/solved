#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 500000;
int tree[MAX * 4 + 1];

struct runner {
	int ability;
	int idx;
	int rank;
};

runner runners[MAX + 1];

bool compare_ab(const runner& a, const runner& b) {
	return a.ability < b.ability;
}

bool compare_idx(const runner& a, const runner& b) {
	return a.idx < b.idx;
}

int query(int start, int end, int left, int right, int node) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int node, int idx) {
	if (idx < start || end < idx) return;

	tree[node]++;

	if (start == end) return;
	
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx);
	update(mid + 1, end, node * 2 + 1, idx);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> runners[i].ability;
		runners[i].idx = i;
	}

	sort(runners + 1, runners + n + 1, compare_ab);
	for (int i = 1; i <= n; i++) runners[i].rank = i;

	sort(runners + 1, runners + n + 1, compare_idx);

	for (int i = 1; i <= n; i++) {
		int cur_rank = runners[i].rank;
		int cnt_slow = query(1, n, 1, cur_rank, 1);

		cout << i - cnt_slow << '\n';
		update(1, n, 1, cur_rank);
	}

	return 0;
}