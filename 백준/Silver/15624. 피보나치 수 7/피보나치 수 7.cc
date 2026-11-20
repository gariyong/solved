#include <iostream>

using namespace std;

const int MOD = 1000000007;
int dp[1000001];

void make_pivo() {
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    make_pivo();
    cout << dp[n];

    return 0;
}