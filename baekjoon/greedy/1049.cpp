// 문제 : https://www.acmicpc.net/problem/1049
// 제목 : 기타줄

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 브랜드별 기타줄 가격 정보 구조체
struct Guitar_str {
	int individual; // 낱개 가격
	int package; // 6개 묶음(패키지) 가격
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m; // n : 필요한 기타줄 수, m : 브랜드 수

	vector<Guitar_str>strings(m);
	for (int i = 0; i < m; i++) {
		// 각 브랜드의 패키지 가격과 낱개 가격 입력
		cin >> strings[i].package >> strings[i].individual;
	}

	int min_6str = 1e9; // 6개 기준 최소 구매 비용
	int min_1str = 1e9; // 1개 기준 최소 구매 비용

	// 모든 브랜드를 순회하며 최소 가격 계산
	for (auto& cur : strings) {
		// 6개를 낱개로 사는게 패키지보다 저렴할수도 있으므로 비교 후 브랜드 찾기
		min_6str = min(min_6str, min(cur.individual * 6, cur.package));

		// 낱개 중에서 가장 저렴한 브랜드 찾기
		min_1str = min(min_1str, cur.individual);
	}

	int result;
	
	// 필요한 기타줄 개수 n이 6으로 나누어 떨어지지 않는 경우
	if (n % 6 != 0) {
		// 두 가지 경우 중 가장 저렴한 것을 선택
		// 패키지로만 사기(남는 줄 포함) | 패키지 + 낱개 혼합 구매
		result = min(min_6str * (n / 6 + 1), min_6str * (n / 6) + min_1str * (n % 6));
	}
	// 6으로 정확히 나누어 떨어지는 경우
	else {
		// 두가지 경우 중 가장 저렴한 것을 선택
		// 전부 패키지로만 구매 | 전부 낱개로만 구매
		result = min(min_6str * (n / 6), min_1str * n);
	}

	cout << result; // 최소 비용 출력

	return 0;
}