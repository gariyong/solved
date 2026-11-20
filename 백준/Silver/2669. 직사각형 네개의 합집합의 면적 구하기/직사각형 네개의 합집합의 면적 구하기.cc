#include <iostream>

using namespace std;

int main() {
	int square[101][101] = { 0 };
	int left_x, left_y, right_x, right_y;
	int num = 0;

	for (int i = 0; i < 4; i++) {
		cin >> left_x >> left_y >> right_x >> right_y;
		for (int j = left_y; j < right_y; j++) {
			for (int k = left_x; k < right_x; k++) {
				if (square[j][k] == 0) {
					square[j][k] = 1;
					num++;
				}
			}
		}
	}
	cout << num;

	return 0;
}