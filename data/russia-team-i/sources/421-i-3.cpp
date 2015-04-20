#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int a[100009];

int main ()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, d, t = 0;
    long long s  = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int mAx = a[n - 1];
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] >= 3 * d)
                ;
        else if(a[i] > 2 * d && t < 2)
            t++;
        else
            a[i] = 0;
        if(a[i] > 0)
        s += a[i] - 2 * d;
    }
    if(s <= 0)
        cout << mAx;
    else
    cout << s + 2 * d;
    return 0;
}

