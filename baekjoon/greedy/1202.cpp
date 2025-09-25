// 문제 : https://www.acmicpc.net/problem/1202
// 제목 : 보석 도둑

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Gem {
    int weight;
    int value;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Gem> gems(n);
    for (int i = 0; i < n; i++) {
        cin >> gems[i].weight >> gems[i].value;
    }

    vector<int> bag(k);
    for (int i = 0; i < k; i++) cin >> bag[i];

    sort(gems.begin(), gems.end(),
        [](const Gem& a, const Gem& b) { return a.weight < b.weight; });
    sort(bag.begin(), bag.end());

    priority_queue<int> q;
    long long sum = 0;
    int idx = 0;

    for (int cap : bag) {
        while (idx < n && gems[idx].weight <= cap) {
            q.push(gems[idx].value);
            idx++;
        }
        if (!q.empty()) {
            sum += q.top();
            q.pop();
        }
    }

    cout << sum;

    return 0;
}