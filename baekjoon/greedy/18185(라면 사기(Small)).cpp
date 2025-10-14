// 문제 : https://www.acmicpc.net/problem/18185
// 제목 : 라면 사기(Small)
// 알고리즘 : Greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; // n : 라면 공장 수

    int cost[] = { 3, 5, 7 }; // cost[0] : 단품, cost[1] : 2개 세트, cost[2] : 3개 세트
    vector<int> ramen(n);
    for (int i = 0; i < n; i++) cin >> ramen[i]; // 각 공장에서 구매해야 하는 라면 수

    int cost_sum = 0; // 총 비용

    // 0 ~ n-3까지 반복(3개 세트 구매를 고려)
    for (int i = 0; i < n - 2; i++) {
        if (ramen[i] == 0) continue; // 이미 구매 완료라면 건너뜀

        // i+1 공장 라면 수가 i+2보다 많으면 2개 세트 먼저 구매
        if (ramen[i + 1] > ramen[i + 2]) {
            int two = min(ramen[i], ramen[i + 1] - ramen[i + 2]); // i, i+1에서 구매할 개수
            ramen[i] -= two;        // i 공장 라면 수 차감
            ramen[i + 1] -= two;    // i + 1 공장 라면 수 차감
            cost_sum += two * cost[1]; // 2개 세트 비용 추가
        }

        // 3개 세트 구매
        int three = min({ ramen[i], ramen[i + 1], ramen[i + 2] }); // 구매 가능한 최대 수
        ramen[i] -= three;
        ramen[i + 1] -= three;
        ramen[i + 2] -= three;
        cost_sum += three * cost[2]; // 3개 세트 비용 추가

        // 남은 i 공장 라면 단품 구매
        cost_sum += ramen[i] * cost[0];
        ramen[i] = 0;
    }

    // 마지막 두 공장 처리(n-2, n-1)
    if (n >= 2) {
        int two = min(ramen[n - 2], ramen[n - 1]); // 2개 세트 구매 가능한 최대 수
        ramen[n - 2] -= two;
        ramen[n - 1] -= two;
        cost_sum += two * cost[1]; // 2개 세트 비용 추가
    }

    // 마지막 공장 단품 구매
    if (ramen[n - 1] != 0) {
        cost_sum += ramen[n - 1] * cost[0];
    }
    if (ramen[n - 2] != 0) {
        cost_sum += ramen[n - 2] * cost[0];
    }

    cout << cost_sum; // 결과 출력

    return 0;
}