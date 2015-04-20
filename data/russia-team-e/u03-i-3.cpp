#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
__int64 n, d, i, a[100005], maxn = 0, j;
int main(){
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    scanf("%I64d %I64d", &n, &d);
    for(i = 1; i<=n; i++){
        scanf("%I64d", a+i);
        if(maxn < a[i]){ maxn = a[i]; j = i;}
    }
    a[j] = 0;
    for(i=1; i<=n; i++){
        if(a[i]>2*d) maxn += (a[i] - 2*d);
    }
    printf("%I64d", maxn);
    return 0;
}
