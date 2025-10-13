// 문제 : https://www.acmicpc.net/problem/1041
// 제목 : 주사위

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n; // 주사위의 한 변에 놓인 주사위 개수

    vector<long long> dice(6);
    for (int i = 0; i < 6; i++) {
        cin >> dice[i]; // 주사위 각 면의 눈금 값 입력
    }

    // 주사위가 하나뿐일 때
    // 한 면만 바닥에 닿고, 나머지 5면이 보임
    if (n == 1) {
        long long sum = 0, max_val = 0;
        for (long long x : dice) {
            sum += x;
            max_val = max(max_val, x); // 가장 큰 면은 바닥으로 숨김
        }
        cout << sum - max_val; // 보이는 5면의 합 = 전체 합 - 최대 면값

        return 0;
    }

    // 한 면에서 가장 작은 값 찾기
    long long one_face_min = dice[0];
    for (int i = 1; i < 6; i++) {
        one_face_min = min(one_face_min, dice[i]);
    }

    // 마주보는 면 : (0,5), (1,4), (2,3)
    // 따라서, 동시에 나올 수 있는 두 면의 조합을 미리 정의
    vector<pair<int, int>> two_face = {
        {0,1},{0,2},{0,3},{0,4},
        {1,2},{1,3},{1,5},
        {2,4},{2,5},
        {3,4},{3,5},
        {4,5}
    };

    // 두 면이 동시에 보이는 경우의 최소 합 찾기
    long long two_face_min = 1e9;
    for (auto& tf : two_face) {
        two_face_min = min(two_face_min, dice[tf.first] + dice[tf.second]);
    }

    // 세 면이 동시에 보이는 경우(모서리 꼭짓점에 위치한 주사위)
    // 가능한 조합을 직접 정의
    vector<vector<int>> three_face = {
        {0,1,2},{0,1,3},{0,2,4},{0,3,4},
        {5,1,2},{5,1,3},{5,2,4},{5,3,4}
    };

    // 세 면이 동시에 보이는 경우의 최소 합 찾기
    long long three_face_min = 1e9;
    for (auto& tf : three_face) {
        three_face_min = min(three_face_min, dice[tf[0]] + dice[tf[1]] + dice[tf[2]]);
    }

    // 한 면만 보이는 주사위 = 윗면 가운데 부분 + 옆면 테두리 부분
    // 윗면 가운데 부분 : (n - 2)^2
    // 아랫면 모서리 부분 : (n - 2) * (n - 1) * 4
    long long one_face_cnt = (n - 2) * (n - 2) + (n - 2) * (n - 1) * 4;
    
    // 두 면이 보이는 주사위 : 윗면 모서리 부분 + 아랫면 모서리 부분
    // 윗면 모서리 부분 : (n - 2) * 4
    // 아랫면 모서리 부분 : (n - 1) * 4
    long long two_face_cnt = (n - 2) * 4 + (n - 1) * 4;

    // 세 면이 보이는 주사위 = 꼭짓점에 위치한 4개
    long long three_face_cnt = 4;

    // 총합 계산 = 각 경우의 수에 해당하는 최소값 * 개수의 합
    long long result = one_face_min * one_face_cnt
        + two_face_min * two_face_cnt
        + three_face_min * three_face_cnt;

    cout << result; // 결과 출력

    return 0;
}
