#include <iostream>
#include <cstdio>
using namespace std;
long long f[3001][3001];
int g[3001][3001];
long long b[5000],a[5000],c,d;
int n,m;
void chck(int i, int j) {
    if (g[i][j]==0) {
        g[i][j]=1;
        f[i][j]=1e18;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> c >> d;
    for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
    f[1][1]=(b[1]-a[1])*d;
    g[1][1]=1;
    for (int i=1;i<n;i++)
    for (int j=1;j<=m;j++)
        if (g[i][j]==1) {
            if (j<m) {
                chck(i+1,j+1);
                f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+(b[i+1]-a[i+1])*d);
            }
            chck(i+1,1);
            f[i+1][1]=min(f[i+1][1],f[i][j]+c+(b[i+1]-a[i+1])*d);
            chck(i+1,j);
            f[i+1][j]=min(f[i+1][j],f[i][j]+(b[i+1]-b[i])*d);
        }
    long long mn=1e18;
    for (int j=1;j<=m;j++)
        if (f[n][j]<mn && g[n][j]==1) mn=f[n][j];
    cout << mn << "\n";
    return 0;
}
