#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int a[300001], ans = 0;
const bool D = 0;

int main ()
{
    if(D)
    {
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    else
    {
        freopen("che.in", "r", stdout);
        freopen("che.out", "w", stdin);
    }
    int n, r;
    cin >> n >> r;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = n; i > 1; i--)
    {
        int t = a[i];
        int j = i - 1;
        while(t - a[j] <= r && j >= 1)
            j--;
        if(t - a[j] > r)
        {
                ans += j;
        }
    }
    cout << ans;
    return 0;
}

