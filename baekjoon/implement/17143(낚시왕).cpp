// 문제 : https://www.acmicpc.net/problem/17143
// 제목 : 낚시왕
// 구현, 시뮬레이션 문제
// 상어를 이동시키고, 낚시꾼이 한 열씩 이동하며 가장 가까운 상어를 잡는 과정을 시뮬레이션함

#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

// 상, 하, 우, 좌 이동을 위한 방향 벡터 (0번 인덱스는 사용 안함)
const int dr[] = { 0, -1, 1, 0, 0 }; // 1: 위, 2: 아래, 3: 오른쪽, 4: 왼쪽
const int dc[] = { 0, 0, 0, 1, -1 };

// 상어 구조체 정의
struct Shark {
    pair<int, int> pos; // 현재 위치 (행, 열)
    int speed;          // 이동 속력
    int head;           // 이동 방향 (1~4)
    int size;           // 상어 크기
};

// 상어를 이동시키는 함수
tuple<int, int, int> move_shark(Shark shark, int r, int c) {
    int p_r = shark.pos.first;
    int p_c = shark.pos.second;
    int s = shark.speed;
    int d = shark.head;

    int period; // 상어 이동의 주기 (반복되는 패턴)
    if (d == 1 || d == 2) { // 위/아래 이동
        period = 2 * (r - 1);
        if (period == 0) return { p_r, p_c, d }; // 행이 1이면 이동 불필요
    }
    else { // 오른쪽/왼쪽 이동
        period = 2 * (c - 1);
        if (period == 0) return { p_r, p_c, d }; // 열이 1이면 이동 불필요
    }

    s %= period; // 주기 단축: 반복되는 패턴을 고려

    int nr = p_r;
    int nc = p_c;
    int nd = d;

    // 상어 이동 시뮬레이션
    while (s > 0) {
        nr += dr[nd];
        nc += dc[nd];
        s--;

        // 경계에 도달하면 방향 반전
        if (nd == 1 && nr < 0) { // 위로 이동 중 경계 도달
            nr = 1;
            nd = 2; // 아래로 방향 전환
        }
        else if (nd == 2 && nr >= r) { // 아래로 이동 중 경계 도달
            nr = r - 2;
            nd = 1; // 위로 방향 전환
        }
        else if (nd == 4 && nc < 0) { // 왼쪽 이동 중 경계 도달
            nc = 1;
            nd = 3; // 오른쪽으로 방향 전환
        }
        else if (nd == 3 && nc >= c) { // 오른쪽 이동 중 경계 도달
            nc = c - 2;
            nd = 4; // 왼쪽으로 방향 전환
        }
    }

    return { nr, nc, nd }; // 이동 후 위치와 방향 반환
}

// 낚시 시뮬레이션 함수
int fishing(vector<vector<int>>& sea, vector<Shark>& sharks, int r, int c, int m) {
    int size_sum = 0; // 잡힌 상어 크기 합

    // 낚시꾼이 0열부터 c-1열까지 이동
    for (int fisher = 0; fisher < c; fisher++) {
        int target = -1; // 현재 열에서 잡을 상어 인덱스

        // 현재 열에서 가장 가까운 상어 찾기
        for (int i = 0; i < m; i++) {
            if (sharks[i].size == 0) continue; // 이미 잡힌 상어는 무시

            if (sharks[i].pos.second == fisher) { // 같은 열에 있는 경우
                if (target == -1) {
                    target = i; // 첫 번째 발견 상어
                }
                else {
                    // 더 위에 있는 상어를 선택
                    if (sharks[target].pos.first > sharks[i].pos.first) {
                        target = i;
                    }
                }
            }
        }

        // 상어 잡기
        if (target != -1) {
            size_sum += sharks[target].size; // 크기 합산
            sharks[target].size = 0;         // 잡힌 상어 표시
        }

        // 상어 이동 후 새로운 바다 상태 갱신
        vector<vector<int>> new_sea(r, vector<int>(c, -1));
        for (int i = 0; i < m; i++) {
            if (sharks[i].size == 0) continue; // 잡힌 상어 무시

            auto [nr, nc, nd] = move_shark(sharks[i], r, c);

            sharks[i].pos = { nr, nc };
            sharks[i].head = nd;

            int& cell = new_sea[nr][nc];
            if (cell == -1) {
                cell = i; // 빈 칸이면 상어 배치
            }
            else {
                // 이미 상어가 있는 칸에서는 큰 상어만 남기기
                if (sharks[cell].size < sharks[i].size) {
                    sharks[cell].size = 0; // 작은 상어 제거
                    cell = i;
                }
                else {
                    sharks[i].size = 0; // 현재 상어 제거
                }
            }
        }

        sea = new_sea; // 바다 상태 갱신
    }

    return size_sum; // 잡힌 상어 크기 합 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, m;
    cin >> r >> c >> m;

    vector<vector<int>> sea(r, vector<int>(c, -1)); // 바다 상태
    vector<Shark> sharks(m);
    for (int i = 0; i < m; i++) {
        int rr, cc, s, d, z;
        cin >> rr >> cc >> s >> d >> z;

        sharks[i] = { {rr - 1, cc - 1}, s , d, z }; // 상어 정보 저장
        sea[rr - 1][cc - 1] = i;                    // 바다에 상어 표시
    }

    int result = fishing(sea, sharks, r, c, m); // 시뮬레이션 수행

    cout << result; // 결과 출력

    return 0;
}
