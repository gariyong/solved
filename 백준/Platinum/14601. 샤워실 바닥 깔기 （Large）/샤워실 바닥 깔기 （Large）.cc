#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void tiling(vector<vector<int>>& tile, int x, int y, int hole_x, int hole_y, int n, int& tile_num) {
	if (n == 1) {
		return;
	}

	int t = tile_num++;
	int half = n / 2;

	int middle_x = x + half;
	int middle_y = y + half;

	int hole_pos = -1;
	if (hole_x < middle_x && hole_y < middle_y) hole_pos = 0;
	else if (hole_x >= middle_x && hole_y < middle_y) hole_pos = 1;
	else if (hole_x < middle_x && hole_y >= middle_y) hole_pos = 2;
	else hole_pos = 3;

	if (hole_pos != 0)tile[middle_y - 1][middle_x - 1] = t;
	if (hole_pos != 1)tile[middle_y - 1][middle_x] = t;
	if (hole_pos != 2) tile[middle_y][middle_x - 1] = t;
	if (hole_pos != 3) tile[middle_y][middle_x] = t;

	tiling(tile, x, y, hole_pos == 0 ? hole_x : middle_x - 1, hole_pos == 0 ? hole_y : middle_y - 1, half, tile_num);
	tiling(tile, x + half, y, hole_pos == 1 ? hole_x : middle_x, hole_pos == 1 ? hole_y : middle_y - 1, half, tile_num);
	tiling(tile, x, y + half, hole_pos == 2 ? hole_x : middle_x - 1, hole_pos == 2 ? hole_y : middle_y, half, tile_num);
	tiling(tile, x + half, y + half, hole_pos == 3 ? hole_x : middle_x, hole_pos == 3 ? hole_y : middle_y, half, tile_num);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	int n = (int)pow(2, k);
	vector<vector<int>> tile(n, vector<int>(n, 0));

	int x, y;
	cin >> x >> y;

	int hole_x = x - 1;
	int hole_y = n - y;
	int tile_num = 1;
	tile[hole_y][hole_x] = -1;

	tiling(tile, 0, 0, hole_x, hole_y, n, tile_num);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << tile[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}