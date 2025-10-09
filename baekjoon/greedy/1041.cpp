// ���� : https://www.acmicpc.net/problem/1041
// ���� : �ֻ���

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n; // �ֻ����� �� ���� ���� �ֻ��� ����

    vector<long long> dice(6);
    for (int i = 0; i < 6; i++) {
        cin >> dice[i]; // �ֻ��� �� ���� ���� �� �Է�
    }

    // �ֻ����� �ϳ����� ��
    // �� �鸸 �ٴڿ� ���, ������ 5���� ����
    if (n == 1) {
        long long sum = 0, max_val = 0;
        for (long long x : dice) {
            sum += x;
            max_val = max(max_val, x); // ���� ū ���� �ٴ����� ����
        }
        cout << sum - max_val; // ���̴� 5���� �� = ��ü �� - �ִ� �鰪

        return 0;
    }

    // �� �鿡�� ���� ���� �� ã��
    long long one_face_min = dice[0];
    for (int i = 1; i < 6; i++) {
        one_face_min = min(one_face_min, dice[i]);
    }

    // ���ֺ��� �� : (0,5), (1,4), (2,3)
    // ����, ���ÿ� ���� �� �ִ� �� ���� ������ �̸� ����
    vector<pair<int, int>> two_face = {
        {0,1},{0,2},{0,3},{0,4},
        {1,2},{1,3},{1,5},
        {2,4},{2,5},
        {3,4},{3,5},
        {4,5}
    };

    // �� ���� ���ÿ� ���̴� ����� �ּ� �� ã��
    long long two_face_min = 1e9;
    for (auto& tf : two_face) {
        two_face_min = min(two_face_min, dice[tf.first] + dice[tf.second]);
    }

    // �� ���� ���ÿ� ���̴� ���(�𼭸� �������� ��ġ�� �ֻ���)
    // ������ ������ ���� ����
    vector<vector<int>> three_face = {
        {0,1,2},{0,1,3},{0,2,4},{0,3,4},
        {5,1,2},{5,1,3},{5,2,4},{5,3,4}
    };

    // �� ���� ���ÿ� ���̴� ����� �ּ� �� ã��
    long long three_face_min = 1e9;
    for (auto& tf : three_face) {
        three_face_min = min(three_face_min, dice[tf[0]] + dice[tf[1]] + dice[tf[2]]);
    }

    // �� �鸸 ���̴� �ֻ��� = ���� ��� �κ� + ���� �׵θ� �κ�
    // ���� ��� �κ� : (n - 2)^2
    // �Ʒ��� �𼭸� �κ� : (n - 2) * (n - 1) * 4
    long long one_face_cnt = (n - 2) * (n - 2) + (n - 2) * (n - 1) * 4;
    
    // �� ���� ���̴� �ֻ��� : ���� �𼭸� �κ� + �Ʒ��� �𼭸� �κ�
    // ���� �𼭸� �κ� : (n - 2) * 4
    // �Ʒ��� �𼭸� �κ� : (n - 1) * 4
    long long two_face_cnt = (n - 2) * 4 + (n - 1) * 4;

    // �� ���� ���̴� �ֻ��� = �������� ��ġ�� 4��
    long long three_face_cnt = 4;

    // ���� ��� = �� ����� ���� �ش��ϴ� �ּҰ� * ������ ��
    long long result = one_face_min * one_face_cnt
        + two_face_min * two_face_cnt
        + three_face_min * three_face_cnt;

    cout << result; // ��� ���

    return 0;
}