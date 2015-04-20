#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
__int64 n, d, i, a[100005], ans = 0, j = n;

int main(){
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    scanf("%I64d %I64d", &n, &d);
    for(i = 1; i<=n; i++)
        scanf("%I64d", a+i);
    sort(a+1,a+n+1); j = 1;
    for(i=n; i>=1; i--){
        if(a[i]>=3*d){
            ans += (a[i] - 2*d);
        }else{ j = i; break; }
    }
    if( ans ) ans += 2*d;

    if(j>0 && a[j] > 2*d){ ans += (a[j] - 2*d); j--; }
    if(j>0 && a[j] > 2*d){ ans += (a[j] - 2*d); j--; }

    printf("%I64d", ans);
    return 0;
}

