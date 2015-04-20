#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
__int64 n, d, i, a[100005], ans = 0, j = 1;
int main(){
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    scanf("%I64d %I64d", &n, &d);
    for(i = 1; i<=n; i++)
        scanf("%I64d", a+i);

    sort(a+1,a+n+1); j = 1;
    ans = a[n];
    for(i=n-1; i>=1; i--){
        if(a[i]>=3*d){
            ans += (a[i] - 2*d);
        }else{ j = i; break; }
    }
    for(i=j; i>j-2 && j-2>0; i--)
        if(a[i]>2*d) ans += (a[i] - 2*d);

    printf("%I64d", ans);
    return 0;
}
