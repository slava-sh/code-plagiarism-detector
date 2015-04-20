#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    int r, d[300005], n, i, j;
    long long int k = 0;
    cin>>n>>r;
    for(i = 1; i <= n; i ++)
    {
        cin>>d[i];
    }
    j = 2;
    for(i = 1; i < n; i ++){
            while(d[j] - d[i] <= r && j <= n)
                j ++;
            k += n - j + 1;
    }
    cout<<k;
    return 0;
}
