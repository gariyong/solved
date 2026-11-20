#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	long long x, y;
};

long long ccw(const point& a, const point& b, const point& c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

long long distance(const point& a, const point& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<point> points(n);
	for (point& p : points) cin >> p.x >> p.y;

	for (int i = 1; i < n; i++) {
		if (points[i].y < points[0].y || (points[i].y == points[0].y && points[i].x < points[0].x)) {
			swap(points[0], points[i]);
		}
	}

	point base = points[0];
	sort(points.begin() + 1, points.end(), [&](const point& a, const point& b) {
		long long c = ccw(base, a, b);
		if (c != 0) return c > 0;
		return distance(base, a) < distance(base, b);
		});

	vector<point> result;
	for (int i = 0; i < n; i++) {
		while (result.size() >= 2 && ccw(result[result.size() - 2], result.back(), points[i]) <= 0) {
			result.pop_back();
		}
		result.push_back(points[i]);
	}

	cout << result.size();

	return 0;
}