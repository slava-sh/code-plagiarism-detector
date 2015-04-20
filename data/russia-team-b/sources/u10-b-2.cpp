#include <stdio.h>
const int maxn = 300005;
int a[maxn];
int main(){
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    int n,i,j,k;
    __int64 result = 0;
    scanf("%i %i",&n,&k);
    for(i = 0;i < n; i ++)scanf("%i",a+i);
    j = n - 1;
    i = n - 1;
    while(i >= 0){
        while(j >= 0 && a[i] - a[j] <= k) j--;
        result += j + 1;
        i --;
    }
    printf("%I64d\n",result);
    return 0;
}
