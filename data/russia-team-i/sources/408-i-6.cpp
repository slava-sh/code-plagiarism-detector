#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool comp(long long int i,long long int j)
{
    return (j<=i);
}
int main()
{
    freopen("sochi.in","r", stdin);
    freopen("sochi.out","w", stdout);
    float x, s = 0;
    long long int n,d;
    vector <float> a;
    cin>>n>>d;
    bool first = true;
    bool second = true;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        a.push_back(x);
    }
    if (n==1)
    {
        cout<<a[0];
        return 0;
    }
    sort(a.rbegin(),a.rend(),comp);
    for (int i = 0; i < n; i++)
    {
        if (a[i]-d>0)
        {
            if(first)
            {
                first = false;
                s = a[i]-d;
                continue;
            }
            if (!first && second)
            {
                second = false;
                s=s+a[i]-d;
                continue;
            }
            if(a[i]-2*d>0) s+=a[i]-2*d;
        }
    }
    if (a[n-1]>=s)  cout<<a[n-1];
        else cout<<s;
    return 0;
}
