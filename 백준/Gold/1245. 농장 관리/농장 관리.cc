#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

bool bfs(vector<vector<int>>& farm, vector<vector<int>>& visit, int n, int m, int start_x, int start_y) {

    queue<pair<int, int>> q;
    q.push({ start_x, start_y });
    visit[start_x][start_y] = 1;

    int high = farm[start_x][start_y];
    bool is_peak = true;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int k = 0; k < 8; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (farm[ny][nx] > high) {
                is_peak = false;
            }

            if (visit[ny][nx] == 0 && farm[ny][nx] == high) {
                visit[ny][nx] = 1;
                q.push({ ny, nx });
            }
        }
    }

    return is_peak;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> farm(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> farm[i][j];
        }
    }

    vector<vector<int>> visit(n, vector<int>(m, 0));
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visit[i][j] == 0) {
                if (bfs(farm, visit, n, m, i, j)) {
                    result++;
                }
            }
        }
    }

    cout << result;

    return 0;
}