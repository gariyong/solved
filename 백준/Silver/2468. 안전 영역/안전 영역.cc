#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void bfs(int**& ground, int**& visit, int n, int h, int y, int x) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visit[y][x] = 1;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = current.first + dy[i];
            int nx = current.second + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                if (visit[ny][nx] == 0 && ground[ny][nx] > h) {
                    visit[ny][nx] = 1;
                    q.push({ ny, nx });
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int** ground = new int* [n];
    int** visit = new int* [n];
    int max_height = 0;

    for (int i = 0; i < n; i++) {
        ground[i] = new int[n];
        visit[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> ground[i][j];
            max_height = max(max_height, ground[i][j]);
        }
    }

    int result = 1;

    for (int h = 1; h <= max_height; h++) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            fill(visit[i], visit[i] + n, 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j] == 0 && ground[i][j] > h) {
                    bfs(ground, visit, n, h, i, j);
                    cnt++;
                }
            }
        }

        result = max(result, cnt);
    }

    cout << result;

    for (int i = 0; i < n; i++) {
        delete[] ground[i];
        delete[] visit[i];
    }
    delete[] ground;
    delete[] visit;

    return 0;
}
