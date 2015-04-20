#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    int r, n, i, j, k = 0, d[300005];
    cin>>n>>r;
    for(i = 1; i <= n; i ++)
    {
        cin>>d[i];
        for(j = 1; j < i; j ++)
        {
            if(d[i] - d[j] > r)k ++;
        }
    }
    cout<<k;
    return 0;
}
