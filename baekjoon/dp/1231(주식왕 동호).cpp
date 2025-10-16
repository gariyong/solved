// ���� : https://www.acmicpc.net/problem/1231
// ���� : �ֽĿ� ��ȣ
// �˰��� : dp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // c : �ֽ� ���� ��
    // d : �ŷ� �� ��
    // capital : �ʱ� �ں�
    int c, d, capital;
    cin >> c >> d >> capital;

    // �ֽ� ���� �Է�
    vector<vector<int>> stocks(c, vector<int>(d));
    for (int i = 0; i < c; i++)
        for (int j = 0; j < d; j++)
            cin >> stocks[i][j];

    // �� ������ �ŷ��� �ݺ�
    for (int day = 0; day < d - 1; day++) {
        vector<int> dp(capital + 1, 0);
        //dp[money] : ���� �ں� money�� �Ϸ� ���� ���� �� �ִ� �ִ� ����

        for (int i = 0; i < c; i++) {
            int buy = stocks[i][day]; // ���� ����
            int sell = stocks[i][day + 1]; // ���� ����
            int benefit = sell - buy; // �ż� �� �ŵ����� �� ��� ����

            // ���� ���� �ں� �������� �ŷ� ������ ��츦 ��� Ž��
            for (int money = buy; money <= capital; money++) {
                // dp[money - buy] : buy�� ������ ������ �ں����� ���� �� �ִ� �ִ� ����
                // benefit�� ���� ���� ���� dp[money] �� ū ������ ����
                dp[money] = max(dp[money], dp[money - buy] + benefit);
            }
        }

        // �Ϸ� �ŷ� �� ���� �ں��� �ִ� ���� ����
        // ���� �� �ŷ����� ������ capital ��� ����
        capital += dp[capital];
    }

    cout << capital; // ��� ���

    return 0;
}