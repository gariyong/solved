// 문제 : https://www.acmicpc.net/problem/10942
// 제목 : 팰린드롬?

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = true;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = true;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;

            if (arr[i] == arr[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << (dp[s][e] ? 1 : 0) << '\n';
    }

    return 0;
}
