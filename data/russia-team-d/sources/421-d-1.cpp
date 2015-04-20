#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int a[100001];

int main ()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int n, k;
    long long s = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
       {
           cin >> a[i];
           s += a[i];
       }
    sort(a, a + n);
    if(s <= k)
    {
        cout << a[0];
        return 0;
    }
    int x = 0, l;
    for(int j = 1; j <= a[0]; j++)
    {
        l=a[0];
        for(int i = 1; i < n; i++)
           if (a[i]-l != 0)
                l += min(a[i] - l, j);
           else
            l += j;
        if(l <= k)
        {
            x = j;
        }
    }
    cout << x;
    return 0;
}
