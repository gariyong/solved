#include <iostream>
#include <string>

using namespace std;

int main() {
	string po1 = "AAAA";
	string po2 = "BB";
	string board;
	string b;
	int len = 0;

	cin >> board;
	
	for (int i = 0; i < board.length(); i++) {
		while (board[i] != '.' && i < board.length()) {
			if (board[i] == 'X') {
				len++;
			}
			i++;
		}
		while (len > 0) {
			if (len >= 4) {
				b += po1;
				len -= 4;
			}
			else if (len >= 2) {
				b += po2;
				len -= 2;
			}
			else {
				len = -1;
				break;
			}
		}
		if (board[i] == '.') {
			b += '.';
		}
		
		if (len == -1) {
			break;
		}
	}

	if (len == -1) {
		cout << -1;
	}
	else {
		cout << b;
	}

	return 0;
}