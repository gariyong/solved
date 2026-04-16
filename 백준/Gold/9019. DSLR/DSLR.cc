#include <iostream>
#include <string>
#include <queue>

using namespace std;

void bfs(int a, int b) {
    bool visited[10000] = { false };
    queue<pair<int, string>> q;

    q.push({ a, "" });
    visited[a] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        string com = q.front().second;
        q.pop();

        if (cur == b) {
            cout << com << '\n';
            return;
        }

        int d = (cur * 2) % 10000;
        if (!visited[d]) {
            visited[d] = true;
            q.push({ d, com + 'D' });
        }

        int s = (cur == 0) ? 9999 : cur - 1;
        if (!visited[s]) {
            visited[s] = true;
            q.push({ s, com + 'S' });
        }

        int l = (cur % 1000) * 10 + cur / 1000;
        if (!visited[l]) {
            visited[l] = true;
            q.push({ l, com + 'L' });
        }

        int r = (cur % 10) * 1000 + cur / 10;
        if (!visited[r]) {
            visited[r] = true;
            q.push({ r, com + 'R' });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int a, b;

        cin >> a >> b;
        bfs(a, b);
    }

    return 0;
}