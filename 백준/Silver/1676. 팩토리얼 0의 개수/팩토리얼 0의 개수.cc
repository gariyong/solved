#include<iostream>
using namespace std;

int main(void)
{
	int cnt = 0;
	int n;
	cin >> n;
    
	for (int i = 1; i <= n; i++)
	{
		if (i % 5 == 0)
		{
			cnt++;
			if (i % 25 == 0)
				cnt++;
			if (i % 125 == 0)
				cnt++;
		}
	}
    
	cout << cnt;
}