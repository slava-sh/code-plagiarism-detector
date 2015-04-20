#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100005;
long n, k;
int a[maxn];
bool tekshir(int m){
    for(int i=0, s=0; i<n; i++){
        s += m;
        if(a[i]>s) s = a[i];
        if(s>k) return false;
    }
    return true;
}
int solve(){
    int result = 0;
    int l = 0, r = k, m;
    if(r>a[0]) r = a[0];
    while(l<=r){
        m = (l+r) >> 1;
        if(tekshir(m)){
            result = m; l = m+1;
        }
        else r = m - 1;
    }
    return result;
}
int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    scanf("%i %i", &n, &k);
    for(int i=0; i<n; i++) scanf("%i", a+i);
    sort(a,a+n);
    printf("%i\n",solve());
    return 0;
}
