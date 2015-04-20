#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long i,j,n,m,k,l,s,r,x;
long a[100500];

int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    scanf("%d%d", &n, &k);
    for (i=1; i<=n; i++)
        scanf("%d", &a[i]);
    sort(a+1,a+n+1);
    l=1;r=a[1];
    while (l<r)
    {
        x=(l+r)/2;
        s=0;
        for (i=1; i<=n; i++)
            s=max(s+x,a[i]+x);
        if (s>k) r=x;
                else l=x+1;
    }
    printf("%d", l);
}
