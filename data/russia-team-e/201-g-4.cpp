#include <stdio.h>
#include <algorithm>
#define LL long long

using namespace std;

long n,m;

void as(long n)
{
    printf("%d", n);
    exit(0);
}

void pr(long n)
{
    long ans,k;
    if (n<3) as(0);
    ans=1;
    k=3;
    ans+=(n-k)/4;
    as(ans);
}

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    scanf("%d%d", &n, &m);
    if (n>m)  swap(n,m);
    if (n==2) as(0);
    if (n==1) pr(m);
    as(1);
    return 0;
}
