#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pb push_back
#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int inf = 500000010;
const int N = 5010;
int a[N], d[N], pr[N];
vector<pair<int, int> > v[N];
set<pair<int, int> > s;

int main() {
    in("secure.in");
    out("secure.out");
    int n, m, i, l, r, w;
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = inf;
        if(a[i] == 1) {
            s.insert(mp(0, i));
            d[i] = 0;
            pr[i] = i;
        }
    }
    for(i = 1; i <= m; i++) {
        cin >> l >> r >> w;
        v[l].pb(mp(r, w));
        v[r].pb(mp(l, w));
    }

    while(!s.empty()) {
        l = s.begin()->se;
        s.erase(s.begin());
        for(i = 0; i < v[l].size(); i++) {
            int to = v[l][i].fi;
            int len = v[l][i].se;
            if(d[l] + len < d[to]) {
                s.erase(mp(d[to], to));
                d[to] = d[l] + len;
                pr[to] = pr[l];
                s.insert(mp(d[to], to));
            }
        }
    }
    int mi = inf;
    for(i = 1; i <= n; i++)
        if(a[i] == 2 && d[i] < mi)
            mi = d[i];
    if(mi == inf)
        cout << -1;
    else {
        for(i = 1; i <= n; i++) {
            if(d[i] == mi) {
                cout << pr[i] << ' ' << i << ' ' << mi;
                return 0;
            }
        }
    }
}
