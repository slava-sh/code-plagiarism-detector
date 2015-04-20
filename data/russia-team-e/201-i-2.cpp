#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
long long d, a[100001], b[100001];

bool cmp(int x, int y){
    return x>y;
}

int main(){
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    cin >> n >> d;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+n+1,cmp);
    int k=1;
    for (int i=1;i<=n;++i)
        if (a[i]>=3*d) {
        ++k;
        b[k]=a[i];
    }

    int col=0;
    for (int i=1;i<=n;++i){

        if (a[i]<3*d) {
            if (col==0){
                b[1]=a[i];
                ++col;
            }
            else if (col==1){
                ++k;
                b[k]=a[i];
                ++col;
            }
        }
    }

    if (col>0)
    {
        long long ans=a[1]-d+a[k]-d;
        for (int i=2;i<k;++i)
            ans+=a[i]-2*d;
        cout << ans;
    }
    else {
        long long ans=a[2]-d+a[k]-d;
        for (int i=3;i<k;++i)
            ans+=a[i]-2*d;
        cout << ans;
    }
    return 0;
}
