#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
vector<int> cur;

void backtrack(int start) {
    if (cur.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << cur[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = start; i < nums.size(); i++) {
        if (prev == nums[i]) {
            continue;
        }

        cur.push_back(nums[i]);
        backtrack(i);
        cur.pop_back();
        prev = nums[i];
    }
}

int main() {
    cin >> n >> m;
    nums.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    backtrack(0);

    return 0;
}