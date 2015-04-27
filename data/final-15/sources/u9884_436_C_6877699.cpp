#include <iostream>
#include <iomanip>

#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <complex>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#ifdef SG
    #define debug(x) cerr << #x << ": " << (x) << endl
#else
    #define debug(x)
#endif

template <typename T>
ostream & operator << (ostream & out, vector<T> const & a) {
    out << "[";
    for (int i = 0; i < sz(a); ++i) {
        if (i != 0) {
            out << ", ";
        }
        out << a[i];
    }
    out << "]";
    return out;
}

template <typename T1, typename T2>
ostream & operator << (ostream & out, pair<T1, T2> const & p) {
    out << "(" << p.fs << ", " << p.sc << ")";
    return out;
}

const int N = 1e3;
const int L = 10;

struct Data {
    int n, m, k, w;
    vector<string> lev[N];
    bool read () {
        if (!(cin >> n >> m >> k >> w)) {
            return false;
        }

        for (int i = 0; i < k; ++i) {
            char buf[L + 1];
            for (int j = 0; j < n; ++j) {
                scanf("%s", buf);
                lev[i].pb(buf);                
            }
        }
        return true;
    }
    
    ll ans;
    vector<pair<int, int> > ansSeq;
    void write () {
        cout << ans << "\n";
        for (int i = 0; i < sz(ansSeq); ++i) {
            cout << ansSeq[i].fs << " " << ansSeq[i].sc << "\n";
        }
    }

    virtual void solve () {}

    virtual void clear () {
        *this = Data();
    }    
};

struct Solution: Data {
    ll g[N + 1][N + 1];
    ll d[N + 1];
    int from[N + 1];
    bool was[N + 1];

    static const ll inf = 1e12L;

    void addEdge (int u, int v, ll w) {
        g[u][v] = g[v][u] = w;
    }

    int diff (vector<string> const & a, vector<string> const & b) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] != b[i][j]) {
                    ++res;
                }
            }
        }

        return res;
    }

    void solve () {
        for (int i = 1; i <= k; ++i) {
            g[i][i] = 0;
        }

        for (int i = 0; i < k; ++i) {
            addEdge(0, i + 1, n * m);
        }

        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                addEdge(i+ 1, j + 1, diff(lev[i], lev[j]) * w);
            }
        }    

        fill(d, d + k + 1, inf);
        fill(was, was + k + 1, false);
        d[0] = 0;
        from[0] = -1;

        ans = 0;
        for (int i = 0; i <= k; ++i) {
            int u = -1;
            ll mn = inf;
            for (int j = 0; j <= k; ++j) {
                if (!was[j] && d[j] < mn) {
                    mn = d[j];
                    u = j;
                }
            }
            if (u == -1) {
                break;
            }
            ans += d[u];
            if (from[u] != -1) {
                ansSeq.pb(mp(u, from[u]));
            }

            was[u] = true;
            for (int v = 0; v <= k; ++v) {
                if (d[v] > g[u][v]) {
                    d[v] = g[u][v];
                    from[v] = u;
                }
            }
        }
    }

    Solution () {
    }

    Solution (Data d): Data(d) {
    }

    void clear () {
        *this = Solution();
    }
};

Solution sol;

int main () {
#ifdef SG
//    freopen("", "r", stdin);
//    freopen("", "w", stdout);
    while (sol.read()) {
        sol.solve();
        sol.write();
        sol.clear();
    }
#else
    sol.read();
    sol.solve();
    sol.write();
#endif
    return 0;
}
