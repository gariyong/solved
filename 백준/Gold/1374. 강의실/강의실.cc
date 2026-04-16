#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct lecture {
	int start;
	int end;
} lecture;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<lecture> lectures(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x >> lectures[i].start >> lectures[i].end;
	}

	sort(lectures.begin(), lectures.end(), [](lecture a, lecture b) {
		if (a.start == b.start) return a.end < b.end;
		return a.start < b.start;
		});

	priority_queue<int, vector<int>, greater<int>> q;
	q.push(lectures[0].end);

	for (int i = 1; i < n; i++) {
		if (q.top() <= lectures[i].start) {
			q.pop();
		}
		q.push(lectures[i].end);
	}

	cout << q.size();

	return 0;
}