#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Node {
    int y, x, dist, broken;
};

void bfs(vector<vector<char>>& graph, int n, int m) {
    vector<vector<vector<bool>>> visit(n + 1, vector<vector<bool>>(m + 1, vector<bool>(2, false)));
    queue<Node> q;

    q.push({ 1, 1, 1, 0 });
    visit[1][1][0] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.y == n && cur.x == m) {
            cout << cur.dist;

            return;
        }

        for (int k = 0; k < 4; k++) {
            int ny = cur.y + dy[k];
            int nx = cur.x + dx[k];

            if (ny < 1 || ny > n || nx < 1 || nx > m) continue;

            if (graph[ny][nx] == '0' && !visit[ny][nx][cur.broken]) {
                visit[ny][nx][cur.broken] = true;
                q.push({ ny, nx, cur.dist + 1, cur.broken });
            }
            else if (graph[ny][nx] == '1' && cur.broken == 0 && !visit[ny][nx][1]) {
                visit[ny][nx][1] = true;
                q.push({ ny, nx, cur.dist + 1, 1 });
            }
        }
    }

    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> graph(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
        }
    }

    bfs(graph, n, m);

    return 0;
}