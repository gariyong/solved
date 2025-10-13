// 문제 : https://www.acmicpc.net/problem/14601
// 제목 : 샤워실 바닥 깔기 (Large)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 분할정복 타일링 함수
// tile: 타일 배열
// x, y: 현재 보드의 왼쪽 위 좌표
// hole_x, hole_y: 현재 영역 내 구멍 좌표
// n: 현재 영역 크기 (n x n)
// tile_num: 타일 번호 (참조로 넘겨서 재귀 호출 간 공유)
void tiling(vector<vector<int>>& tile, int x, int y, int hole_x, int hole_y, int n, int& tile_num) {
	
	// 영역이 크기 1이면 종료
	if (n == 1) {
		return;
	}

	int t = tile_num++;          // 이번에 놓을 ㄱ자 타일 번호
	int half = n / 2;            // 영역을 4등분할 기준

	int middle_x = x + half;     // 중앙 x 좌표
	int middle_y = y + half;     // 중앙 y 좌표

	// 구멍이 속한 사분면을 찾음
	// 0: 좌상, 1: 우상, 2: 좌하, 3: 우하
	int hole_pos = -1;
	if (hole_x < middle_x && hole_y < middle_y) hole_pos = 0;
	else if (hole_x >= middle_x && hole_y < middle_y) hole_pos = 1;
	else if (hole_x < middle_x && hole_y >= middle_y) hole_pos = 2;
	else hole_pos = 3;

	// 중앙에 ㄱ자 타일을 놓음 (구멍 사분면 제외)
	if (hole_pos != 0) tile[middle_y - 1][middle_x - 1] = t; // 좌상
	if (hole_pos != 1) tile[middle_y - 1][middle_x] = t;     // 우상
	if (hole_pos != 2) tile[middle_y][middle_x - 1] = t;     // 좌하
	if (hole_pos != 3) tile[middle_y][middle_x] = t;         // 우하

	// 각 사분면에 대해 재귀 호출
	// 구멍이 속한 사분면은 원래 구멍 좌표, 나머지 사분면은 중앙에 놓은 ㄱ자 타일 좌표가 구멍
	
	// 좌상
	tiling(tile, x, y, hole_pos == 0 ? hole_x : middle_x - 1, hole_pos == 0 ? hole_y : middle_y - 1, half, tile_num);
	
	// 우상
	tiling(tile, x + half, y, hole_pos == 1 ? hole_x : middle_x, hole_pos == 1 ? hole_y : middle_y - 1, half, tile_num);
	
	// 좌하
	tiling(tile, x, y + half, hole_pos == 2 ? hole_x : middle_x - 1, hole_pos == 2 ? hole_y : middle_y, half, tile_num);
	
	// 우하
	tiling(tile, x + half, y + half, hole_pos == 3 ? hole_x : middle_x, hole_pos == 3 ? hole_y : middle_y, half, tile_num);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k; // 샤워실 바닥 크기 입력(2^k)

	int n = (int)pow(2, k);
	vector<vector<int>> tile(n, vector<int>(n, 0));

	int x, y;
	cin >> x >> y; // 배수구 위치 입력

	// (1,1)이 왼쪽 아래 기준이므로 위로 뒤집기
	int hole_x = x - 1;
	int hole_y = n - y;

	int tile_num = 1;		   // 타일 번호 초기화
	tile[hole_y][hole_x] = -1; // 배수구 표시

	// 타일링 시작
	tiling(tile, 0, 0, hole_x, hole_y, n, tile_num);

	// 결과 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << tile[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
