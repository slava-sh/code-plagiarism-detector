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
int dj[N][N];
queue<pair<int, int>> q;
int a[N], len;

int ind(int b) {
    return lower_bound(a + 1, a + 1 + len, b) - a;
}

void print(int n) {
    cout << (n == inf ? -1: n) << "\n";
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
            for(j = 1; j <= len; j++)
                dj[i][j] = inf;
        dj[fi][ind(inf)] = 0;
        q.push({fi, inf});
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            for(auto y: v[x.fi]) {
                if((x.se == inf || abs(x.se - y.se) <= d) && dj[x.fi][ind(x.se)] + 1 < dj[y.fi][ind(y.se)]) {
                    dj[y.fi][ind(y.se)] = dj[x.fi][ind(x.se)] + 1;
                    q.push({y.fi, y.se});
                }
            }
        }
        print(*min_element(dj[sc] + 1, dj[sc] + 1 + len));
    }
}
