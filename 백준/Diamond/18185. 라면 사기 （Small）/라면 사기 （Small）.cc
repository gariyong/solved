#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int cost[] = { 3, 5, 7 };
    vector<int> ramen(n);
    for (int i = 0; i < n; i++) cin >> ramen[i];

    int cost_sum = 0;

    for (int i = 0; i < n - 2; i++) {
        if (ramen[i] == 0) continue;

        if (ramen[i + 1] > ramen[i + 2]) {
            int two = min(ramen[i], ramen[i + 1] - ramen[i + 2]);
            ramen[i] -= two;
            ramen[i + 1] -= two;
            cost_sum += two * cost[1];
        }

        int three = min({ ramen[i], ramen[i + 1], ramen[i + 2] });
        ramen[i] -= three;
        ramen[i + 1] -= three;
        ramen[i + 2] -= three;
        cost_sum += three * cost[2];

        cost_sum += ramen[i] * cost[0];
        ramen[i] = 0;
    }

    if (n >= 2) {
        int two = min(ramen[n - 2], ramen[n - 1]);
        ramen[n - 2] -= two;
        ramen[n - 1] -= two;
        cost_sum += two * cost[1];
    }

    if (ramen[n - 1] != 0) {
        cost_sum += ramen[n - 1] * cost[0];
    }
    if (ramen[n - 2] != 0) {
        cost_sum += ramen[n - 2] * cost[0];
    }
    
    cout << cost_sum;
    
    return 0;
}