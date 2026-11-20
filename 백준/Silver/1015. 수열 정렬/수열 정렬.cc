#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        seq[v[i].second] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << seq[i] << " ";
    }

    return 0;
}