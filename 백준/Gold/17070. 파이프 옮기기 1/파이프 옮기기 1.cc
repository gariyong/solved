#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int result;

    cin >> n;

    vector<vector<int>> home(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> home[i][j];

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3, 0)));
    dp[1][2][0] = 1;

    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            if (home[y][x] == 1) continue;

            if (x - 1 >= 1) {
                dp[y][x][0] += dp[y][x - 1][0] + dp[y][x - 1][2];
            }

            if (y - 1 >= 1) {
                dp[y][x][1] += dp[y - 1][x][1] + dp[y - 1][x][2];
            }

            if (y - 1 >= 1 && x - 1 >= 1) {
                if (home[y - 1][x] == 0 && home[y][x - 1] == 0) {
                    dp[y][x][2] += dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2];
                }
            }
        }
    }

    result = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    cout << result << "\n";

    return 0;
}