// 문제 : https://www.acmicpc.net/problem/18186
// 제목 : 라면 사기(Large)
// 알고리즘 : greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b, c;
    cin >> n >> b >> c; // n : 공장 수, b : 단품 가격, c : 세트 추가 비용

    // cost[0] : 단품, cost[1] : 2개 세트, cost[2] : 3개 세트
    int cost[] = { b, b + c, b + 2 * c };
    vector<int> ramen(n);
    for (int i = 0; i < n; i++) cin >> ramen[i]; // 각 공장에서 구매해야 하는 라면 수

    // b < c 인 경우 : 세트를 구매하면 오히려 비싸므로 모든 라면 단품으로 구매
    if (b < c) {
        long long total = 0;
        for (int i = 0; i < n; i++) total += (long long)ramen[i] * b;
        cout << total;

        return 0;
    }

    long long cost_sum = 0; // 총 비용

    // 0 ~ n-3까지 반복(3개 세트 구매를 고려)
    for (int i = 0; i < n - 2; i++) {
        if (ramen[i] == 0) continue; // 이미 구매 완료라면 넘어감

        // i+1 공장 라면이 i+2 공장 라면보다 많으면, 2개 세트 먼저 구매
        if (ramen[i + 1] > ramen[i + 2]) {
            int two = min(ramen[i], ramen[i + 1] - ramen[i + 2]);
            ramen[i] -= two;        // i 공장 라면 수 차감
            ramen[i + 1] -= two;    // i+1 공장 라면 수 차감
            cost_sum += (long long)two * cost[1]; // 2개 세트 비용 추가
        }

        // 3개 세트 구매
        int three = min({ ramen[i], ramen[i + 1], ramen[i + 2] }); // 3개 세트 구매 가능한 최대 수
        ramen[i] -= three;
        ramen[i + 1] -= three;
        ramen[i + 2] -= three;
        cost_sum += (long long)three * cost[2]; // 3개 세트 비용 추가

        // 남은 i 공장 라면 단품 구매
        cost_sum += (long long)ramen[i] * cost[0];
        ramen[i] = 0; // 구매 완료 처리
    }

    // 마지막 두 공장 처리(n-2,n-1)
    if (n >= 2) {
        int two = min(ramen[n - 2], ramen[n - 1]); // 2개 세트 구매 가능한 최대 수
        ramen[n - 2] -= two;
        ramen[n - 1] -= two;
        cost_sum += (long long)two * cost[1]; // 2개 세트 비용 추가
    }

    // 마지막 공장 단품 구매
    if (ramen[n - 1] != 0) {
        cost_sum += (long long)ramen[n - 1] * cost[0];
    }
    if (ramen[n - 2] != 0) {
        cost_sum += (long long)ramen[n - 2] * cost[0];
    }

    cout << cost_sum; // 총 비용 출력

    return 0;
}