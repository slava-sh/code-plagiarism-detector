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
    int n, d, t = 0, s  = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= 3 * d)
            a[i] = a[i];
        else if(a[i] > 2 * d && t < 2)
            t++;
        else
            a[i] = 0;
        if(a[i] > 0)
        s += a[i] - 2 * d;
    }
    cout << s + 2 * d;
    return 0;
}

