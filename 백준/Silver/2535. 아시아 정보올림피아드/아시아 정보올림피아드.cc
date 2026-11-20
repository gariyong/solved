#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Student {
	int country;
	int num;
	int grade;
}Student;

bool compare(const Student& a, const Student& b) {
	return a.grade > b.grade;
}

int main() {
	int n;
	int cnt = 0;
	int* cnt_country;
	Student* student;

	cin >> n;
	cnt_country = new int[n + 1]();
	student = new Student[n];

	for (int i = 0; i < n; i++) {
		cin >> student[i].country >> student[i].num >> student[i].grade;
	}
	sort(student, student + n, compare);

	for (int i = 0; i < n; i++ ) {
		if (cnt_country[student[i].country] != 2) {
			cnt_country[student[i].country]++;
			cout << student[i].country << ' ' << student[i].num << '\n';
			cnt++;
		}
		if (cnt == 3) {
			break;
		}
	}
	delete[] cnt_country;
	delete[] student;

	return 0;
}