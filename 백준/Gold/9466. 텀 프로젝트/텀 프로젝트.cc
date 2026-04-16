#include <iostream>
#include <vector>

using namespace std;

int graph[100001];
int visit[100001];
int cnt;

void dfs(int idx) {
    visit[idx] = 1;
    int next = graph[idx];

    if (visit[next] == 0) {
        dfs(next);
    }
    else if (visit[next] == 1) {
        int temp = next;

        while (temp != idx) {
            cnt++;
            temp = graph[temp];
        }
        cnt++;
    }

    visit[idx] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> graph[i];
            visit[i] = 0;
        }

        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (visit[i] == 0) {
                dfs(i);
            }
        }

        cout << n - cnt << "\n";
    }

    return 0;
}