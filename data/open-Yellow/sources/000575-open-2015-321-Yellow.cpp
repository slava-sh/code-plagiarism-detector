#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct node {
    int lf,rf,sm;
};
node tr[2000000];
int a[300000],n,m,x,y;
void buildtree(int x, int l, int r) {
    if (l==r) {
        tr[x].sm=1;
        tr[x].lf=a[l];
        tr[x].rf=a[r];
        return;
    }
    int mid=(r+l)/2;
    buildtree(x*2,l,mid);
    buildtree(x*2+1,mid+1,r);
    int c=0;
    if (tr[x*2].rf==tr[x*2+1].lf) c=1;
    tr[x].sm=tr[x*2].sm+tr[x*2+1].sm-c;
    tr[x].lf=tr[x*2].lf;
    tr[x].rf=tr[x*2+1].rf;
}
void md(int x, int l, int r, int y, int z) {
    if (l==r) {
        tr[x].lf=a[l];
        tr[x].rf=a[r];
        return;
    }
    int mid=(r+l)/2;
    if (y<=mid) md(x*2,l,mid,y,z);
    if (y>mid) md(x*2+1,mid+1,r,y,z);
    int c=0;
    if (tr[x*2].rf==tr[x*2+1].lf) c=1;
    tr[x].sm=tr[x*2].sm+tr[x*2+1].sm-c;
    tr[x].lf=tr[x*2].lf;
    tr[x].rf=tr[x*2+1].rf;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    buildtree(1,1,n);
    cin >> m;
    for (int i=1;i<=m;i++) {
        cin >> x >> y;
        a[x]=y;
        md(1,1,n,x,y);
        cout << tr[1].sm << "\n";
    }
    return 0;
}
