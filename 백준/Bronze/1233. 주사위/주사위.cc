#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int max_sum = s1 + s2 + s3;
    vector<int> cnt_sum(max_sum + 1, 0);
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                cnt_sum[i + j + k]++;
            }
        }
    }

    int best_sum = 0;
    int best_cnt = 0;
    for (int s = 3; s <= max_sum; s++) {
        if (cnt_sum[s] > best_cnt) {
            best_cnt = cnt_sum[s];
            best_sum = s;
        }
    }

    cout << best_sum;

    return 0;
}