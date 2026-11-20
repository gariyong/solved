#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	int max_len = 0;
	vector <int> v;
	unordered_map <int, int> fruit;

	cin >> n;
	v.resize(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int left = 0;
	int right = 0;
	
	while (right < n) {
		fruit[v[right]]++;

		while (fruit.size() > 2) {
			fruit[v[left]]--;
			
			if (fruit[v[left]] == 0) {
				fruit.erase(v[left]);
			}

			left++;
		}

		max_len = max(max_len, right - left + 1);
		right++;
	}
	cout << max_len;

	return 0;
}