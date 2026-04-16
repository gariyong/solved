#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e15;

long long tsp(const vector<vector<long long>>& node_cost, vector<vector<long long>>& dp, int pos, long long visit, int n) {
    if (visit == (1LL << n) - 1) {
        if (node_cost[pos][0] == 0) return INF;
        return node_cost[pos][0];
    }

    if (dp[pos][visit] != -1) return dp[pos][visit];

    dp[pos][visit] = INF;

    for (int next = 0; next < n; next++) {
        if ((visit & (1LL << next)) || node_cost[pos][next] == 0) continue;
        long long cost = node_cost[pos][next] + tsp(node_cost, dp, next, visit | (1LL << next), n);
        dp[pos][visit] = min(dp[pos][visit], cost);
    }

    return dp[pos][visit];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<long long>> node_cost(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> node_cost[i][j];

    vector<vector<long long>> dp(n, vector<long long>((1LL << n), -1));

    long long result = tsp(node_cost, dp, 0, 1LL << 0, n);

    cout << result;

    return 0;
}