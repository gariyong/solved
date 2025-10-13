// 문제 : https://www.acmicpc.net/problem/17387
// 제목 : 선분 교차 2
// 알고리즘 : CCW(Counter ClockWise) 알고리즘

#include <iostream>
#include <algorithm>

using namespace std;

// 선분을 표현하기 위한 구조체
// a, b 는 선분의 양 끝점 (pair< x, y >)
struct Line_seg {
	pair<long long, long long> a, b;
};


// CCW 함수
// 세 점 p1, p2, p3 에 대해 아래 식을 계산한다:
// res = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1)
// 이 값은 2차원 벡터의 외적(cross product)에 해당한다.
// 해석:
// res > 0 -> p1 -> p2 -> p3 가 반시계 방향 (CCW)
// res < 0 -> p1 -> p2 -> p3 가 시계 방향 (CW)
// res == 0 -> 세 점이 한 직선(line)에 놓여 있음 (collinear)
// 외적의 부호는 벡터 (p1->p2) 를 기준으로 p3 가 왼쪽(양수)인지 오른쪽(음수)인지를 알려준다.
// 2차원에서의 외적은 방향(부호)과 면적(절댓값)에 대한 정보를 준다.

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
	long long res = (p2.first - p1.first) * (p3.second - p1.second)
		- (p2.second - p1.second) * (p3.first - p1.first);


	if (res > 0) {
		return 1; // 반시계
	}
	else if (res < 0) {
		return -1; // 시계
	}


	return 0; // 일직선
}

// 두 선분 l, r 이 교차하는지 판정하는 함수
// 아이디어 요약:
// 1) 일반적인 경우: 두 선분 AB, CD 가 교차하려면
// ccw(A,B,C) * ccw(A,B,D) <= 0 && ccw(C,D,A) * ccw(C,D,B) <= 0
// 가 성립해야 한다.
// (각각 C와 D가 AB의 양쪽에 있고, A와 B가 CD의 양쪽에 있는지 검사)
// 2) 특수한 경우: 네 점 모두 한 직선 위에 있는 경우(모두 ccw == 0)
// 이때는 두 선분의 투영(좌표 정렬)을 비교해서 실제로 겹치는지 확인해야 한다.
// (예: [----A----B----] 와 [----C----D----] 가 겹치는지 확인)
// 구현 세부사항:
// - pair 의 비교 연산자(>, <)는 먼저 first(x)를 비교하고 같으면 second(y)를 비교한다.
// - 일직선일 때는 각 선분의 끝점을 오름차순으로 정렬한 뒤 범위가 겹치는지 검사한다.
// - 정렬은 (x, y) 순서로 정렬되므로 수직/기울기 등 모든 경우에 동작하도록 보장된다.

bool is_cross(Line_seg l, Line_seg r) {
	int ccw1 = ccw(l.a, l.b, r.a);
	int ccw2 = ccw(l.a, l.b, r.b);
	int ccw3 = ccw(r.a, r.b, l.a);
	int ccw4 = ccw(r.a, r.b, l.b);


	// 두 선분이 교차할 수 있는 기본 조건
	if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {
		// 네 점이 모두 일직선상에 있는 특수 케이스
		if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0) {
			// 각 선분의 끝점을 작은 순서로 정렬한다.
			// pair 에 대해서는 기본 비교연산자가 정의되어 있어서 (x, y) 기준으로 정렬된다.
			if (l.a > l.b) swap(l.a, l.b);
			if (r.a > r.b) swap(r.a, r.b);


			// 두 구간이 겹치는지 확인
			// 겹치지 않는 조건은 (l.b < r.a) 또는 (r.b < l.a)
			// 따라서 겹치면 !(l.b < r.a || r.b < l.a)
			return !(l.b < r.a || r.b < l.a);
		}
		// 일직선이 아닌 경우라면 앞의 조건만으로도 교차가 성립
		return true;
	}


	// 기본 조건 불만족 -> 교차하지 않음
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	Line_seg l, r;
	// 입력: 첫 줄 AB (x1 y1 x2 y2), 둘째 줄 CD (x3 y3 x4 y4)
	cin >> l.a.first >> l.a.second >> l.b.first >> l.b.second;
	cin >> r.a.first >> r.a.second >> r.b.first >> r.b.second;


	cout << is_cross(l, r);


	return 0;
}
