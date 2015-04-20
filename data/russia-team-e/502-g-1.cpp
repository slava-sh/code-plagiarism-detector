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

int n,m;

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    cin >> n >> m;
    cout << min((n-2+3)/4,(m-2+3)/4);
    return 0;
}
