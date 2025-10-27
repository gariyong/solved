// ���� : https://www.acmicpc.net/problem/9328
// ���� : ����
// �˰��� : BFS

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

// 4���� �̵� �迭
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

// �ܰ����� �����Ͽ� �湮 ������ ��� ĭ Ž��
int bfs(vector<vector<char>>& map, vector<bool>& keys, int h, int w) {
    int cnt = 0; // ������ ����('$') ����
    vector<vector<bool>> visit(h, vector<bool>(w, false)); // �湮 üũ �迭
    queue<pair<int, int>> q; // BFS ť
    vector<queue<pair<int, int>>> door(26); // ���谡 ��� ��� �� ��ġ ����(A~Z)

    // �ܰ� ��ǥ�� ť�� ����
    for (int i = 0; i < h; i++) { // �¿� ��
        for (int j : {0, w - 1}) {
            if (map[i][j] != '*' && !visit[i][j]) { // ���� �ƴϸ�
                q.push({ i,j });
                visit[i][j] = true;
            }
        }
    }
    for (int j = 0; j < w; j++) { // ���� ��
        for (int i : {0, h - 1}) {
            if (map[i][j] != '*' && !visit[i][j]) { // ���� �ƴϸ�
                q.push({ i,j });
                visit[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [y, x] = q.front(); // ���� ��ġ
        q.pop();
        char cur = map[y][x]; // ���� ĭ ����

        // ���� ĭ�� ��(A~Z)�� ���
        if ('A' <= cur && cur <= 'Z') {
            int idx = cur - 'A';

            if (!keys[idx]) { // ���谡 ������
                door[idx].push({ y,x }); // ���߿� ���� ������ �湮�� �� �ֵ��� ����
                continue;
            }
        }

        // ���� ĭ�� ����(a~z)�� ���
        if ('a' <= cur && cur <= 'z') {
            int idx = cur - 'a';
            if (!keys[idx]) { // ���� ȹ������ ���� ������ ���
                keys[idx] = true; // ���� ȹ��

                while (!door[idx].empty()) { // ���谡 ���� �� �湮�ߴ� ���� ť�� �߰�
                    auto [dy_, dx_] = door[idx].front();
                    door[idx].pop();
                    q.push({ dy_, dx_ });
                }
            }
        }

        // ���� ĭ�� ����('$')�� ���
        if (cur == '$') cnt++;

        // 4���� Ž��
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            // ���� üũ,
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            // ���� �ƴϰ� ���� �湮���� ���� ĭ�̸�
            if (map[ny][nx] != '*' && !visit[ny][nx]) {
                visit[ny][nx] = true; // �湮 üũ
                q.push({ ny,nx }); // ť�� �߰�
            }
        }
    }

    return cnt; // ���� ������ ���� ���� ��ȯ
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // �׽�Ʈ ���̽� ��
    cin >> t;

    while (t--) {
        int h, w;
        cin >> h >> w;

        vector<vector<char>> map(h, vector<char>(w)); // ���� �Է�
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> map[i][j];

        string str; // �ʱ� ���� �Է�
        cin >> str;

        vector<bool> keys(26, false); // ���� ���� ����
        if (str[0] != '0') { // 0�� �ƴϸ� ���谡 ����
            for (char c : str) keys[c - 'a'] = true;
        }

        // ������ ���� ���� ���
        cout << bfs(map, keys, h, w) << '\n';
    }

    return 0;
}