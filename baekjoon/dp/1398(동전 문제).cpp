// 문제 : https://www.acmicpc.net/problem/1398
// 제목 : 동전 문제

// [1, 10, 25] -> [100, 1000, 2500] -> .... 이므로
// 100 단위로 나누어서 계산한다는 아이디어를 떠올리는게 중요

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t; // 테스트 케이스 수 입력

	// 1~100원까지의 최소 동전 개수를 저장할 dp 배열
	int dp[101] = { 0 };

	// 1~100원까지의 최소 동전 개수를 미리 계산
	for (int i = 1; i <= 100; i++) {
		dp[i] = dp[i - 1] + 1; // 1원짜리 동전을 하나 더 쓰는 경우
		if (i - 10 >= 0) dp[i] = min(dp[i], dp[i - 10] + 1); // 10원짜리 동전 사용 시 최소값 저장
		if (i - 25 >= 0) dp[i] = min(dp[i], dp[i - 25] + 1); // 25원짜리 동전 사용 시 최소값 저장
	}

	// 각 테스트 케이스 처리
	while (t--) {
		long long cost;
		cin >> cost; // 초콜릿 가격 입력

		int cnt = 0; // 필요한 동전 개수 초기화

		// 금액을 100 단위로 나누어서 계산
		while (cost > 0) {
			// 나머지 0~99원 부분에 대한 최소 동전 수를 더함
			cnt += dp[cost % 100];

			// 100원 단위로 나눠서 다음 반복
			cost /= 100;
		}

		cout << cnt << '\n'; // 최소 동전 개수 출력
	}

	return 0;
}
