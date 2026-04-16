#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int y, x, broken;
};

int bfs(const vector<vector<char>>& graph, int n, int m) {
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, -1)));
    queue<Node> q;

    int dy[4] = { -1, 1, 0, 0 };
    int dx[4] = { 0, 0, -1, 1 };

    q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int y = cur.y;
        int x = cur.x;
        int broken = cur.broken;

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }

            if (graph[ny][nx] == '0' && dist[ny][nx][broken] == -1) {
                dist[ny][nx][broken] = dist[y][x][broken] + 1;
                q.push({ ny, nx, broken });
            }

            if (graph[ny][nx] == '1' && broken == 0 && dist[ny][nx][1] == -1) {
                dist[ny][nx][1] = dist[y][x][broken] + 1;
                q.push({ ny, nx, 1 });
            }
        }
    }

    int res1 = dist[n - 1][m - 1][0];
    int res2 = dist[n - 1][m - 1][1];

    if (res1 == -1 && res2 == -1) {
        return -1;
    }
    else if (res1 == -1) {
        return res2;
    }
    else if (res2 == -1) {
        return res1;
    }
    else {
        return min(res1, res2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int result = bfs(graph, n, m);
    cout << result;

    return 0;
}