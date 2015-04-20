#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<climits>
using namespace std;

int a[100001];
int b[100001];
long long s = 0;

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
    b[0] = a[0];
    int mIn = INT_MAX;
    if(s <= k)
    {
        cout << a[0];
        return 0;
    }
    for(int i = 1; i < n; i++)
    {
         b[i] = a[i] - a[i - 1];
         if(b[i] < mIn)
                mIn = b[i];
    }
    int ans = 0;
    int t = a[n - 1];
    //cout << t << endl;
    while(t <= k)
    {
        for(int j = a[n - 1]; j < t; j++)
            if(b[j] < mIn)
                mIn = b[j];
        int T = 0;
        for(int j = 0; j < t; j++)
            if(b[j] == mIn)
                T++;
        if(t + T <= k)
        {
            t += T;
            for(int j = 0; j < t - 1; j++)
            if(b[j] == mIn)
                b[j]++;
            a[t] = mIn + 1;
            ans = mIn + 1;
        }
        else
        {
            cout << ans;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
