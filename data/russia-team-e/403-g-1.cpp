#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int m,n;
    cin >> n >> m;
    cout << (max(n, m) + 1) / 4;
    return 0;
}
