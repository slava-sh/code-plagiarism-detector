#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long i,j,n,m,k,l,r,x, col_k=0;
long long a[100500], s=0;


int main(){
    freopen("fence.in","r",stdin);
   freopen("fence.out","w",stdout);
    scanf("%d%d", &n, &k);

    for (i=1; i<=n; i++){
        scanf("%d"
    , &a[i]);
        s+=a[i];
        if (a[i]==k) ++col_k;
    }
    sort(a+1,a+n+1);
    if (n==1){
        cout << a[1];
        return 0;
    }
    if (col_k>1){
        cout << 0;
        return 0;
    }
    if (col_k==1){
        cout << min(min(a[1],(k-a[1])/(n-1)),a[n]-a[n-1]);
        return 0;
    }
    cout << min(min(a[1],(k-a[1])/(n-1)),k-a[n]);

    return 0;
}
