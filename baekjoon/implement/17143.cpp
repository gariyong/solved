// ���� : https://www.acmicpc.net/problem/17143
// ���� : ���ÿ�
// ����, �ùķ��̼� ����
// �� �̵���Ű��, ���ò��� �� ���� �̵��ϸ� ���� ����� �� ��� ������ �ùķ��̼���

#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

// ��, ��, ��, �� �̵��� ���� ���� ���� (0�� �ε����� ��� ����)
const int dr[] = { 0, -1, 1, 0, 0 }; // 1: ��, 2: �Ʒ�, 3: ������, 4: ����
const int dc[] = { 0, 0, 0, 1, -1 };

// ��� ����ü ����
struct Shark {
    pair<int, int> pos; // ���� ��ġ (��, ��)
    int speed;          // �̵� �ӷ�
    int head;           // �̵� ���� (1~4)
    int size;           // ��� ũ��
};

// �� �̵���Ű�� �Լ�
tuple<int, int, int> move_shark(Shark shark, int r, int c) {
    int p_r = shark.pos.first;
    int p_c = shark.pos.second;
    int s = shark.speed;
    int d = shark.head;

    int period; // ��� �̵��� �ֱ� (�ݺ��Ǵ� ����)
    if (d == 1 || d == 2) { // ��/�Ʒ� �̵�
        period = 2 * (r - 1);
        if (period == 0) return { p_r, p_c, d }; // ���� 1�̸� �̵� ���ʿ�
    }
    else { // ������/���� �̵�
        period = 2 * (c - 1);
        if (period == 0) return { p_r, p_c, d }; // ���� 1�̸� �̵� ���ʿ�
    }

    s %= period; // �ֱ� ����: �ݺ��Ǵ� ������ ���

    int nr = p_r;
    int nc = p_c;
    int nd = d;

    // ��� �̵� �ùķ��̼�
    while (s > 0) {
        nr += dr[nd];
        nc += dc[nd];
        s--;

        // ��迡 �����ϸ� ���� ����
        if (nd == 1 && nr < 0) { // ���� �̵� �� ��� ����
            nr = 1;
            nd = 2; // �Ʒ��� ���� ��ȯ
        }
        else if (nd == 2 && nr >= r) { // �Ʒ��� �̵� �� ��� ����
            nr = r - 2;
            nd = 1; // ���� ���� ��ȯ
        }
        else if (nd == 4 && nc < 0) { // ���� �̵� �� ��� ����
            nc = 1;
            nd = 3; // ���������� ���� ��ȯ
        }
        else if (nd == 3 && nc >= c) { // ������ �̵� �� ��� ����
            nc = c - 2;
            nd = 4; // �������� ���� ��ȯ
        }
    }

    return { nr, nc, nd }; // �̵� �� ��ġ�� ���� ��ȯ
}

// ���� �ùķ��̼� �Լ�
int fishing(vector<vector<int>>& sea, vector<Shark>& sharks, int r, int c, int m) {
    int size_sum = 0; // ���� ��� ũ�� ��

    // ���ò��� 0������ c-1������ �̵�
    for (int fisher = 0; fisher < c; fisher++) {
        int target = -1; // ���� ������ ���� ��� �ε���

        // ���� ������ ���� ����� ��� ã��
        for (int i = 0; i < m; i++) {
            if (sharks[i].size == 0) continue; // �̹� ���� ���� ����

            if (sharks[i].pos.second == fisher) { // ���� ���� �ִ� ���
                if (target == -1) {
                    target = i; // ù ��° �߰� ���
                }
                else {
                    // �� ���� �ִ� �� ����
                    if (sharks[target].pos.first > sharks[i].pos.first) {
                        target = i;
                    }
                }
            }
        }

        // ��� ���
        if (target != -1) {
            size_sum += sharks[target].size; // ũ�� �ջ�
            sharks[target].size = 0;         // ���� ��� ǥ��
        }

        // ��� �̵� �� ���ο� �ٴ� ���� ����
        vector<vector<int>> new_sea(r, vector<int>(c, -1));
        for (int i = 0; i < m; i++) {
            if (sharks[i].size == 0) continue; // ���� ��� ����

            auto [nr, nc, nd] = move_shark(sharks[i], r, c);

            sharks[i].pos = { nr, nc };
            sharks[i].head = nd;

            int& cell = new_sea[nr][nc];
            if (cell == -1) {
                cell = i; // �� ĭ�̸� ��� ��ġ
            }
            else {
                // �̹� �� �ִ� ĭ������ ū �� �����
                if (sharks[cell].size < sharks[i].size) {
                    sharks[cell].size = 0; // ���� ��� ����
                    cell = i;
                }
                else {
                    sharks[i].size = 0; // ���� ��� ����
                }
            }
        }

        sea = new_sea; // �ٴ� ���� ����
    }

    return size_sum; // ���� ��� ũ�� �� ��ȯ
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, m;
    cin >> r >> c >> m;

    vector<vector<int>> sea(r, vector<int>(c, -1)); // �ٴ� ����
    vector<Shark> sharks(m);
    for (int i = 0; i < m; i++) {
        int rr, cc, s, d, z;
        cin >> rr >> cc >> s >> d >> z;

        sharks[i] = { {rr - 1, cc - 1}, s , d, z }; // ��� ���� ����
        sea[rr - 1][cc - 1] = i;                    // �ٴٿ� ��� ǥ��
    }

    int result = fishing(sea, sharks, r, c, m); // �ùķ��̼� ����

    cout << result; // ��� ���

    return 0;
}