#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n && n != 0) {
		vector<ll> h(n);
		for (int i = 0; i < n; i++) cin >> h[i];

		ll result = 0;
		stack<int> s;
		for (int i = 0; i <= n; i++) {
			ll cur_h = (i == n) ? 0 : h[i];

			while (!s.empty() && h[s.top()] > cur_h) {
				int high = h[s.top()];
				s.pop();

				ll width = s.empty() ? i : i - s.top() - 1;
				result = max(result, high * width);
			}

			s.push(i);
		}

		cout << result << '\n';
	}

	return 0;
}