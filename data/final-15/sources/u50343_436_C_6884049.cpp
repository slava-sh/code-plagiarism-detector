//#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
typedef long  long LL;

const int N =  1005;
const int M = 1000005;
const int inf = 1 << 28;
const int mod = 1e9 + 7;
const double eps = 1e-8;
using namespace std;

char s[15];
int ans[N][15][55];
int d[N][N];
int maz[N][N];
int cnt[1 << 11];


int dis[N], pre[N], vis[N];
int Prim(int n)
{
    int i,j;
    int sum=0,tmp,u;
    for(i=0;i<=n;i++)
        vis[i]=0,dis[i]=maz[0][i],pre[i]=0;
    vis[0]=1;
    for(i=1;i <= n;i++)
    {
        tmp=inf,u=-1;
        for(j=0;j<=n;j++)
            if(!vis[j]&&dis[j]<tmp) tmp=dis[j],u=j;
        vis[u]=1;
        sum+=maz[pre[u]][u];
        for(j=0;j<=n;j++)
        {
            if(!vis[j]&&dis[j]>maz[u][j])
            {
                dis[j]=maz[u][j];
                pre[j]=u;
            }
        }
    }
    return sum;
}

vector<int> g[N];

void graph(int n) {
    for (int i = 0; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
//        cout << i << " " << pre[i] << endl;
        g[i].push_back(pre[i]);
        g[pre[i]].push_back(i);
    }
}

void dfs(int u, int fa, int deep) {
    if (deep) {
        printf("%d %d\n", u, fa);
    }
    for (int i = 0; i < (int)g[u].size(); i++) {
        if (g[u][i] == fa) continue;
        dfs(g[u][i], u, deep + 1);
    }
}

int n, m, k, w;




int main() {
    //freopen("in", "r", stdin);
    cnt[0] = 0;
    for (int i = 1; i < (1 << 10); i++) {
        cnt[i] = cnt[i >> 1] + (i & 1);
//        if (i < 20) cout << i << ":  " << cnt[i] << endl;
    }
    while (cin >> n >> m >> k >> w) {
        memset(ans, 0, sizeof(ans));
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%s", s);
                for (int x = 0; x < m; x++) {
                    if (s[x] == '.') ans[i][j][0] |= (1 << x);
                    else if (s[x] >= 'a' && s[x] <= 'z') ans[i][j][1 + (s[x] - 'a')] |= (1 << x);
                    else if (s[x] >= 'A' && s[x] <= 'Z') ans[i][j][27 + (s[x] - 'A')] |= (1 << x);
                }
            }
        }
        for (int t = 0; t < 53; t++) {
            for (int i = 1; i <= k; i++) {
                for (int j = i + 1; j <= k; j++) {
                    for (int x = 0; x < n; x++) {
                        int nn = (ans[i][x][t] & ans[j][x][t]);
//                        cout << nn << ":  " << cnt[nn] << endl;
                        d[i][j] += cnt[nn];
                        d[j][i] += cnt[nn];
                    }
                }
            }
        }
        for (int i = 1; i <= k; i++) {
            d[i][i] = inf;
            for (int j = 1; j <= k; j++) {
                if (i == j) continue;
                d[i][j] = (n * m - d[i][j]) * w;
            }
            d[0][i] =  n * m;
            d[i][0] = n * m;
            for (int j = 0; j <= k; j++) maz[i][j] = d[i][j];
        }
        for (int i = 1; i <= k; i++) maz[0][i] = n * m;
        maz[0][0] = inf;
//        for (int i = 0; i <= k; i++) {
//            for (int j = 0; j <= k; j++) cout << maz[i][j] << " ";
//            cout << endl;
//        }
        printf("%d\n", Prim(k));
        graph(k);
        dfs(0, -1, 0);
    }
    return 0;
}

















