#include <iostream>
#include <cstdio>
using namespace std;
int l1[500],r1[500],xx[200000],yy[200000];
int v,m,n;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> xx[0] >> yy[0];
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> m;
        l1[i]=v+1;
        for (int j=1;j<=m+1;j++) {
            v++;
            cin >> xx[v] >> yy[v];
        }
        r1[i]=v;
    }
    for (int l=1;l<=n;l++)
    for (int r=l+1;r<=n;r++) {
        for (int i=l1[l];i<=r1[l]-1;i++)
        for (int j=l1[r];j<=r1[r]-1;j++) {
            double k1=(1.00000*yy[i+1]-yy[i])/(xx[i+1]-xx[i]);
            double b1=1.0000*yy[i+1]-xx[i+1]*k1;
            double k2=(1.00000*yy[j+1]-yy[j])/(xx[j+1]-xx[j]);
            double b2=1.0000*yy[j+1]-xx[j+1]*k2;
            if (k1==k2) continue;
            double xxx=(b2-b1)/(k1-k2);
            if (xxx>xx[i] && xxx<xx[i+1]) {
                cout << l << " " << r << "\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}
