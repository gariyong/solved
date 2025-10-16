// 문제 : https://www.acmicpc.net/problem/1231
// 제목 : 주식왕 동호
// 알고리즘 : dp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // c : 주식 종목 수
    // d : 거래 일 수
    // capital : 초기 자본
    int c, d, capital;
    cin >> c >> d >> capital;

    // 주식 가격 입력
    vector<vector<int>> stocks(c, vector<int>(d));
    for (int i = 0; i < c; i++)
        for (int j = 0; j < d; j++)
            cin >> stocks[i][j];

    // 각 날마다 거래를 반복
    for (int day = 0; day < d - 1; day++) {
        vector<int> dp(capital + 1, 0);
        //dp[money] : 현재 자본 money로 하루 동안 얻을 수 있는 최대 수익

        for (int i = 0; i < c; i++) {
            int buy = stocks[i][day]; // 오늘 가격
            int sell = stocks[i][day + 1]; // 내일 가격
            int benefit = sell - buy; // 매수 후 매도했을 때 얻는 이익

            // 현재 가진 자본 기준으로 거래 가능한 경우를 모두 탐색
            for (int money = buy; money <= capital; money++) {
                // dp[money - buy] : buy를 제외한 나머지 자본으로 얻을 수 있는 최대 수익
                // benefit을 더한 값과 현재 dp[money] 중 큰 값으로 갱신
                dp[money] = max(dp[money], dp[money - buy] + benefit);
            }
        }

        // 하루 거래 후 실제 자본에 최대 수익 누적
        // 다음 날 거래에서 누적된 capital 사용 가능
        capital += dp[capital];
    }

    cout << capital; // 결과 출력

    return 0;
}