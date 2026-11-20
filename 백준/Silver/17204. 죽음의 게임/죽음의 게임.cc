#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> next(n);
    for (int i = 0; i < n; i++) cin >> next[i];

    int now = 0;
    int cnt = 0;
    vector<bool> visited(n, false);

    while (!visited[now]) {
        if (now == k) {
            cout << cnt;
            
            return 0;
        }

        visited[now] = true;
        now = next[now];
        cnt++;
    }

    cout << -1;
    
    return 0;
}