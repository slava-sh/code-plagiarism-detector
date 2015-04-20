#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, l, r, mid, i, a;
vector <int> test;

bool can(int cur)
{
    long long int tec=1;
    for (int j=0; j<n; j++)
    {
        if (j==0) tec=test[j]+1;
        if (j>0)
        {
            tec+=cur;
            if (tec<test[j]+1) tec=test[j]+1;
        }
    }
    if (tec<=k+1) return true;
    return false;
}

int main ()
{
    freopen ("fence.in", "r", stdin);
    ofstream cout("fence.out");
    scanf ("%d %d", &n, &k);
    for(i = 1; i <= n; i++)
    {
        scanf ("%d", &a);
        test.push_back(a);
    }
    sort (test.begin(), test.end());
    l=0;
    r=test[0];
    while (r-l>0)
    {
        mid=(l+r+1)/2;
        if (can(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout << l << endl;
    return 0;
}
