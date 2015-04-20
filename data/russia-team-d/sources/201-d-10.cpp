#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long i,j,n,m,k,l,r,x;
long long a[100500];


int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    scanf("%d%d", &n, &k);
    for (i=1; i<=n; i++)
        scanf("%d", &a[i]);
    sort(a+1,a+n+1);
    int ans=0;
    ans=(k-a[1])/(n-1);
    if (ans>a[1]) ans=a[1];
    cout << ans;

    return 0;
}
