#include <bits/stdc++.h>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.00000001
#define pi 3.1415926535897932384626433832795
#define na(x) ((x)<P?(x):(x)-P)

using namespace std;
const int N=200021;
int n,m,a[N],x[N],y[N];
bool b[N],c[N];
void sol(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) c[i]=b[i]=0;
    for (int i=1;i<n;i++) scanf("%d%d",&x[i],&y[i]);
    int I=0;
    int k=0;
    int mik=0;
    for (int i=1;i<n;i++){
        if (y[i]){
            I=i;
            for (;i<n;i++)
            c[x[i]]=1;
            }
        else {
        if (x[i]) a[x[i]]--;
        else k++;
        }
    }
    if (I){
        mik=N;
        for (int i=1;i<=m;i++)
        if (c[i]==0)
        {
            if (a[i]<=k) {b[i]=1;
            if (mik>a[i]){
                mik=a[i];
            }
            }
        }
        for (int i=I;i<n;i++)
        if (x[i]) a[x[i]]--;
        else k++;
    }
    for (int i=1;i<=m;i++)
    if (b[i]==0){
        b[i]=(a[i]<=k-mik);
    }
    for (int i=1;i<=m;i++)
    printf(b[i]?"Y":"N");
    printf("\n");
}
int main(){
    int test;
    cin>>test;
    while (test--)
        sol();
    return 0;
}
