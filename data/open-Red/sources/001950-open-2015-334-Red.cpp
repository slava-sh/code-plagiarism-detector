#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

const int N = 2000;
vector <pair<int, int>> v[N];
const int inf = 1000000001;
queue<pair<int, int>> q;
int a[N], len;
map<int, int> dj[N];

void print(int n) {
    cout << (n == inf ? -1: n) << "\n";
}

bool check(pair<int, int> x, pair<int, int> y) {
    if(dj[y.fi].find(y.se) == dj[y.fi].end())
        return 1;
    return dj[x.fi][x.se] + 1 < dj[y.fi][y.se];
}

int main() {
    inp("input.txt");
    int n, m, d, i, j, qq;
    cin >> n >> m >> d;
//    assert(n <= 1000 && m <= 1000);
    for(i = 1; i <= m; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        v[l].pb({r, t});
        if(l != r)
            v[r].pb({l, t});
        a[++len] = t;
    }
    sort(a + 1, a + 1 + len);
    len = unique(a + 1, a + 1 + len) - a;
    a[len] = inf;
    for(cin >> qq; qq; qq--) {
        int fi, sc;
        cin >> fi >> sc;
        for(i = 1; i <= n; i++)
            dj[i].clear();
        dj[fi][inf] = 0;
        q.push({fi, inf});
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            for(auto y: v[x.fi]) {
                if((x.se == inf || abs(x.se - y.se) <= d) && check(x, y)) {
                    dj[y.fi][y.se] = dj[x.fi][x.se] + 1;
                    q.push({y.fi, y.se});
                }
            }
        }
        int ans = inf;
        for(auto x: dj[sc]) {
            ans = min(ans, x.se);
        }
        print(ans);
    }
}
