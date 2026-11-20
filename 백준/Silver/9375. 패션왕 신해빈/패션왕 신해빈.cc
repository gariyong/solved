#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct clothes{
	string type;
	int cnt = 0;
}clothes;

int main() {
	int t;

	cin >> t;
	while (t > 0) {
		int n;
		int com = 1;
		vector <clothes> c;
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			string type;
			string name;
			cin >> name >> type;
			if (c.size() == 0) {
				clothes h;
				h.type = type;
				h.cnt++;
				c.push_back(h);
			}
			else {
				int flag = 0;
				for (int i = 0; i < c.size(); i++) {
					if (c[i].type == type) {
						c[i].cnt++;
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					clothes h;
					h.type = type;
					h.cnt++;
					c.push_back(h);
				}
			}
		}

		for (int i = 0; i < c.size(); i++) {
			com *= (c[i].cnt + 1);
		}
		com--;
		
		cout << com << '\n';

		t--;
	}

	return 0;
}