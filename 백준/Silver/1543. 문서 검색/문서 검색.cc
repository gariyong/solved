#include <iostream>
#include <string>

using namespace std;

int main() {
	string txt, word;
	int count = 0;

	getline(cin, txt);
	getline(cin, word);
	
	for (int i = 0; i < txt.length(); ) {
		int check = 0;
		for (int j = 0; j < word.length(); j++) {
			if (txt[i + j] == word[j]) {
				check++;
			}
			else {
				i++;
				break;
			}
		}
		if (check == word.length()) {
			count++;
			i += check;
		}
	}
	cout << count;

	return 0;
}