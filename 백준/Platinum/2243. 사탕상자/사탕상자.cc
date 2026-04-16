#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
int candy[4 * MAX + 1];

int find_candy(int start, int end, int node, int k) {
	if (start == end) return start;

	int mid = (start + end) / 2;

	if (candy[node * 2] >= k) {
		return find_candy(start, mid, node * 2, k);
	}
	else {
		return find_candy(mid + 1, end, node * 2 + 1, k - candy[node * 2]);
	}
}

void update_candy(int start, int end, int node, int target, int k) {
	if (target < start || target > end) return;

	candy[node] += k;

	if (start != end) {
		int mid = (start + end) / 2;
		update_candy(start, mid, node * 2, target, k);
		update_candy(mid + 1, end, node * 2 + 1, target, k);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;

		if (a == 1) {
			int b;
			cin >> b;

			int flavor = find_candy(1, MAX, 1, b);
			cout << flavor << '\n';

			update_candy(1, MAX, 1, flavor, -1);
		}
		else if (a == 2) {
			int b, c;
			cin >> b >> c;

			update_candy(1, MAX, 1, b, c);
		}
	}

	return 0;
}