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

const int N = 50010;
vector <pair<int, int>> v[N];
vector <int> vv[N];
const int inf = 1000000001;
int *dj[N];
queue<pair<int, int>> q;

int ind(int a, int b) {
    return lower_bound(vv[a].begin(), vv[a].end(), b) - vv[a].begin();
}

void print(int n) {
    cout << (n == inf ? -1: n) << "\n";
}

int main() {
    must;
    inp("input.txt");
    int n, m, d, i, j, qq;
    cin >> n >> m >> d;
//    assert(n <= 1000 && m <= 1000);
    for(i = 1; i <= m; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        v[l].pb({r, t});
        vv[l].pb(t);
        if(l != r) {
            v[r].pb({l, t});
            vv[r].pb(t);
        }
    }
    for(i = 1; i <= n; i++) {
        sort(vv[i].begin(), vv[i].end());
        vv[i].pb(inf);
        vv[i].resize(unique(vv[i].begin(), vv[i].end()) - vv[i].begin());
        dj[i] = new int[sz(vv[i]) + 10];
    }

    for(cin >> qq; qq; qq--) {
        int fi, sc;
        cin >> fi >> sc;
        for(i = 1; i <= n; i++)
            for(j = 0; j < vv[i].size(); j++)
                dj[i][j] = inf;
        dj[fi][ind(fi, inf)] = 0;
        q.push({fi, inf});
        while(!q.empty()) {
            auto x = q.front();
//        cout << x.fi << ' ' << x.se << "\n";
            q.pop();
            for(auto y: v[x.fi]) {
//                cout << "\t" << y.fi << ' ' << y.se << "\n";
//                cout << "\t\t" << ind(x.fi, x.se) << "\n";
                if((x.se == inf || abs(x.se - y.se) <= d) && dj[x.fi][ind(x.fi, x.se)] + 1 < dj[y.fi][ind(y.fi, y.se)]) {
                    dj[y.fi][ind(y.fi, y.se)] = dj[x.fi][ind(x.fi, x.se)] + 1;
                    q.push({y.fi, y.se});
                }
            }
        }
//        for(i = 1; i <= n; i++)
//            for(j = 0; j <= vv[i].size(); j++)
//                cout << dj[i][j] << " \n"[j == vv[i].size()];
        print(*min_element(dj[sc], dj[sc] + vv[sc].size()));
//        cout << "\n\n";

    }
}

