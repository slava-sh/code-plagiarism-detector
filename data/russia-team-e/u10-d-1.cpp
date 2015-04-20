#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int n,k;
int a[maxn];
bool result_true(int m){
    for(int i = 0, s = 0; i < n; i ++){
        s += m;
        if(a[i] > s)s = a[i];
        if(s > k) return false;
    }
    return true;
}
int bin_find_result(){
    int l = 0, r = k, m, result = 0;
    if(a[0] < r)r = a[0];
    while(l <= r){
        m = (l + r) >> 1;
        if(result_true(m)) {
            result = m;
            l = m + 1;
        }else r = m - 1;
    }
    return result;
}
int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    scanf("%i %i",&n,&k);
    for(int i = 0; i < n; i ++)scanf("%i",a+i);
    sort(a,a+n);
    printf("%i\n",bin_find_result());
    return 0;
}
