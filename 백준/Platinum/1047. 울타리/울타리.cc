#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree {
	int x;
	int y;
	int fence_len;
};

bool compare(const int& a, const int& b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<tree> trees(n);
	vector<int> x_coords;
	vector<int> y_coords;
	for (int i = 0; i < n; i++) {
		cin >> trees[i].x >> trees[i].y >> trees[i].fence_len;
		x_coords.push_back(trees[i].x);
		y_coords.push_back(trees[i].y);
	}

	sort(x_coords.begin(), x_coords.end());
	sort(y_coords.begin(), y_coords.end());

	int result = n - 1;

	for (int x1 = 0; x1 < n; x1++) {
		for (int x2 = x1; x2 < n; x2++) {
			for (int y1 = 0; y1 < n; y1++) {
				for (int y2 = y1; y2 < n; y2++) {
					int x_min = x_coords[x1], x_max = x_coords[x2];
					int y_min = y_coords[y1], y_max = y_coords[y2];

					vector<int> inside_trees;
					int cut = 0;
					int cur_len = 0;
					int need_len = ((x_max - x_min) + (y_max - y_min)) * 2;
					for (int i = 0; i < n; i++) {
						if (trees[i].x < x_min || trees[i].x > x_max || trees[i].y < y_min || trees[i].y > y_max) {
							cur_len += trees[i].fence_len;
							cut++;
						}
						else {
							inside_trees.push_back(trees[i].fence_len);
						}
					}

					sort(inside_trees.begin(), inside_trees.end(), compare);

					for (int len : inside_trees) {
						if (cur_len >= need_len) break;
						cut++;
						cur_len += len;
					}

					result = min(result, cut);
				}
			}
		}
	}

	cout << result;

	return 0;
}