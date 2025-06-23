// 아기상어(간만에 하니까 머리가 안굴러감 ㅎ)
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

typedef struct Pair {
	int x, y;
} Pair;

Pair bfs(vector<vector<int>>& aquarium, Pair start, int& result, int& size, int n, int& eat) {
	Pair cur = start;
	int dist = 0;
	queue<Pair> q;
	queue<Pair> fish;
	vector<vector<int>> visit(n, vector<int>(n, -1));

	q.push(start);
	visit[start.y][start.x] = 0;

	while (!q.empty()) {
		int dy[4] = { -1, 1, 0, 0 };
		int dx[4] = { 0, 0, -1, 1 };
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visit[ny][nx] != -1 || aquarium[ny][nx] > size) {
				continue;
			}

			visit[ny][nx] = visit[y][x] + 1;
			int cost = visit[ny][nx];

			if (aquarium[ny][nx] > 0 && aquarium[ny][nx] < size) {
				if (dist == 0 || dist > cost) {
					dist = cost;
					fish = queue<Pair>();
					fish.push({ nx, ny });
				}
				else if (dist == cost) {
					fish.push({ nx, ny });
				}
			}

			q.push({ nx, ny });
		}
	}

	if (fish.empty()) {
		return cur;
	}
	else {
		cur = fish.front();
		fish.pop();

		int fish_cnt = (int)fish.size();
		for (int i = 0; i < fish_cnt; i++) {
			Pair next_fish = fish.front();
			fish.pop();

			if (next_fish.y < cur.y || (next_fish.y == cur.y && next_fish.x < cur.x)) {
				cur = next_fish;
			}
		}

		eat++;
		if (eat == size) {
			size++;
			eat = 0;
		}

		result += dist;
		aquarium[cur.y][cur.x] = 0;

		return cur;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int eat = 0;
	int result = 0;
	int size = 2;
	Pair start, next;

	cin >> n;
	vector<vector<int>> aquarium(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> aquarium[i][j];

			if (aquarium[i][j] == 9) {
				start.y = i;
				start.x = j;
				aquarium[i][j] = 0;
			}
		}
	}

	while (true) {
		next = bfs(aquarium, start, result, size, n, eat);

		if (next.x == start.x && next.y == start.y) {
			break;
		}

		start = next;
	}

	cout << result;

	return 0;
}