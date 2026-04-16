#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        cnt[nums[i]]++;
    }

    vector<int> values;
    for (auto& x : cnt) {
        values.push_back(x.first);
    }

    vector<int> answer;
    while (n > 0) {
        for (int i = 0; i < values.size() && n > 0; i++) {
            int v = values[i];
            if (cnt[v] == 0) continue;

            if (cnt.count(v + 1) && cnt[v + 1] > 0) {
                bool find = false;

                for (int j = i + 1; j < values.size(); j++) {
                    if (values[j] >= v + 2 && cnt[values[j]] > 0) {
                        while (cnt[v] > 0) {
                            answer.push_back(v);
                            cnt[v]--; n--;
                        }
                        answer.push_back(values[j]);
                        cnt[values[j]]--; n--;
                        find = true;
                        break;
                    }
                }

                if (!find) {
                    answer.push_back(v + 1);
                    cnt[v + 1]--; n--;
                }
                else {
                    while (cnt[v] > 0) {
                        answer.push_back(v);
                        cnt[v]--; n--;
                    }
                }
            }
            else {
                while (cnt[v] > 0) {
                    answer.push_back(v);
                    cnt[v]--; n--;
                }
            }
        }
    }

    for (int x : answer) {
        cout << x << ' ';
    }
    
    return 0;
}