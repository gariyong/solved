#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int dist_sq(pair<int, int>& p1, pair<int, int>& p2) {
	long long dx = (long long)p1.first - p2.first;
	long long dy = (long long)p1.second - p2.second;

	return (int)(dx * dx + dy * dy);
}

int closest_pair(vector<pair<int, int>>& v, int start, int end) {
	int n = end - start + 1;

	if (n <= 3) {
		int min_d_sq = 1e9;

		for (int i = start; i < end; i++) {
			for (int j = i + 1; j <= end; j++) {
				min_d_sq = min(min_d_sq, dist_sq(v[i], v[j]));
			}
		}

		return min_d_sq;
	}

	int mid = (start + end) / 2;
	int mid_x = v[mid].first;
	int d_sq = min(closest_pair(v, start, mid), closest_pair(v, mid + 1, end));

	vector<pair<int, int>> cords;

	for (int i = start; i <= end; i++) {
		int dx = v[i].first - mid_x;
		if (dx * dx < d_sq) {
			cords.push_back(v[i]);
		}
	}

	sort(cords.begin(), cords.end(), [](pair<int, int>& a, pair<int, int>& b) {
		return a.second < b.second;
		});

	for (int i = 0; i < cords.size(); i++) {
		for (int j = i + 1; j < cords.size(); j++) {
			int dy = cords[j].second - cords[i].second;
			if (dy * dy >= d_sq) break;

			d_sq = min(d_sq, dist_sq(cords[i], cords[j]));
		}
	}

	return d_sq;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());

	cout << closest_pair(v, 0, n - 1);

	return 0;
}