#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Line_seg {
	pair<int, int> a, b;
};

int find(vector<int>& parent, int x) {
	if (parent[x] == x) {
		return parent[x];
	}

	return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, vector<int>& cnt, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);

	if (a != b) {
		parent[a] = b;
		cnt[b] += cnt[a];
		cnt[a] = 0;
	}
}

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	int res = (p2.first - p1.first) * (p3.second - p1.second)
		- (p2.second - p1.second) * (p3.first - p1.first);

	if (res > 0) {
		return 1;
	}
	else if (res < 0) {
		return -1;
	}

	return 0;
}

bool is_cross(Line_seg l, Line_seg r) {
	int ccw1 = ccw(l.a, l.b, r.a);
	int ccw2 = ccw(l.a, l.b, r.b);
	int ccw3 = ccw(r.a, r.b, l.a);
	int ccw4 = ccw(r.a, r.b, l.b);

	if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {
		if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0) {
			if (l.a > l.b) swap(l.a, l.b);
			if (r.a > r.b) swap(r.a, r.b);

			return !(l.b < r.a || r.b < l.a);
		}

		return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Line_seg>lines(n);
	for (int i = 0; i < n; i++) {
		cin >> lines[i].a.first >> lines[i].a.second >> lines[i].b.first >> lines[i].b.second;
	}

	vector<int>parent(n);
	vector<int>cnt(n, 1);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (is_cross(lines[i], lines[j])) {
				unite(parent, cnt, i, j);
			}
		}
	}


	int groups = 0;
	int max_size = 0;
	for (int i = 0; i < n; i++) {
		int cur = find(parent, i);

		if (cur == i) {
			groups++;
		}

		max_size = max(max_size, cnt[cur]);
	}

	cout << groups << '\n' << max_size;

	return 0;
}