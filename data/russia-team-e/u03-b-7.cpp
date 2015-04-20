#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
__int64 n, k, ans = 0, i, j, m = 2, a[300005];
int main(){
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    cin >> n >> k;
    for(i=1; i<=n; i++) cin >> a[i];
    for(i=1; i<n; i++){
        for(j=m; j<=n; j++){
            if(a[j] - a[i] > k) break;
        }
        ans += n - j + 1;
        m = j;
    }
    cout << ans;
    return 0;
}
