#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

void bfs(int n, int m, int h, int& day, int& tomato, vector<vector<vector<int>>>& farm, queue<tuple<int, int, int, int>>& q) {
    int dy[] = { -1, 1, 0, 0, 0, 0 };
    int dx[] = { 0, 0, -1, 1, 0, 0 };
    int dz[] = { 0, 0, 0, 0, -1, 1 };

    while (!q.empty()) {
        auto [x, y, z, cur_day] = q.front();
        q.pop();

        day = max(day, cur_day);

        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && nz >= 0 && nz < h) {
                if (farm[ny][nx][nz] == 0) {
                    farm[ny][nx][nz] = 1;

                    q.emplace(nx, ny, nz, cur_day + 1);
                    tomato--;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, h;
    cin >> m >> n >> h;

    int day = 0;
    int tomato = 0;

    vector<vector<vector<int>>> farm(n, vector<vector<int>>(m, vector<int>(h)));
    queue<tuple<int, int, int, int>> q;

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                int& cell = farm[y][x][z];

                cin >> cell;
                
                if (cell == 0) {
                    tomato++;
                }
                else if (cell == 1) {
                    q.emplace(x, y, z, 0);
                }
            }
        }
    }

    bfs(n, m, h, day, tomato, farm, q);

    cout << (tomato == 0 ? day : -1) << '\n';

    return 0;
}