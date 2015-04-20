#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

const int INF=1000000000;

int getint() {
    int x;
    scanf("%d",&x);
    return x;
}

int n,k,a,mi;

int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    n=getint();k=getint();
    mi=INF;
    for (int i=0;i<n;i++) {
        a=getint();
        mi=min(mi,a);
    }
    mi=min(mi,k/n);
    cout << mi;
    return 0;
}
