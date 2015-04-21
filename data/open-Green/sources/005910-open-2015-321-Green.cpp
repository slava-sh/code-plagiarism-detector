#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
long long f[20100][12];
int v,k;
vector <int> ed[20100];
long long n,a[20000],mx;
int main() {
   // freopen("input.txt","r",stdin);
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
    a[0]=1;
    for (int i=1;i<=v;i++)
    for (int j=0;j<i;j++)
        if (a[i]%a[j]==0) ed[i].push_back(j);
    f[0][0]=1;
    for (int i=1;i<=v;i++)
    for (int j=1;j<=k;j++) {
        long long mn=mxx;
        for (int p=0;p<ed[i].size();p++) {
            int x=ed[i][p];
            if (f[x][j-1]==mxx) continue;
            long long df=(a[i]/a[x]);
            df=(df/2+df%2);
            if (mn>df*f[x][j-1]) mn=df*f[x][j-1];
        }
        if (mn<mx && i==v) mx=mn;
        f[i][j]=mn;
    }
    cout << mx << "\n";
    return 0;
}
