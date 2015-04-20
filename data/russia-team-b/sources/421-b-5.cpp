#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int a[300091], ans = 0, d, n;
int an;
const bool D = 0;

int binsearch(int l, int r, int t)
{
    int x;
    an = 1;
    int m = (r + l) / 2;
    while(r > l)
    {
        m = (r + l) / 2;
       // cout << l << ' ' << m << ' ' << r <<' ' << a[m] << endl;
        if(a[m] > t + d)
        {
            if(m == n)
                an = 1;
            else
                an = n - m + 1;
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    //cout << an << endl;
    if(an != -1)
        return an;
    else return 0;
}

int main ()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        int t = a[i];
        if(a[n] <= t + d)
            continue;
        int r = n;
        int l = i;
        int m = 0;
        ans += binsearch(l, r, t);
    }
    cout << ans;
    return 0;
}

