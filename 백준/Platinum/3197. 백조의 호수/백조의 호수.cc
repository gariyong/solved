#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;

    return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a != b) parent[b] = a;
}

queue<pair<int, int>> bfs(vector<vector<char>>& lake,vector<vector<int>>& id,queue<pair<int, int>>& water,vector<int>& parent,vector<vector<bool>>& visit,int r, int c) {
    queue<pair<int, int>> next_water;

    while (!water.empty()) {
        auto [cur_y, cur_x] = water.front();
        water.pop();

        for (int k = 0; k < 4; k++) {
            int ny = cur_y + dy[k];
            int nx = cur_x + dx[k];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (visit[ny][nx]) continue;

            visit[ny][nx] = true;

            if (lake[ny][nx] == 'X') {
                lake[ny][nx] = '.';
                next_water.push({ ny, nx });

                for (int i = 0; i < 4; i++) {
                    int nny = ny + dy[i];
                    int nnx = nx + dx[i];

                    if (nny < 0 || nny >= r || nnx < 0 || nnx >= c) continue;
                    if (lake[nny][nnx] != 'X') {
                        unite(parent, id[ny][nx], id[nny][nnx]);
                    }
                }
            }
        }
    }

    return next_water;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> lake(r, vector<char>(c));
    vector<vector<int>> id(r, vector<int>(c));
    vector<int> parent(r * c);

    queue<pair<int, int>> water;
    vector<vector<bool>> visit(r, vector<bool>(c, false));

    vector<pair<int, int>> swan;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> lake[i][j];

            id[i][j] = i * c + j;
            parent[id[i][j]] = id[i][j];

            if (lake[i][j] != 'X') {
                water.push({ i, j });
                visit[i][j] = true;

                if (lake[i][j] == 'L')
                    swan.push_back({ i, j });
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (lake[i][j] == 'X') continue;

            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];

                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (lake[ny][nx] != 'X') {
                    unite(parent, id[i][j], id[ny][nx]);
                }
            }
        }
    }

    int day = 0;
    while (true) {
        int s1 = id[swan[0].first][swan[0].second];
        int s2 = id[swan[1].first][swan[1].second];

        if (find(parent, s1) == find(parent, s2))
            break;

        water = bfs(lake, id, water, parent, visit, r, c);
        day++;
    }

    cout << day;

    return 0;
}