#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int t;
    cin >> t;

    vector<vector<bool>> blocked_right(m + 1, vector<bool>(n + 1, false));
    vector<vector<bool>> blocked_up(m + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < t; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {
            blocked_up[max(y1, y2)][x1] = true;
        }
        else {
            blocked_right[y1][max(x1, x2)] = true;
        }
    }

    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    dp[0][0] = 1;

    for (int y = 0; y <= m; y++) {
        for (int x = 0; x <= n; x++) {
            if (x > 0 && !blocked_right[y][x])
                dp[y][x] += dp[y][x - 1];
            if (y > 0 && !blocked_up[y][x])
                dp[y][x] += dp[y - 1][x];
        }
    }

    cout << dp[m][n];
    
    return 0;
}