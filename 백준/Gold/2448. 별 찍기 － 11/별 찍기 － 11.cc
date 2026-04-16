#include <iostream>

using namespace std;

const int MAX = 3072;
char star[MAX][MAX * 2];

void draw(int y, int x, int height) {
	if (height == 3) {
		star[y][x] = '*';
		star[y + 1][x - 1] = '*';
		star[y + 1][x + 1] = '*';

		for (int i = -2; i <= 2; i++) {
			star[y + 2][x + i] = '*';
		}
		return;
	}

	int half = height / 2;

	draw(y, x, half);
	draw(y + half, x - half, half);
	draw(y + half, x + half, half);
}

int main() {
	int n; 

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			star[i][j] = ' ';
		}
	}

	draw(0, n - 1, n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n * 2; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}

	return 0;
}