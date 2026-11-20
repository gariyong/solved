#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    deque<int> q;
    for (int i = 1; i <= n; i++) {
        q.push_back(i);
    }

    int result = 0;

    while (m--) {
        int x;
        cin >> x;

        int idx = 0;
        for (int i = 0; i < q.size(); i++) {
            if (q[i] == x) {
                idx = i;
                break;
            }
        }

        if (idx <= q.size() / 2) {
            while (idx--) {
                q.push_back(q.front());
                q.pop_front();
                result++;
            }
        } else {
            int cnt = q.size() - idx;
            while (cnt--) {
                q.push_front(q.back());
                q.pop_back();
                result++;
            }
        }

        q.pop_front();
    }

    cout << result;
    
    return 0;
}