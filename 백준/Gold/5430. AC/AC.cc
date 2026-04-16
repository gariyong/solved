#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while (t > 0) {
		string function, arr;
		int n;
		int D_cnt = 0;
		int n_len = 0;
		int arr_len;
		int ftn_len;
		deque <int> q;

		cin >> function >> n >> arr;
		arr_len = (int)arr.length();
		ftn_len = (int)function.length();

		for (int i = 0; i < arr_len; i++) {
			if (arr[i] != '[' && arr[i] != ']' && arr[i] != ',') {
				n_len++;
			}
			else {
				if (n_len != 0) {
					string num;
					for (int j = n_len; j >= 1; j--) {
						num += arr[i - j];
					}
					q.push_back(stoi(num));
					n_len = 0;
				}
			}
		}

		bool flip = false;

		for (int i = 0; i < ftn_len; i++) {
			if (function[i] == 'R') {
				flip = !flip;
			}
			else if (function[i] == 'D') {
				D_cnt++;
				if (q.empty()) {
					break;
				}
				else {
					if (flip == true) {
						q.pop_back();
					}
					else if (flip == false) {
						q.pop_front();
					}
				}
			}
		}

		if (D_cnt > n) {
			cout << "error\n";
		}
		else {
			int size = (int)q.size();
			if (size == 0) {
				cout << "[]\n";
			}
			else {
				cout << "[";
				if (flip == true) {
					for (int i = 0; i < size - 1; i++) {
						cout << q.back() << ',';
						q.pop_back();
					}
					cout << q.back() << ']' << '\n';
				}
				else if (flip == false) {
					for (int i = 0; i < size - 1; i++) {
						cout << q.front() << ',';
						q.pop_front();
					}
					cout << q.front() << ']' << '\n';
				}
			}
		}

		t--;
	}

	return 0;
}