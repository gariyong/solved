#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Alphabet {
	char alpha;
	long long w;
	bool is_zero;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}

	vector<Alphabet> alphabets(10);
	for (int i = 0; i < 10; i++) {
		alphabets[i].alpha = 'A' + i;
		alphabets[i].w = 0;
		alphabets[i].is_zero = false;
	}

	for (string word : words) {
		long long p = 1;

		for (int i = word.length() - 1; i >= 0; i--) {
			int idx = word[i] - 'A';
			alphabets[idx].w += p;

			if (i == 0) {
				alphabets[idx].is_zero = true;
			}
			p *= 10;
		}
	}

	vector<Alphabet> used_alphabets;
	for (Alphabet alpha : alphabets) {
		if (alpha.w > 0) {
			used_alphabets.push_back(alpha);
		}
	}

	sort(used_alphabets.begin(), used_alphabets.end(), [](Alphabet& a, Alphabet& b) {
		return a.w > b.w;
		});

	if (used_alphabets.size() == 10) {
		int zero_idx = -1;

		for (int i = used_alphabets.size() - 1; i >= 0; i--) {
			if (!used_alphabets[i].is_zero) {
				zero_idx = i;
				
				break;
			}
		}

		if (zero_idx != -1) {
			Alphabet temp = used_alphabets[zero_idx];
			used_alphabets.erase(used_alphabets.begin() + zero_idx);
			used_alphabets.push_back(temp);
		}
	}

	long long result = 0;
	int digit = 9;
	for (Alphabet alpha : used_alphabets) {
		result += alpha.w * digit;
		digit--;
	}

	cout << result;

	return 0;
}