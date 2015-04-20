#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int n,m,x,ans;

int Our (int x) {
    ans=0;
    if (x>=2) {
        x-=2;
        ans++;
    }
    ans+=x/4;
    return ans;
}

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    cin >> n >> m;
    x = min(n,m)-1;
    if ((n==1) || (m==1)) {
        x = max(n,m)-1;
        cout << Our(x);
    } else {
        x=min(n,m)-1;
        cout << min(Our(x),1);
    }
    return 0;
}

