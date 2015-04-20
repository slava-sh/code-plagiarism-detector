#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF=1000000000;

int getint() {
    int x;
    scanf("%d",&x);
    return x;
}

long long n,i,j,a[111111];
bool met[111111];
long long kol,d,pos;
long long sum=0;

int main()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    cin >> n >> d;
    long long ma=0;
    for (i=0;i<n;i++) {
        cin >> a[i];
        ma=max(ma,a[i]);
    }
    if (n==1) {
        cout << a[0];
        return 0;
    }
    sort(a,a+n);
    for (i=0;i<n;i++)
        if (a[i]>=d*3) {
            sum+=a[i]-d*2;
            met[i]=true;
            kol++;
        }
    if (kol==0) {
        long long ma1=a[n-2],ma2=a[n-1];
        if (ma1<d) {
            cout << ma;
        }
        else {
            cout << max(ma,ma1+ma2-d*2);
        }
        return 0;
    }
    bool fnd=false;
    for (i=0;i<n;i++)
        if (a[i]>=d*2 && !met[i]) {
            fnd=true;
            pos=i;
        }
    if (!fnd) {
        sum+=d*2;
        cout << max(ma,sum);
        return 0;
    }
    met[pos]=true;
    sum+=a[pos]-d;
    fnd=false;
    for (i=0;i<n;i++)
        if (a[i]>=d*2 && !met[i]) {
            fnd=true;
            pos=i;
        }
    if (!fnd) {
        sum+=d;
        cout << max(ma,sum);
        return 0;
    }
    sum+=a[pos]-d;
    cout << max(ma,sum);
    return 0;
}