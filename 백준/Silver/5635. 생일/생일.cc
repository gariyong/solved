#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Student {
	string name;
	int day;
	int month;
	int year;
}Student;

bool compare(const Student& a, const Student& b) {
	if (a.year == b.year) {
		if (a.month == b.month) {
			return a.day > b.day;
		}
		else {
			return a.month > b.month;
		}
	}
	else {
		return a.year > b.year;
	}
}

int main() {
	int n;
	Student* student;

	cin >> n;
	student = new Student[n];
	for (int i = 0; i < n; i++) {
		cin >> student[i].name >> student[i].day >> student[i].month >> student[i].year;
	}
	sort(student, student + n, compare);
	cout << student[0].name << '\n' << student[n-1].name;
	
	delete[] student;

	return 0;
}