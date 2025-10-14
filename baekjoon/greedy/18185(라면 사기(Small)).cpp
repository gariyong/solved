// ���� : https://www.acmicpc.net/problem/18185
// ���� : ��� ���(Small)
// �˰��� : Greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; // n : ��� ���� ��

    int cost[] = { 3, 5, 7 }; // cost[0] : ��ǰ, cost[1] : 2�� ��Ʈ, cost[2] : 3�� ��Ʈ
    vector<int> ramen(n);
    for (int i = 0; i < n; i++) cin >> ramen[i]; // �� ���忡�� �����ؾ� �ϴ� ��� ��

    int cost_sum = 0; // �� ���

    // 0 ~ n-3���� �ݺ�(3�� ��Ʈ ���Ÿ� ���)
    for (int i = 0; i < n - 2; i++) {
        if (ramen[i] == 0) continue; // �̹� ���� �Ϸ��� �ǳʶ�

        // i+1 ���� ��� ���� i+2���� ������ 2�� ��Ʈ ���� ����
        if (ramen[i + 1] > ramen[i + 2]) {
            int two = min(ramen[i], ramen[i + 1] - ramen[i + 2]); // i, i+1���� ������ ����
            ramen[i] -= two;        // i ���� ��� �� ����
            ramen[i + 1] -= two;    // i + 1 ���� ��� �� ����
            cost_sum += two * cost[1]; // 2�� ��Ʈ ��� �߰�
        }

        // 3�� ��Ʈ ����
        int three = min({ ramen[i], ramen[i + 1], ramen[i + 2] }); // ���� ������ �ִ� ��
        ramen[i] -= three;
        ramen[i + 1] -= three;
        ramen[i + 2] -= three;
        cost_sum += three * cost[2]; // 3�� ��Ʈ ��� �߰�

        // ���� i ���� ��� ��ǰ ����
        cost_sum += ramen[i] * cost[0];
        ramen[i] = 0;
    }

    // ������ �� ���� ó��(n-2, n-1)
    if (n >= 2) {
        int two = min(ramen[n - 2], ramen[n - 1]); // 2�� ��Ʈ ���� ������ �ִ� ��
        ramen[n - 2] -= two;
        ramen[n - 1] -= two;
        cost_sum += two * cost[1]; // 2�� ��Ʈ ��� �߰�
    }

    // ������ ���� ��ǰ ����
    if (ramen[n - 1] != 0) {
        cost_sum += ramen[n - 1] * cost[0];
    }
    if (ramen[n - 2] != 0) {
        cost_sum += ramen[n - 2] * cost[0];
    }

    cout << cost_sum; // ��� ���

    return 0;
}