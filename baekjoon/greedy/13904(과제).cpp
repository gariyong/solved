// 문제 : https://www.acmicpc.net/problem/13904
// 제목 : 과제

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

// 과제 구조체 : 마감일(d)과 점수(w) 저장
struct Assignment {
	int d;
	int w;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; // 과제의 수
	cin >> n;

	vector<Assignment> assignments(n);
	for (int i = 0; i < n; i++) {
		cin >> assignments[i].d >> assignments[i].w; // 각 과제의 마감일과 점수를 입력
	}

	// 마감일 기준 오름차순 정렬, 점수 기준 내림차순 정렬
	sort(assignments.begin(), assignments.end(), [](const Assignment& a, const Assignment& b) {
		if (a.d != b.d) {
			return a.d < b.d; // 마감일이 빠른 순서
		}

		return a.w > b.w; // 점수가 높은 순서
		});

	// 우선순위 큐: 최소 힙, 현재 선택한 과제들 중 점수가 가장 작은 값을 top에다 올려놓음
	priority_queue<int, vector<int>, greater<int>> q;

	for (auto& hw : assignments) {
		int d = hw.d; // 과제 마감일
		int w = hw.w; // 과제 점수

		int cnt = (int)q.size(); // 현재 선택된 과제 수 == 날짜

		// 현재 선택된 과제 수가 마감일 보다 낮으면 선택
		if (cnt < d) {
			q.push(w);
		}

		// 선택된 과제 수가 마감일과 같으면 더 높은 점수의 과제와 교체 가능
		else if (cnt == d) {
			if (!q.empty() && w > q.top()) {
				q.pop();
				q.push(w);
			}
		}
	}

	// 선택된 과제들의 점수의 합 계산
	int score = 0;
	while (!q.empty()) {
		int x = q.top();
		q.pop();

		score += x;
	}

	// 최대 점수 출력
	cout << score;

	return 0;
}
