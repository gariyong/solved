// 문제 : https://www.acmicpc.net/problem/15824
// 제목 : 너 봄에는 캡사이신이 맛있단다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007; // 모듈러 연산 값

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n; // 메뉴 개수 입력

	vector<long long>menu(n);
	for (int i = 0; i < n; i++) {
		cin >> menu[i];
	}
	// 오름차순 정렬
	// menu[i]가 최대/최소 등장 횟수를 카운트하기 위해서
	sort(menu.begin(), menu.end());


	// 2의 거듭제곱 미리 계산
	vector<long long> pow2(n);
	pow2[0] = 1;
	for (int i = 1; i < n; i++) {
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}

	long long result = 0;
	for (int i = 0; i < n; i++) {
		// menu[i]가 최대값으로 등장하는 부분집합 수 : 2^i
		long long max_contrib = (menu[i] * pow2[i]) % MOD;

		// menu[i]가 최솟값으로 등장하는 부분집합 수 : 2^(n - i - 1)
		long long min_contrib = (menu[i] * pow2[n - i - 1]) % MOD;

		// 각 메뉴의 기여도 = max 기여도 - min 기여도
		// 음수가 나올 수 있으므로 MOD를 더해줘서 보정(중요)
		result += (max_contrib - min_contrib + MOD) % MOD;
		result %= MOD;
	}

	// 결과 출력
	cout << result;

	return 0;
}