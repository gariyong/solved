#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct study {
	int s;
	int t;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<study>studies(n);
	for (int i = 0; i < n; i++) {
		cin >> studies[i].s >> studies[i].t;
	}
	sort(studies.begin(), studies.end(), [](const study& a, const study& b) {
		return a.s < b.s;
		});
	
	priority_queue<int, vector<int>, greater<>> q;
	q.push(studies[0].t);

	for (int i = 1; i < n; i++) {
		if (q.top() <= studies[i].s) {
			q.pop();
		}
		q.push(studies[i].t);
	}

	cout << q.size();

	return 0;
}