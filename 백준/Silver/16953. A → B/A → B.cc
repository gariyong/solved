#include <iostream>
#include <queue>

using namespace std;

void bfs(long long A, long long B) {
    queue<pair<long long, int>> q;
    q.push({ A, 1 });

    while (!q.empty()) {
        long long cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == B) {
            cout << cnt;
            
            return;
        }

        if (cur * 2 <= B) {
            q.push({ cur * 2, cnt + 1 });
        }

        if (cur * 10 + 1 <= B) {
            q.push({ cur * 10 + 1, cnt + 1 });
        }
    }

    cout << -1;
}

int main() {
    long long A, B;

    cin >> A >> B;
    
    bfs(A, B);
    
    return 0;
}