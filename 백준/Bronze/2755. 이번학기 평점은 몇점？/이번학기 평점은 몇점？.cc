#include <iostream>
#include <cmath>
#include <string>

using namespace std;

typedef struct Student {
	string subject;
	double credit;
	string grade;
}Student;

int main() {
	int n;
	double avg = 0, sum_credit = 0;
	Student* student;

	cin >> n;
	student = new Student[n];
	for (int i = 0; i < n; i++) {
		cin >> student[i].subject >> student[i].credit >> student[i].grade;
		sum_credit += student[i].credit;
        
        if (student[i].grade == "A+") {
            avg += 4.3 * student[i].credit;
        }
        else if (student[i].grade == "A0") {
            avg += 4.0 * student[i].credit;
        }
        else if (student[i].grade == "A-") {
            avg += 3.7 * student[i].credit;
        }
        else if (student[i].grade == "B+") {
            avg += 3.3 * student[i].credit;
        }
        else if (student[i].grade == "B0") {
            avg += 3.0 * student[i].credit;
        }
        else if (student[i].grade == "B-") {
            avg += 2.7 * student[i].credit;
        }
        else if (student[i].grade == "C+") {
            avg += 2.3 * student[i].credit;
        }
        else if (student[i].grade == "C0") {
            avg += 2.0 * student[i].credit;
        }
        else if (student[i].grade == "C-") {
            avg += 1.7 * student[i].credit;
        }
        else if (student[i].grade == "D+") {
            avg += 1.3 * student[i].credit;
        }
        else if (student[i].grade == "D0") {
            avg += 1.0 * student[i].credit;
        }
        else if (student[i].grade == "D-") {
            avg += 0.7 * student[i].credit;
        }
	}
    avg /= sum_credit;
    avg = round(avg * 100) / 100;

    cout << fixed;
    cout.precision(2);
    cout << avg;
	delete[] student;

	return 0;
}