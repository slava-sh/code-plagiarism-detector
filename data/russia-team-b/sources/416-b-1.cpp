#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <fstream>
using namespace std;
int main ()
{
    freopen ("che.in", "r", stdin);
    ofstream cout("che.out");
    //freopen ("input.txt", "r", stdin);
    //freopen ("input.txt", "r", stdin);
    int n, rr, a[300001], l, r, mid, i, need;
    long long int ans=0;
    scanf ("%d %d", &n, &rr);
    for (i=1; i<=n; i++) scanf("%d", &a[i]);
    a[0]=-rr-1;
    for (i=1; i<=n; i++)
    {
        l=0;
        r=i-1;
        need=a[i]-rr;
        while (r-l>0)
        {
            mid = (l+r+1)/2;
            if (a[mid]<need)
            {
                l=mid;
            }
            else
            {
                r=mid-1;
            }
        }
            ans+=l;
    }
    cout << ans << endl;
    return 0;
}
