#include <stdio.h>
int main(){
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    int n,m,result;
    scanf("%i %i",&n,&m);
    n --; m --;
    if(n + m == 0 || n == 1 || m == 1)result = 0; else
    if(n == 0 || m == 0) result = 1 + ((n + m - 2) >> 2) ; else
    result = 1;
    printf("%i\n",result);
    return 0;
}
