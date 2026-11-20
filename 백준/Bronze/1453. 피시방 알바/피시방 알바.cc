#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int pc[101] = {0};
    int cnt = 0;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        if(pc[x] == 0){
            pc[x] = 1;
        }else{
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}