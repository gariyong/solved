#include <iostream>

using namespace std;

int main() {
    int x, m, M, t, r;
    cin >> x >> m >> M >> t >> r;

    if (m + t > M) {
        cout << -1;
        
        return 0;
    }

    int cur = m;
    int work = 0;
    int time = 0;
    while (work < x) {
        if (cur + t <= M) {
            cur += t;
            work++;
        }
        else {
            cur -= r;
            if (cur < m) cur = m;
        }
        time++;
    }

    cout << time;

    return 0;
}