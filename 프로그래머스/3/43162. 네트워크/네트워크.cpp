#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& computers, vector<int>& visit, int n, int start){
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        visit[cur] = 1;
        
        for(int i = 0; i < n; i++){
            if(computers[cur][i] == 1 && visit[i] == -1){
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int network = 0;
    vector<int> visit(n, -1);
    
    for(int i = 0; i < n; i++){
        if(visit[i] == 1) continue;
        
        bfs(computers, visit, n, i);
        network++;
    }
    
    return network;
}