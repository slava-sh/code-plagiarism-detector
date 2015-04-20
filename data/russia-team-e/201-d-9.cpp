#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long i,j,n,m,k,l,r,x;
long long a[100500];
long long d;

long long f(long x)
{
 long long s;
        s=a[1];
        long t;
        for (i=2; i<=n; i++)
            if (a[i]-s>0) {t=a[i]-s;if (t>=k) s+=t; else s+=x;}
                else s+=x;
        return  s;
}

int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    scanf("%d%d", &n, &k);
    for (i=1; i<=n; i++)
        scanf("%d", &a[i]);
    sort(a+1,a+n+1);
    l=0;r=a[1];
    while (l+1<r)
    {
        x=(l+r)/2;
        d=f(x);
        if (d>k) r=x;
                else l=x;
    }
   //printf("%d %d\n", l, r);
    if (f(r)<=k) printf("%d", r); else if (f(l)<=k) printf("%d", l); else printf("0");
}
