#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 1000000007;

int g[2000][2000], n, a;
char used[2000];

void dfs (int v) {
    if (used[v]) return;
    used[v] = true;
    for (int i = 0; i < n; ++i) {
        if (g[v][i]) dfs (i);
    }
}


int main () {
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        used[i] = false;
        if (a == -1) continue;
        if (a > i + 1) return cout << 0, 0;
        for (int j = 0; j < a; ++j) {
                if (i + j >= n) return cout << 0, 0;
                g[j][i+j]=true;
                g[i+j][j]=true;
        }
    }
    if(n%2==0)
    {
        cout<<0<<endl;
        return 0;
    }
    long long ans=1;
    for(int i=0;i<n;i++)
    {
        if(!used[i])
        {
            dfs(i);
            ans=(ans*2)%mod;
        }
    }
    if(a==1)cout<<ans/2; else
    cout << ans;
}
