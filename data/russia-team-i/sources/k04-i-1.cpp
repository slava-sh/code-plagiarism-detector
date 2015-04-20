#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int a[100001], n, m, d, s = 0, i, c[100001], k = 0, max1 = 0, max2 = 0;
    cin>>m>>d;
    for(i = 1; i <= m; i++)
    {
        cin>>a[i];
    }
    for(i = 1; i <= m; i ++)
    {
        if(a[i] >= 2 * d && a[i] < 3 * d){
            if(max1 < a[i]){max2 = max1; max1 = a[i];}
            else if(max2 < a[i])max2 = a[i];
            }
        if(a[i] >= 3 * d){s += a[i]; k ++;}
    }
    s += max1 + max2;
    n = k;
    if(max1)n ++;
    if(max2)n ++;
    cout<<s - 2 * d * (n - 1);
    return 0;
}
