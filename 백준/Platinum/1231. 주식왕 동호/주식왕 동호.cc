#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c, d, capital;
    cin >> c >> d >> capital;

    vector<vector<int>> stocks(c, vector<int>(d));
    for (int i = 0; i < c; i++)
        for (int j = 0; j < d; j++)
            cin >> stocks[i][j];

    for (int day = 0; day < d - 1; day++) {
        vector<int> dp(capital + 1, 0);

        for (int i = 0; i < c; i++) {
            int buy = stocks[i][day];
            int sell = stocks[i][day + 1];
            int benefit = sell - buy;

            for (int money = buy; money <= capital; money++) {
                dp[money] = max(dp[money], dp[money - buy] + benefit);
            }
        }

        capital += dp[capital];
    }

    cout << capital;

    return 0;
}