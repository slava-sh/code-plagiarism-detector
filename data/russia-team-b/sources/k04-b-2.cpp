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
    }
    for(i = 1; i < n; i ++){
            j = n;
        while(d[j] - d[i] > r && j > i){
            if(d[j] - d[i] > r)k ++;
            j --;}
    }
    cout<<k;
    return 0;
}
