#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int a[300091], ans = 0;
const bool D = 0;

int main ()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    int n, r;
    scanf("%d%d", &n, &r);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
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

