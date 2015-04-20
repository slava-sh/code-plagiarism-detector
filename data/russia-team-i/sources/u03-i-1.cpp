#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, d, i, a[100005], maxn = 0;
int main(){
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    cin >> n >> d;
    for(i = 1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1); maxn = a[n];
    for(i=n-1; i>=1; i--){
        if(a[i]>2*d) maxn += a[i] - 2*d;
    }
    cout << maxn;
    return 0;
}
