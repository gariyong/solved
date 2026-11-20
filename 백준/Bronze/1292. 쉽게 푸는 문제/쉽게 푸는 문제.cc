#include <iostream>

using namespace std;

int main() {
	int num[1001];
	int a, b;
	int sum = 0;
	int k = 1;

	for (int i = 1; i < 1001; ) {
		int j = k;
		while (j > 0 && i<1001) {
			num[i] = k;
			j--;
			i++;
		}
		k++;
	}
	cin >> a >> b;

	while (a <= b) {
		sum += num[a];
		a++;
	}
	cout << sum;

	return 0;
}