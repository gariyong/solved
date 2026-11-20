#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, b;
	int max_height = -1, min_height = 257;
	int best_time = 1e9, best_height = 0;
	int** ground;
	
	cin >> n >> m >> b;
	ground = new int* [n];

	for (int i = 0; i < n; i++) {
		ground[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			max_height = max(max_height, ground[i][j]);
			min_height = min(min_height, ground[i][j]);
		}
	}
	
	for (int height = min_height; height <= max_height; height++) {
		int time = 0, inventory = b;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int diff = ground[i][j] - height;
				if (diff > 0) {
					time += diff * 2;
					inventory += diff;
				}
				else {
					time -= diff;
					inventory -= (-diff);
				}
			}
		}

		if (inventory >= 0) {
			if (time < best_time) {
				best_time = time;
				best_height = height;
			}
			else if (time == best_time) {
				best_height = max(best_height, height);
			}
		}
	}
	cout << best_time << " " << best_height;

	for (int i = 0; i < n; i++) {
		delete[] ground[i];
	}
	delete[] ground;

	return 0;
}