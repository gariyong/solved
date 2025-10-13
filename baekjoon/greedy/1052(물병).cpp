// 문제 : https://www.acmicpc.net/problem/1052
// 제목 : 물병

#include <iostream>

using namespace std;

// 물병을 합칠 수 있는 만큼 합친 뒤, 남는 물병의 개수를 계산하는 함수
int count_bottles(int n) {
	int cnt = 0;

	// n이 0이 될 때까지 반복
	while (n > 0) {
		// n이 홀수면, 병이 하나 남는다는 의미 (2개씩 합치고도 1개 남음)
		if (n % 2 == 1) cnt++;

		// 2개씩 병을 합치기 → n을 2로 나누면 상위 크기의 병 개수가 됨
		n /= 2;
	}

	return cnt; // 남은 병의 개수 반환
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k; // n : 현재 가진 물병의 개수, k : 최대로 남길 수 있는 물병의 개수

	int cnt = 0; // 새로 사야 하는 물병의 수

	while (true) {
		// 현재 병 개수를 모두 합쳤을 때, 남는 병이 k개 이하라면 종료
		if (count_bottles(n) <= k) break;

		// 아니라면 물병을 하나 더 구입
		n++;
		cnt++;
	}

	cout << cnt; // 추가로 사야 하는 최소 물병 개수 출력

	return 0;
}
