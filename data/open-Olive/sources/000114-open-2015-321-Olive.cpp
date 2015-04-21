#include <iostream>
#include <cstdio>
using namespace std;
int a[2000000],f[200000],fn[2000000],g[2000000],n,mx,nm,l,r,ans;
void findmn(int x) {
    while (x>0) {
        if (fn[x]>mx) {
            mx=fn[x];
            nm=g[x];
        }
        x=(x&(x-1));
    }
}
void md(int x, int y, int z) {
    while (x<=n) {
        if (fn[x]<y) {
            fn[x]=y;
            g[x]=z;
        }
        x=((x|(x-1))+1);
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        a[i]=n-a[i]+1;
    }
    for (int i=1;i<=n;i++) {
        mx=0;
        findmn(a[i]-1);
        f[i]=mx+1;
        if (mx==0) nm=i;
        md(a[i],f[i],nm);
        if (f[i]>ans) {
            ans=f[i];
            l=nm;
            r=i;
        }
    }
    if (ans==1) cout << "-1 -1\n";
    else {
        cout << l << " " << r << "\n";
        return 0;
    }
    return 0;
}
