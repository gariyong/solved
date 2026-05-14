#include <string>
#include <vector>

using namespace std;

int dy1[] = { 1, -1, 0, 0 };
int dx1[] = { 0, 0, 1, -1 };

int dy2[] = { 2, -2, 0, 0 };
int dx2[] = { 0, 0, 2, -2 };

int dy_diag[] = { 1, 1,- 1, -1 };
int dx_diag[] = { -1, 1, -1, 1 };

int check_place(vector<string>& place) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (place[i][j] != 'P') continue;

            for (int k = 0; k < 4; k++) {
                int ny = i + dy1[k];
                int nx = j + dx1[k];
                
                if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
               
                if (place[ny][nx] == 'P') return 0;
            }

            for (int k = 0; k < 4; k++) {
                int ny = i + dy2[k];
                int nx = j + dx2[k];

                if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;

                int my = i + dy2[k] / 2;
                int mx = j + dx2[k] / 2;

                if (place[ny][nx] == 'P' && place[my][mx] != 'X') return 0;
            }

            for (int k = 0; k < 4; k++) {
                int ny = i + dy_diag[k];
                int nx = j + dx_diag[k];

                if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;

                if (place[ny][nx] == 'P') {
                    if (place[i][nx] != 'X' || place[ny][j] != 'X') return 0;
                }
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> check;

    for (auto& place : places) {
        check.push_back(check_place(place));
    }

    return check;
}