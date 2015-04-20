#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN=111111;

int a[MAXN],i,j,l,r,n,k;

bool foo(int x) {
    int r=0;
    int ans=1000000000;
    for (int i=0;i<n;i++) {
        int strt=max(0,r-(a[i]-x));
        int endd=min(k,strt+a[i]);
        ans=min(ans,endd-r);
        r=endd;
    }
    return ans>=x;
}

int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    cin >> n >> k;
    r=1000000000;
    for (i=0;i<n;i++) {
        cin >> a[i];
        r=min(r,a[i]);
    }
    sort(a,a+n);
    l=0,r++;
    while (r-l>1) {
        int mid=(l+r)/2;
        if (foo(mid)) l=mid;
        else r=mid;
    }
    foo(l);
    cout << l;
    return 0;
}
