#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, w, L;
    cin >> n >> w >> L;

    queue<int> trucks;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        trucks.push(x);
    }

    queue<int> bridge;
    for (int i = 0; i < w; i++) bridge.push(0);

    int time = 0;
    int bridge_w = 0;

    while (true) {
        time++;

        bridge_w -= bridge.front();
        bridge.pop();

        if (!trucks.empty()) {
            if (bridge_w + trucks.front() <= L) {
                bridge_w += trucks.front();
                bridge.push(trucks.front());
                trucks.pop();
            }
            else {
                bridge.push(0);
            }
        }

        if (trucks.empty() && bridge_w == 0) break;
    }

    cout << time;

    return 0;
}