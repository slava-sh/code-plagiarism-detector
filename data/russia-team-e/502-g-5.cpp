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

long long n,m;

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    cin >> n >> m;
    if (n>m) swap(n,m);
    if (n==1) {
        cout << (m+1)/4;
        return 0;
    }
    if (n==2) {
        cout << 0;
        return 0;
    }
    if (n==3) {
        cout << 1;
        return 0;
    }
    cout << min(2LL,min((n+1)/4,(m+1)/4));
    return 0;
}
