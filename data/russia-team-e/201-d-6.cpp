#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, k;
int a[100001];
long long s=0;

bool f(long mid)
{
    long l=0,i;
    l=a[1];
    for (i=2; i<=n; i++)
    {
        if (a[i]-mid>=l) l+=mid;
            else l+=(a[i]-l)+mid;
    }
    if (l<=k) return 1;
        else return 0;
}

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
        if (f(mid)) l=mid; else r=mid;
    }
    if (f(r)) cout << r; else cout << l;

    return 0;
}
