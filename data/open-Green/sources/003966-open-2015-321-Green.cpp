#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
long long f[10100][12];
int v,k;
long long n,a[10000],mx;
int main() {
    cin >> n >> k;
    for (int i=2;1ll*i*i<=n;i++) {
        if (n%i==0) {
            v++;
            a[v]=i;
        }
        if (n%i==0 && n/i!=i) {
            v++;
            a[v]=n/i;
        }
    }
    sort(a+1,a+v+1);
    v++;
    a[v]=n;
    long long mxx=(n/2)+n%2;
    long long mx=mxx;
    for (int i=0;i<=v;i++)
    for (int j=0;j<=k;j++)
        f[i][j]=mxx;
    f[0][0]=1;
    a[0]=1;
    for (int i=0;i<v;i++)
    for (int j=0;j<k;j++)
        if (f[i][j]!=mxx) {
            for (int p=1;p<=v-1;p++) {
                if (a[p]*a[i]>n) break;
                int l=lower_bound(a+1,a+v+1,a[p]*a[i])-a;
                if (l==v+1) continue;
                if (a[l]!=a[p]*a[i]) continue;
                f[l][j+1]=min(f[i][j]*(a[p]/2+a[p]%2),f[l][j+1]);
                if (f[l][j+1]<mx && l==v) mx=f[l][j+1];
            }
        }
    cout << mx << "\n";
    return 0;
}
