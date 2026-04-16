#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

class Cordinate {
public:
    int x;
    int y;
    Cordinate(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

bool canReach(const Cordinate& a, const Cordinate& b) {
    return abs(a.x - b.x) + abs(a.y - b.y) <= 1000;
}

bool bfs(vector<Cordinate>& places, int n) {
    queue<int> q;
    vector<bool> visited(n + 2, false);

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == n + 1)
            return true;

        for (int i = 0; i < n + 2; i++) {
            if (!visited[i] && canReach(places[curr], places[i])) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int x, y;
        vector<Cordinate> v;

        cin >> x >> y;
        v.push_back(Cordinate(x, y));

        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v.push_back(Cordinate(x, y));
        }

        cin >> x >> y;
        v.push_back(Cordinate(x, y));

        if (bfs(v, n)) {
            cout << "happy\n";
        }
        else {
            cout << "sad\n";
        }
    }

    return 0;
}