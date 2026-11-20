#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	int sum = 0;
	stack <int> score;
	vector <int> time;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		
		if (m == 1) {
			int a, t;
			cin >> a >> t;
			score.push(a);
			time.push_back(t);
		}
		if (!time.empty()) {
			time[time.size() - 1]--;
			if (time[time.size() - 1] == 0) {
				time.pop_back();
				sum += score.top();
				score.pop();
			}
		}
	}
	cout << sum;

	return 0;
}