#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int n,m,x,ans;
int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    cin >> n >> m;
    x = min(n,m)-1;
    if (x>=2) {
        x-=2;
        ans++;
    }
    ans+=x/4;
    cout << ans;
    return 0;
}

