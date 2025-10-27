// 문제 : https://www.acmicpc.net/problem/9328
// 제목 : 열쇠
// 알고리즘 : BFS

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

// 4방향 이동 배열
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

// 외곽에서 시작하여 방문 가능한 모든 칸 탐색
int bfs(vector<vector<char>>& map, vector<bool>& keys, int h, int w) {
    int cnt = 0; // 수집한 문서('$') 개수
    vector<vector<bool>> visit(h, vector<bool>(w, false)); // 방문 체크 배열
    queue<pair<int, int>> q; // BFS 큐
    vector<queue<pair<int, int>>> door(26); // 열쇠가 없어서 잠긴 문 위치 저장(A~Z)

    // 외곽 좌표를 큐에 넣음
    for (int i = 0; i < h; i++) { // 좌우 열
        for (int j : {0, w - 1}) {
            if (map[i][j] != '*' && !visit[i][j]) { // 벽이 아니면
                q.push({ i,j });
                visit[i][j] = true;
            }
        }
    }
    for (int j = 0; j < w; j++) { // 상하 행
        for (int i : {0, h - 1}) {
            if (map[i][j] != '*' && !visit[i][j]) { // 벽이 아니면
                q.push({ i,j });
                visit[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [y, x] = q.front(); // 현재 위치
        q.pop();
        char cur = map[y][x]; // 현재 칸 문자

        // 현재 칸이 문(A~Z)인 경우
        if ('A' <= cur && cur <= 'Z') {
            int idx = cur - 'A';

            if (!keys[idx]) { // 열쇠가 없으면
                door[idx].push({ y,x }); // 나중에 열쇠 얻으면 방문할 수 있도록 저장
                continue;
            }
        }

        // 현재 칸이 열쇠(a~z)인 경우
        if ('a' <= cur && cur <= 'z') {
            int idx = cur - 'a';
            if (!keys[idx]) { // 아직 획득하지 않은 열쇠인 경우
                keys[idx] = true; // 열쇠 획득

                while (!door[idx].empty()) { // 열쇠가 없을 때 방문했던 문을 큐에 추가
                    auto [dy_, dx_] = door[idx].front();
                    door[idx].pop();
                    q.push({ dy_, dx_ });
                }
            }
        }

        // 현재 칸이 문서('$')인 경우
        if (cur == '$') cnt++;

        // 4방향 탐색
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            // 범위 체크,
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            // 벽이 아니고 아직 방문하지 않은 칸이면
            if (map[ny][nx] != '*' && !visit[ny][nx]) {
                visit[ny][nx] = true; // 방문 체크
                q.push({ ny,nx }); // 큐에 추가
            }
        }
    }

    return cnt; // 최종 수집한 문서 개수 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // 테스트 케이스 수
    cin >> t;

    while (t--) {
        int h, w;
        cin >> h >> w;

        vector<vector<char>> map(h, vector<char>(w)); // 지도 입력
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> map[i][j];

        string str; // 초기 열쇠 입력
        cin >> str;

        vector<bool> keys(26, false); // 열쇠 보유 여부
        if (str[0] != '0') { // 0이 아니면 열쇠가 존재
            for (char c : str) keys[c - 'a'] = true;
        }

        // 수집한 문서 개수 출력
        cout << bfs(map, keys, h, w) << '\n';
    }

    return 0;
}