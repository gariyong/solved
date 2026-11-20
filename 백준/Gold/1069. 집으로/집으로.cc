#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int x, y, d, t;
	cin >> x >> y >> d >> t;
	
	double dist = sqrt(x * x + y * y);
	double time = dist;
	int n = (int)(dist / d);

	time = min(time, n * t + (dist - n * d));
	if (n == 0) {
		time = min(time, t + (d - dist));
		time = min(time, (double) (2 * t));
	}
	else {
		time = min(time, (double)(n + 1) * t);
	}

	cout << fixed << setprecision(10) << time;

	return 0;
}