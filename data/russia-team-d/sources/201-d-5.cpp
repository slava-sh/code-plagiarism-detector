#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, k;
int a[100001];
long long s=0;

int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1;i<=n;++i){ cin >> a[i]; s+=a[i];}
    sort(a+1,a+n+1);
    if (s<=k) {
        cout << a[1];
        return 0;
    }
    int l=1, r=a[1];
    while (r-l>1){
        int mid=(l+r)/2;
        if (mid*n<k) l=mid; else r=mid;
    }
    if (r*n<=k) cout << r; else cout << l;

    return 0;
}
