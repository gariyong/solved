#include <vector>
#include <algorithm>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int dfs(vector<vector<int>>& picture, vector<vector<bool>>& visit, int x, int y, int n, int m) {
    visit[y][x] = true;
    int color = picture[y][x];
    int size = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (visit[ny][nx]) continue;
        if (picture[ny][nx] != color) continue; 
        
        size += dfs(picture, visit, nx, ny, n, m);
    }

    return size;
}

vector<int> solution(int n, int m, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<bool>>visit(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (picture[i][j] != 0 && !visit[i][j]) {
                number_of_area++;
                int area_size = dfs(picture, visit, j, i, n, m);
                max_size_of_one_area = max(max_size_of_one_area, area_size);
            }
        }
    }

    return { number_of_area, max_size_of_one_area };
}