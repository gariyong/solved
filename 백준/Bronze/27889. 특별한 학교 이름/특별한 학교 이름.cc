#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	cin >> str;

	if (str == "NLCS") {
		cout << "North London Collegiate School\n";
	}
	else if (str == "BHA") {
		cout << "Branksome Hall Asia\n";
	}
	else if (str == "KIS") {
		cout << "Korea International School\n";
	}
	else if (str == "SJA") {
		cout << "St. Johnsbury Academy\n";
	}

	return 0;
}