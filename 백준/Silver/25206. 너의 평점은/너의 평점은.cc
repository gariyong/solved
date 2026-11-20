#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double grade_to_score(const string& grade) {
	if (grade == "A+") return 4.5;
	if (grade == "A0") return 4.0;
	if (grade == "B+") return 3.5;
	if (grade == "B0") return 3.0;
	if (grade == "C+") return 2.5;
	if (grade == "C0") return 2.0;
	if (grade == "D+") return 1.5;
	if (grade == "D0") return 1.0;
	if (grade == "F")  return 0.0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double score_sum = 0;
	double credit_sum = 0;

	for (int i = 0; i < 20; i++) {
		string subject, grade;
		double credit;
		cin >> subject >> credit >> grade;

		if (grade == "P") continue;

		score_sum += credit * grade_to_score(grade);
		credit_sum += credit;
	}

	cout << fixed << setprecision(6) << (score_sum / credit_sum);

	return 0;
}