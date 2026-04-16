#include <iostream>
#include <algorithm>

using namespace std;

struct Line_seg {
	pair<long long, long long> a, b;
};

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
	long long res = (p2.first - p1.first) * (p3.second - p1.second)
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

	Line_seg l, r;
	cin >> l.a.first >> l.a.second >> l.b.first >> l.b.second;
	cin >> r.a.first >> r.a.second >> r.b.first >> r.b.second;

	cout << is_cross(l, r);

	return 0;
}