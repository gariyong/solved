#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, L;
    cin >> k >> L;

    vector<string> order(L);
    unordered_map<string, int> last;

    for (int i = 0; i < L; i++) {
        cin >> order[i];
        last[order[i]] = i;
    }

    int cnt = 0;
    for (int i = 0; i < L; i++) {
        if (last[order[i]] == i) {
            cout << order[i] << '\n';
            cnt++;
        }
        if (cnt == k) break;
    }

    return 0;
}