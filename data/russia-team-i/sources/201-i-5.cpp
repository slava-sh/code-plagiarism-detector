#include <stdio.h>
#include <algorithm>
#define LL long long

using namespace std;

long a[1000500];
long n,i,j,d,l,k;
long ans;

void as(long n)
{
    printf("%d", n);
    exit(0);
}

int main()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    scanf("%d%d", &n, &d);
    for (i=1; i<=n; i++)
        scanf("%d", &a[i]);
    sort(a+1,a+n+1);
    l=0;
    for (i=1; i<=n; i++)
        if (a[i]>=3*d) {l=i; break;}
    k=0;
    for (i=1; i<=n; i++)
        if (a[i]>=2*d) {k=i; break;}
    if (k==0) as(a[n]);
    ans=0;
    if (l==0)
    {
        if (n-k+1==1) as(a[n]);
        for (i=k; i<=n; i++)
            ans+=a[i]-2*d;
        as(ans+2*d);
    }
    ans=0;
    for (i=l; i<=n; i++)
        ans+=a[i]-2*d;
    if (l==1) as(ans+2*d);
    if (l==2) as(ans+a[1]);
    as(ans+a[l-1]-d+a[l-2]-d);
    return 0;
}
