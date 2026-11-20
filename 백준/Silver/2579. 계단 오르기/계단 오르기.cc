#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* stair = new int[n + 1];
    int* dp = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> stair[i];
    }

    dp[0] = 0;
    dp[1] = stair[1];
    if (n >= 2) dp[2] = stair[1] + stair[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]) + stair[i];
    }

    cout << dp[n];

    delete[] stair;
    delete[] dp;

    return 0;
}