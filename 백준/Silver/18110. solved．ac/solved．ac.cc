#include <iostream>
#include <math.h>

using namespace std;

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main()
{
	int n;
	double p_cut, average = 0;
	int* num;

	cin >> n;
	num = new int[n];
	p_cut = round(double(n) * 0.15);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	qsort(num, n, sizeof(int), compare);

	if (n == 0) {
		cout << 0;
	}
	else {
		for (int i = p_cut; i < (double(n) - p_cut); i++) {
			average += num[i];
		}
		average = round(average / (n - (p_cut * 2)));

		cout << average;
	}
	
	return 0;
}