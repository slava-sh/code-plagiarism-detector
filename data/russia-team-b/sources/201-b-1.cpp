#include <stdio.h>
#include <algorithm>
#define LL long long

using namespace std;

long i,l,k,r,n;
long long a[1000500];

int main()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    scanf("%d%d", &n, &r);
    for (i=1; i<=n; i++)
            scanf("%d", &a[i]);
    sort(a+1,a+n+1);
    LL ans=0;
    for (i=1; i<=n; i++)
    {
        if (a[n]-a[i]<=r) break;
        l=i;r=n;
        while (l<r)
        {
            k=(l+r)/2;
            if (a[k]-a[i]>r) r=k;
                else l=k+1;
        }
        ans+=n-l+1;
    }
    printf("%I64d", ans);
    return 0;
}
