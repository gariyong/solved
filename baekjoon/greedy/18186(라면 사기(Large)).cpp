// ���� : https://www.acmicpc.net/problem/18186
// ���� : ��� ���(Large)
// �˰��� : greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b, c;
    cin >> n >> b >> c; // n : ���� ��, b : ��ǰ ����, c : ��Ʈ �߰� ���

    // cost[0] : ��ǰ, cost[1] : 2�� ��Ʈ, cost[2] : 3�� ��Ʈ
    int cost[] = { b, b + c, b + 2 * c };
    vector<int> ramen(n);
    for (int i = 0; i < n; i++) cin >> ramen[i]; // �� ���忡�� �����ؾ� �ϴ� ��� ��

    // b < c �� ��� : ��Ʈ�� �����ϸ� ������ ��ιǷ� ��� ��� ��ǰ���� ����
    if (b < c) {
        long long total = 0;
        for (int i = 0; i < n; i++) total += (long long)ramen[i] * b;
        cout << total;

        return 0;
    }

    long long cost_sum = 0; // �� ���

    // 0 ~ n-3���� �ݺ�(3�� ��Ʈ ���Ÿ� ���)
    for (int i = 0; i < n - 2; i++) {
        if (ramen[i] == 0) continue; // �̹� ���� �Ϸ��� �Ѿ

        // i+1 ���� ����� i+2 ���� ��麸�� ������, 2�� ��Ʈ ���� ����
        if (ramen[i + 1] > ramen[i + 2]) {
            int two = min(ramen[i], ramen[i + 1] - ramen[i + 2]);
            ramen[i] -= two;        // i ���� ��� �� ����
            ramen[i + 1] -= two;    // i+1 ���� ��� �� ����
            cost_sum += (long long)two * cost[1]; // 2�� ��Ʈ ��� �߰�
        }

        // 3�� ��Ʈ ����
        int three = min({ ramen[i], ramen[i + 1], ramen[i + 2] }); // 3�� ��Ʈ ���� ������ �ִ� ��
        ramen[i] -= three;
        ramen[i + 1] -= three;
        ramen[i + 2] -= three;
        cost_sum += (long long)three * cost[2]; // 3�� ��Ʈ ��� �߰�

        // ���� i ���� ��� ��ǰ ����
        cost_sum += (long long)ramen[i] * cost[0];
        ramen[i] = 0; // ���� �Ϸ� ó��
    }

    // ������ �� ���� ó��(n-2,n-1)
    if (n >= 2) {
        int two = min(ramen[n - 2], ramen[n - 1]); // 2�� ��Ʈ ���� ������ �ִ� ��
        ramen[n - 2] -= two;
        ramen[n - 1] -= two;
        cost_sum += (long long)two * cost[1]; // 2�� ��Ʈ ��� �߰�
    }

    // ������ ���� ��ǰ ����
    if (ramen[n - 1] != 0) {
        cost_sum += (long long)ramen[n - 1] * cost[0];
    }
    if (ramen[n - 2] != 0) {
        cost_sum += (long long)ramen[n - 2] * cost[0];
    }

    cout << cost_sum; // �� ��� ���

    return 0;
}