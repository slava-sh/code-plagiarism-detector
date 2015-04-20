#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    int n, i, j, d[300005];
    long long int  k = 0, r;
    cin>>n>>r;
    for(i = 1; i <= n; i ++)
    {
        cin>>d[i];
    }
    for(i = 1; i < n; i ++){
            j = i + 1;
            while(d[j] - d[i] <= r && j <= n)
                j ++;
            k += n - j + 1;
    }
    cout<<k;
    return 0;
}
