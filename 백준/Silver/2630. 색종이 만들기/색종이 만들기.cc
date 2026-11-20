#include <iostream>

using namespace std;

void divid_paper(int n, int**& paper, int i, int j, int& w_p, int& b_p) {
	int color = paper[i][j];
	int flag = 0;

		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				if (paper[i + k][l + j] != color && flag == 0) {
					divid_paper(n / 2, paper, i + 0, j + 0, w_p, b_p);
					divid_paper(n / 2, paper, i + n / 2, j + 0, w_p, b_p);
					divid_paper(n / 2, paper, i + 0, j + n / 2, w_p, b_p);
					divid_paper(n / 2, paper, i + n / 2, j + n / 2, w_p, b_p);
					flag = 1;
				}
			}
		}

		if (flag == 0) {
			if (color == 0) {
				w_p++;
			}
			else {
				b_p++;
			}
		}
}

int main() {
	int n;
	int w_p = 0, b_p = 0;
	int** paper;

	cin >> n;
	paper = new int* [n];
	for (int i = 0; i < n; i++) {
		paper[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	divid_paper(n, paper, 0, 0, w_p, b_p);

	cout << w_p << '\n' << b_p;

	return 0;
}