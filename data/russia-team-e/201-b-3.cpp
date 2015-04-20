#include <stdio.h>
#include <algorithm>
#define LL long long

using namespace std;

long i,l,k,r,n,d;
long long a[400500];

int main()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    scanf("%d%d", &n, &d);
    for (i=1; i<=n; i++)
            scanf("%d", &a[i]);
    LL ans=0;
    for (i=1; i<=n; i++)
    {
        if (a[n]-a[i]<=d) break;
        l=i;r=n;
        while (l<r)
        {
            k=(l+r)/2;
            if (a[k]-a[i]>d) r=k;
                else l=k+1;
        }
        ans+=n-l+1;
    }
    printf("%I64d", ans);
    return 0;
}
