#include <iostream>
#include <cstdio>
using namespace std;
int ans,mn,l,n,r,a[50000],k;
int f[5001][5001];
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        if (a[i]==i) k++;
    }
    if (k==n) {
        cout << "-1 -1\n";
        return 0;
    }
    for (int i=1;i<=n;i++) {
        for (int j=n;j>=1;j--)
            if (a[j]<a[i]) f[i][j]=f[i][j+1]+1;
            else f[i][j]=f[i][j+1];
    }
    mn=n*100;
    for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++) {
        ans=-f[i][i]-f[j][j]+f[i][j+1]+f[j][i+1];
        if (a[j]>a[i]) ans--;
        if (ans<mn) {
            mn=ans;
            l=i;
            r=j;
        }
    }
    for (int i=1;i<=n;i++) {

    }
    //cout << l << " " << r << "\n";
    return 0;
}
