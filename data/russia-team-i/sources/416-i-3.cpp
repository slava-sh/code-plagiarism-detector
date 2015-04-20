#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    freopen ("sochi.in", "r", stdin);
    ofstream cout("sochi.out");
    int n, d, a[3300], i, b, num=0, sum, ans=0, len=0, need=2;
    scanf ("%d %d", &n, &d);
    for (i=1; i<=3250; i++) a[i]=0;
    for (i=1; i<=n; i++)
    {
        scanf ("%d", &b);
        a[b]++;
    }
    for (i=3*d; i<=1000; i++)
    {
        len=len+a[i]*i;
        num+=a[i];
    }
    if (num==0)
    {
        for (i=3*d-1; i>=2*d; i--)
        {
            while (need>0)
            {
                if (a[i]==0) break;
                if (a[i]>0)
                {
                    ans=ans+i;
                    need--;
                    a[i]--;
                }
            }
        }
        if (need==2)
        {
            for (i=1000; i>=1; i--)
            {
                if (a[i]>0)
                {
                    need--;
                    ans=i;
                    break;
                }
            }
        }
        if (need==0)
        {
            cout << ans - 2*d << endl;
        }
        if (need>0) cout << ans << endl;
        return 0;
    }
    ans=len-2*d*(num-1);
    for (i=3*d-1; i>=2*d; i--)
    {
        while (need>0)
        {
            if (a[i]==0) break;
            if (a[i]>0)
            {
                ans=ans+i-2*d;
                need--;
                a[i]--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
