#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs(vector<vector<int>>& map, int start_x, int start_y, int item_x, int item_y){
    queue<pair<int,int>> q;
    vector<vector<int>> dist(102, vector<int>(102, -1));

    q.push({start_y, start_x});
    dist[start_y][start_x] = 0;

    while(!q.empty()){

        auto [cur_y, cur_x] = q.front();
        q.pop();

        if(cur_y == item_y && cur_x == item_x){
            return dist[cur_y][cur_x] / 2;
        }

        for(int k = 0; k < 4; k++){

            int ny = cur_y + dy[k];
            int nx = cur_x + dx[k];

            if(ny < 0 || ny >= 102 || nx < 0 || nx >= 102){
             continue;   
            }

            if(map[ny][nx] != 1){
                continue;
            }
            
            if(dist[ny][nx] != -1){
                continue;
            }

            dist[ny][nx] = dist[cur_y][cur_x] + 1;
            q.push({ny, nx});
        }
    }

    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

    vector<vector<int>> map(102, vector<int>(102, 0));

    for(auto x : rectangle){
        int x1 = x[0] * 2;
        int y1 = x[1] * 2;
        int x2 = x[2] * 2;
        int y2 = x[3] * 2;

        for(int y = y1; y <= y2; y++){
            for(int x = x1; x <= x2; x++){
                map[y][x] = 1;
            }
        }
    }

    for(auto x : rectangle){
        int x1 = x[0] * 2;
        int y1 = x[1] * 2;
        int x2 = x[2] * 2;
        int y2 = x[3] * 2;

        for(int y = y1 + 1; y < y2; y++){
            for(int x = x1 + 1; x < x2; x++){
                map[y][x] = 0;
            }
        }
    }

    return bfs(map, characterX * 2, characterY * 2, itemX * 2, itemY * 2);
}