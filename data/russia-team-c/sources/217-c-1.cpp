#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const long long INF=1000000000000000000ll;

vector <int> a[200200];
bool f[200200];
int n, v, u;

inline int dfs(int v, int u){
    if (f[v]||f[u]) return -n;
    f[v]=1;
    f[u]=1;
    int res=0;
    for (int i=0; i<a[v].size(); ++i)
        for (int j=0; j<a[u].size(); ++j)
            res=max(res, dfs(a[v][i], a[u][j])+1);
    f[v]=0;
    f[u]=0;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("dwarfs.in", "r", stdin);
    freopen("dwarfs.out", "w", stdout);
    scanf("%d", &n);
    for (int i=0; i<n-1; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].pb(y);
        a[y].pb(x);
    }
    scanf("%d%d", &v, &u);
    int ans=dfs(v, u);
    printf("%d\n", ans+1);
    return 0;
}
