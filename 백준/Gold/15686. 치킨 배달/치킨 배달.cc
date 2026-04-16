#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

const int INF = numeric_limits<int> ::max();
int city[50][50] = { {0} };

void backtracking(vector<pair<int, int>>& home, vector<pair<int, int>>& chicken,
	vector<pair<int, int>>& cur, int& m, int& distance, int start) {
	if (cur.size() == m) {
		int cnt_home = home.size();
		int sum_dis = 0;

		for (int i = 0; i < cnt_home; i++) {
			int min_dis = INF;

			for (int j = 0; j < m; j++) {
				int d = abs(home[i].first - cur[j].first) + abs(home[i].second - cur[j].second);
				min_dis = min(min_dis, d);
			}
			sum_dis += min_dis;
		}

		distance = min(distance, sum_dis);

		return;
	}

	for (int i = start; i < chicken.size(); i++) {
		cur.push_back(chicken[i]);
		backtracking(home, chicken, cur, m, distance, i + 1);
		cur.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int chicken_distance = INF;
	vector<pair <int, int>> home;
	vector<pair<int, int>> chicken;
	vector<pair<int, int>> cur;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			
			if (city[i][j] == 1) {
				home.push_back({ i, j });
			}

			if (city[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	backtracking(home, chicken, cur, m, chicken_distance, 0);

	cout << chicken_distance;

	return 0;
}