// 문제 : https://www.acmicpc.net/problem/2162
// 제목 : 선분 그룹
// 알고리즘 : CCW(Count ClockWise)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 선분 구조체 : 두 점 (a, b)로 구성됨
struct Line_seg {
	pair<int, int> a, b;
};

// 부모 노드를 찾는 함수
int find(vector<int>& parent, int x) {
	if (parent[x] == x) {
		return parent[x];
	}

	return parent[x] = find(parent, parent[x]);
}

// 두 집합을 합치는 함수
// cnt[x] : 해당 그룹의 선분 개수
void unite(vector<int>& parent, vector<int>& cnt, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);

	if (a != b) {
		// b 그룹에 a 그룹을 합침
		parent[a] = b;
		cnt[b] += cnt[a]; // 그룹 크기 합치기
		cnt[a] = 0;		  // 흡수된 그룹의 크기는 0
	}
}

// CCW (Counter ClockWise) 알고리즘
// res > 0 : 반시계 방향
// res < 0 : 시계 방향
// res = 0 : 일직선
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	int res = (p2.first - p1.first) * (p3.second - p1.second)
		- (p2.second - p1.second) * (p3.first - p1.first);

	if (res > 0) {
		return 1;
	}
	else if (res < 0) {
		return -1;
	}

	return 0;
}

// CCW 값을 이용하여 교차 조건을 판정하는 함수
// 1. 일반 교차 : ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0
// 2. 일직선 상의 경우엔 좌표 비교로 겹침 판정
bool is_cross(Line_seg l, Line_seg r) {
	int ccw1 = ccw(l.a, l.b, r.a);
	int ccw2 = ccw(l.a, l.b, r.b);
	int ccw3 = ccw(r.a, r.b, l.a);
	int ccw4 = ccw(r.a, r.b, l.b);

	// 두 선분이 교차하거나 닿는 경우
	if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {
		// 네 점 모두 일직선 상에 있는 경우
		if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0) {
			// 두 선분의 점 순서 정렬
			if (l.a > l.b) swap(l.a, l.b);
			if (r.a > r.b) swap(r.a, r.b);

			// 겹치지 않는 경우 제외
			return !(l.b < r.a || r.b < l.a);
		}

		// 교차
		return true;
	}

	// 교차하지 않음
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Line_seg>lines(n);
	for (int i = 0; i < n; i++) {
		cin >> lines[i].a.first >> lines[i].a.second >> lines[i].b.first >> lines[i].b.second;
	}

	// 각 선분을 독립된 집합으로 초기화
	vector<int>parent(n);
	vector<int>cnt(n, 1); // 초기 그룹 크기 = 1
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	// 모든 선분 쌍을 비교하여 교차하면 같은 그룹으로 합침
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (is_cross(lines[i], lines[j])) {
				unite(parent, cnt, i, j);
			}
		}
	}


	int groups = 0;
	int max_size = 0;
	for (int i = 0; i < n; i++) {
		int cur = find(parent, i); // 대표 노드 찾기

		if (cur == i) { // 루트 노드면 새로운 그룹
			groups++;
		}

		max_size = max(max_size, cnt[cur]); // 최대 그룹 크기 갱신
	}

	cout << groups << '\n' << max_size; // 결과 출력

	return 0;
}