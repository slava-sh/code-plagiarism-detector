#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int n,m,st=1,p,l,r,sum0,sum1;
int a[2][200000];
int b[2][500000];

void change(int p,int l,int x)
{
    int i=l+st-1;
    b[p][i]=x;
    while (i>1) {
        i=i/2;
        b[p][i]=b[p][2*i]+b[p][2*i+1];
    }
}

int cnt(int p,int l,int r)
{
    int ll=l+st-1,rr=r+st-1;
    int s=0;
    while (ll<=rr) {
        if ((ll&1)==1) s+=b[p][ll];
        if ((rr&1)==0) s+=b[p][rr];
        ll=(ll+1)/2;
        rr=(rr-1)/2;
    }
    return s;
}

int main()
{
    freopen("signchange.in","r",stdin);
    freopen("signchange.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        if ((i&1)==0) scanf("%d",&a[0][i/2]);
        else scanf("%d",&a[1][(i+1)/2]);

    while (2*st<n) st*=2;
    for (int i=(n/2)+1;i<=st;i++) a[0][i]=0;
    for (int i=(n+1/2)+1;i<=st;i++) a[1][i]=0;
    for (int i=1;i<=st;i++) {
        b[0][st+i-1]=a[0][i];
        b[1][st+i-1]=a[1][i];
    }
    for (int i=st-1;i>0;i--) {
        b[0][i]=b[0][2*i]+b[0][2*i+1];
        b[1][i]=b[1][2*i]+b[1][2*i+1];
    }

    scanf("%d",&m);
    for (int i=1;i<=m;i++) {
        scanf("%d%d%d",&p,&l,&r);
        if (p==0) {
            if ((l&1)==0) change(0,l/2,r);
            else change(1,(l+1)/2,r);
        } else {
            sum0=cnt(0,(l+1)/2,r/2);
            sum1=cnt(1,(l+2)/2,(r+1)/2);
            if ((l&1)==0) printf("%d\n",(sum0-sum1));
            else printf("%d\n",(sum1-sum0));
        }
    }
    return 0;
}
