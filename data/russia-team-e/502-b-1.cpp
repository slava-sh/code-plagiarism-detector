#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int getint() {
    int x;
    scanf("%d",&x);
    return x;
}

int n,ras,l,l2;
long long ans;
int a[333333];

int main()
{
    freopen("che.in","r",stdin);
    freopen("che.out","w",stdout);
    n=getint();ras=getint();
    for (int i=0;i<n;i++)
        a[i]=getint();
    l=l2=0;
    for (int i=0;i<n;i++) {
        int r=i;
        while (a[r]-a[l]>ras*2) l++;
        while (a[r]-a[l2+1]>ras) l2++;
        if (a[r]-a[l2]>ras) {
            ans+=(long long)(l2-l+1);
        }
    }
    cout << ans;
    return 0;
}
