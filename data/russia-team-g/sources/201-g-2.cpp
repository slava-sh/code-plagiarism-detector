#include <stdio.h>
#include <algorithm>
#define LL long long

using namespace std;

long n,m;

void pr(long n)
{
    long ans=0,k=0;
    if (n<3)
    {
        printf("0");
        exit(0);
    }
    k=3;
    ans=1;
    ans+=(n-k)/4;
    printf("%d", ans);
    exit(0);
}

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    scanf("%d%d", &n, &m);
    if (n>m)  swap(n,m);
    if (n==1) pr(m);
    pr(n);
    return 0;
}
