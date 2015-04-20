#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 300000;

vector <int> es[N];
int n, v1, v2;
int d[N];
int d2[N];
int pr[N];
int b[N];
int nxt[N];
int dp;

void dfs(int v, int p) {
    int w;
    int md = 0;
    for (int i = 0; i < es[v].size(); i++) {
        w = es[v][i];
        if (w != p) {
            dfs(w, v);
            pr[w] = v;
            md = max(d[w], md);
        }
    }
    d[v] = md + 1;
    return;
}

void dfs2(int v, int p) {
    int w;
    int md = 0;
    for (int i = 0; i < es[v].size(); i++) {
        w = es[v][i];
        if (w != p) {
            dfs2(w, v);
            if (w != nxt[v])
                md = max(d[w], md);
        }
    }
    d2[v] = md + 1;
    return;
}

int main()
{
    freopen("dwarfs.in", "r", stdin);
    freopen("dwarfs.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2;
        v1--; v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    cin >> v1 >> v2;
    v1--; v2--;
    dfs(v1, -1);
    //for (int i = 0; i < n; i++)
      //  cerr << d[i] << " ";

    int w;
    w = v2;
    while (w != v1) {
        nxt[pr[w]] = w;
        w = pr[w];
        dp++;
    }
    //cerr << "ok\n";

    dfs2(v1, -1);
   // cerr << "\n";
   // for (int i = 0; i < n; i++) cerr << d2[i] << " ";


    int ans = 1;
    for (int i = 0; i < es[v1].size(); i++) {
        w = es[v1][i];
        if (w != nxt[v1])
            ans = max(ans, d[w] + 1);
    }
    b[0] = ans;
    w = v1;
    for (int i = 1; i <= dp; i++) {
        w = nxt[w];
        b[i] = max(b[i - 1], i + d2[w]);
    }
   // cerr << "\n";
    //for (int i = 0; i < dp; i++) cerr << b[i] << " ";
   // cerr << "\n";

    ans = d[v2];
    w = v2;
    int res = 0;
    for (int i = dp - 1; i >= 0; i--) {
       // cerr << ans << " " << b[i] << "\n";
        res = max(res, min(ans, b[i]));
        w = pr[w];
        ans = max(ans, d[w] + dp - i - 1);
    }

    cout << res;

    return 0;
}
