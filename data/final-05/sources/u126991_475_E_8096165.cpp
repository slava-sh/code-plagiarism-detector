#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;

#define LL long long
#define mod 1000000007
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define FOR(i,a,b) for (int i = a; i < b; ++i)

#define mxn 2005
#define mxe 4100000

int dfn[mxn], low[mxn], sta[mxn], col[mxn], top, cnt, cc;
int first[mxn], vv[mxe], nxt[mxe], sz[mxn], num[mxn], e;

void add(int u, int v) {
    vv[e] = v, nxt[e] = first[u], first[u] = e++;
}

void dfs(int u, int p) {  
    low[u] = dfn[u] = ++cnt;  
    sta[++top] = u;  
    for (int i = first[u]; i != -1; i = nxt[i]) {  
        int v = vv[i];  
        if (i == (p ^ 1)) continue;
        if (!dfn[v]) {  
            dfs(v, i);  
            if (low[v] < low[u]) low[u] = low[v];  
            if (low[v] > dfn[u]) {  
                ++cc;
                do {  
                    col[sta[top]] = cc;
                    ++sz[cc];
                } while( sta[top--] != v );  
            }
        }
        else if (low[u] > dfn[v]) low[u] = dfn[v];  
    }  
}

int F(int u, int p) {
    num[u] = sz[u];
    int ret = sz[u] * sz[u];
    for (int i = first[u]; i != -1; i = nxt[i]) {
        int v = vv[i];
        if (v == p) continue;
        ret += F(v, u);
        ret += sz[u] * num[v];
        num[u] += num[v];
    }
    return ret;
}

int solve(int u) {
    bitset<2005> msk;
    msk.reset();
    msk[0] = 1;
    int ret = sz[u] * sz[u], tot = 0;
    for (int i = first[u]; i != -1; i = nxt[i]) {
        int v = vv[i];
        ret += F(v, u);
        ret += sz[u] * num[v];
        msk = msk | (msk << num[v]);
        tot += num[v];
    }
    int res = ret;
    REP(i, 1, tot) if (msk[i]) ret = max(ret, res + i * (tot - i));
    //cout << u << " " << res << " " << tot << " " << ret << endl;
    return ret;
}

int main()
{
    int n, m, u, v;
    memset(first, -1, sizeof(first)); e = 0;
    scanf("%d%d", &n, &m);
    REP(i, 1, m) {
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    dfs(1, -1);
    ++cc;
    REP(i, 1, n) if (dfn[i] && col[i] == 0) col[i] = cc, ++sz[cc];
    //REP(i, 1, n) cout << "col " << col[i] << endl;
    memset(first, -1, sizeof(first)); e = 0;
    for (int i = 0; i < 2 * m; i += 2) {
        int u = col[vv[i]], v = col[vv[i^1]];
        if (u != v) add(u, v), add(v, u);
    }
    int ans = 0;
    REP(i, 1, cc) ans = max(ans, solve(i));
    cout << ans << endl;
    return 0;
}