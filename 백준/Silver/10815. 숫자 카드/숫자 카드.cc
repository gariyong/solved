#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, temp;
    vector<int> v;
    
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    scanf("%d", &n);
    
    while (n--) {
        scanf("%d", &temp);
        printf("%d ", binary_search(v.begin(), v.end(), temp));
    }

    return 0;
}