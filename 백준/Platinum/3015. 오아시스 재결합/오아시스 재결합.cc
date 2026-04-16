#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long result = 0;
	stack<pair<int,int>> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		int duplicate = 1;
		while (!s.empty() && s.top().first < x) {
			result += s.top().second;
			s.pop();
		}

		if (!s.empty()) {
			if (s.top().first == x) {
				result += s.top().second;
				duplicate = s.top().second + 1;
				
				if (s.size() > 1) {
					result++;
				}
				s.pop();
			}
			else {
				result++;
			}
		}

		s.push({ x, duplicate });
	}

	cout << result;

	return 0;
}