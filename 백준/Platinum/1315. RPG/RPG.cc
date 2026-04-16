#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct quest {
    int STR;
    int INT;
    int PNT;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<quest> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i].STR >> q[i].INT >> q[i].PNT;
    }

    vector<vector<int>> dp(1001, vector<int>(1001, -1));
    dp[1][1] = 0;
    int clear = 0;

    for (int s = 1; s <= 1000; s++) {
        for (int i = 1; i <= 1000; i++) {
            if (dp[s][i] == -1) continue;

            int total_pnt = 0;
            int cur_clear = 0;

            for (int k = 0; k < n; k++) {
                if (q[k].STR <= s || q[k].INT <= i) {
                    total_pnt += q[k].PNT;
                    cur_clear++;
                }
            }

            clear = max(clear, cur_clear);

            int remain_pnt = total_pnt - (s - 1 + i - 1);

            if (remain_pnt > 0) {
                if (s < 1000) dp[s + 1][i] = max(dp[s + 1][i], cur_clear);
                if (i < 1000) dp[s][i + 1] = max(dp[s][i + 1], cur_clear);
            }
        }
    }

    cout << clear;

    return 0;
}