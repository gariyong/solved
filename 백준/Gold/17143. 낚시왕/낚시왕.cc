#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

const int dr[] = { 0, -1, 1, 0, 0 };
const int dc[] = { 0, 0, 0, 1, -1 };

struct Shark {
	pair<int, int> pos;
	int speed;
	int head;
	int size;
};

tuple<int, int, int> move_shark(Shark shark, int r, int c) {
	int p_r = shark.pos.first;
	int p_c = shark.pos.second;
	int s = shark.speed;
	int d = shark.head;

	int period;
	if (d == 1 || d == 2) {
		period = 2 * (r - 1);
		if (period == 0) return { p_r, p_c, d };
	}
	else {
		period = 2 * (c - 1);
		if (period == 0) return { p_r, p_c, d };
	}

	s %= period;

	int nr = p_r;
	int nc = p_c;
	int nd = d;

	while (s > 0) {
		nr += dr[nd];
		nc += dc[nd];
		s--;

		
		if (nd == 1 && nr < 0) {
			nr = 1;
			nd = 2;
		}
		else if (nd == 2 && nr >= r) {
			nr = r - 2;
			nd = 1;
		}
		else if (nd == 4 && nc < 0) {
			nc = 1;
			nd = 3;
		}
		else if (nd == 3 && nc >= c) {
			nc = c - 2;
			nd = 4;
		}
	}

	return { nr, nc, nd };
}

int fishing(vector<vector<int>>& sea, vector<Shark>& sharks, int r, int c, int m) {
	int size_sum = 0;
	
	for (int fisher = 0; fisher < c; fisher++) {
		int target = -1;
		
		for (int i = 0; i < m; i++) {
			if (sharks[i].size == 0) continue;

			if (sharks[i].pos.second == fisher) {
				if (target == -1) {
					target = i;
				}
				else {
					if (sharks[target].pos.first > sharks[i].pos.first) {
						target = i;
					}
				}
			}
		}

		if (target != -1) {
			size_sum += sharks[target].size;
			sharks[target].size = 0;
		}

		vector<vector<int>> new_sea(r, vector<int>(c, -1));
		for (int i = 0; i < m; i++) {
			if (sharks[i].size == 0) continue;

			auto[nr, nc, nd] = move_shark(sharks[i], r, c);

			sharks[i].pos = { nr, nc };
			sharks[i].head = nd;

			int& cell = new_sea[nr][nc];
			if (cell == -1) {
				cell = i;
			}
			else {
				if (sharks[cell].size < sharks[i].size) {
					sharks[cell].size = 0;
					cell = i;
				}
				else {
					sharks[i].size = 0;
				}
			}
		}

		sea = new_sea;
	}

	return size_sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c, m;
	cin >> r >> c >> m;

	vector<vector<int>> sea(r, vector<int>(c, -1));
	vector<Shark> sharks(m);
	for (int i = 0; i < m; i++) {
		int rr, cc, s, d, z;
		cin >> rr >> cc >> s >> d >> z;

		sharks[i] = { {rr - 1, cc - 1}, s , d, z };
		sea[rr - 1][cc - 1] = i;
	}

	int result = fishing(sea, sharks, r, c, m);

	cout << result;

	return 0;
}