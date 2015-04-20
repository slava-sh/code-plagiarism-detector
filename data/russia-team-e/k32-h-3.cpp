 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>
 # include <vector>
 # include <set>
 # include <vector>
 # define pb push_back
 # define mp make_pair

 using namespace std;

 const int N = (int) 1e4;
 const int INF = (int) 1e9;

 set < pair <int, int> > st;
 set < pair <int, int> > :: iterator it;
 int n, m, Min = INF;
 int a[N], d[N], p[N];
 vector < pair <int, int> > g[N];


 void djikstra (int v) {
    st.insert (mp (0, v));
    for (int tt = 1; tt <= n; ++tt) {
        st.insert (mp (INF, tt));
        d[tt] = INF;
    }
    while (st.size ()) {
        it = st.begin ();
        int cur = it -> second;
        st.erase (st.begin ());
        for (int it = 0; it < (int) g[cur].size (); ++it) {
            int len = g[cur][it].first;
            int to = g[cur][it].second;
            if (d[cur] + len < d[to]) {
                st.erase (st.find (mp (d[to], to)));
                d[to] = d[cur] + len;
                p[to] = cur;
                st.insert (mp (d[to], to));
            }
        }
    }

 }

 int main () {
    freopen ("secure.in", "r", stdin);
    freopen ("secure.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        g[A].pb (mp (C, B));
        g[B].pb (mp (C, A));
    }

    for (int t = 1; t <= n; ++t)
        if (a[t] == 1) {
            g[n + 1].pb (mp (0, t));
            g[0].pb (mp (n + 1, t));
        }
    djikstra (n + 1);

    int last = 0;

    for (int i = 1; i <= n; ++i) {
        if (a[i] == 2 && d[i] < Min) {
                Min = d[i];
                last = i;
        }
    }
    if (Min == INF) {
        cout << "-1";
        return 0;
    }
    int ans1 = 0, ans2 = last;
    while (p[last] != n + 1)
     last = p[last];
    ans1 = last;
    cout << ans1 << ' ' << ans2 << ' ' << Min << endl;
 }

