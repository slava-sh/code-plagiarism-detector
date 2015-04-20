#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 300007;
int a[maxn];
int binar(int k, int l, int r){
    if(r == l) return l;
    int m = (l+r) >> 1;
    if(a[m]<=k) return binar(k,m+1,r);
    return binar(k,l,m);
}
 
int main(){
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    int n, i, k;
    __int64 result = 0;
    scanf("%i %i %i", &n, &k, &a[0]);
    for(i=1; i<n; i++){
        scanf("%i", a+i);
        result += binar(a[i]-k-1, 0, i);
    }
    printf("%i\n", result);
    
    return 0;
}
