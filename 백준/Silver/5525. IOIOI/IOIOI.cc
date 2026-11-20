#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	int len;
	int cnt = 0;
	int pattern = 0;
	string s;

	cin >> n >> len >> s;
	
	for (int i = 1; i <= len - 1; i++) {
		if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
			pattern++;
			i++;

			if (pattern == n) {
				cnt++;
				pattern--;
			}
		}
		else {
			pattern = 0;
		}
	}

	cout << cnt;

	return 0;
}