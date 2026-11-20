#include <iostream>

using namespace std;

int main(){
int cnt = 0;
int n;

cin >> n;

for(int i = 0; i < 5; i++){
	int x;

	cin >> x;
	if(x % 10 == n){
	cnt++;
}
}

cout << cnt;

return 0;
}