#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int bfs(vector<vector<char>>& map, vector<bool>& keys, int h, int w) {
    int cnt = 0;
    vector<vector<bool>> visit(h, vector<bool>(w, false));
    queue<pair<int, int>> q;
    vector<queue<pair<int, int>>> door(26);

    for (int i = 0; i < h; i++) {
        for (int j : {0, w - 1}) {
            if (map[i][j] != '*' && !visit[i][j]) {
                q.push({ i,j });
                visit[i][j] = true;
            }
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i : {0, h - 1}) {
            if (map[i][j] != '*' && !visit[i][j]) {
                q.push({ i,j });
                visit[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        char cur = map[y][x];

        if ('A' <= cur && cur <= 'Z') {
            int idx = cur - 'A';

            if (!keys[idx]) {
                door[idx].push({ y,x });
                continue;
            }
        }

        if ('a' <= cur && cur <= 'z') {
            int idx = cur - 'a';
            if (!keys[idx]) {
                keys[idx] = true;
                
                while (!door[idx].empty()) {
                    auto [dy_, dx_] = door[idx].front();
                    door[idx].pop();
                    q.push({ dy_, dx_ });
                }
            }
        }

        if (cur == '$') cnt++;

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (map[ny][nx] != '*' && !visit[ny][nx]) {
                visit[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int h, w;
        cin >> h >> w;
       
        vector<vector<char>> map(h, vector<char>(w));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> map[i][j];

        string str;
        cin >> str;
       
        vector<bool> keys(26, false);
        if (str[0] != '0') {
            for (char c : str) keys[c - 'a'] = true;
        }

        cout << bfs(map, keys, h, w) << '\n';
    }

    return 0;
}