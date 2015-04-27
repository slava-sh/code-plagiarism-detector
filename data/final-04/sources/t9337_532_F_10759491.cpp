#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 400 * 1000 + 13;

char buf[N];
string s;
string t;
int n, m;

inline bool read() {
    if (scanf("%d%d", &n, &m) != 2)
        return false;
    assert(scanf("%s", buf) == 1);
    s = string(buf);
    assert(scanf("%s", buf) == 1);
    t = string(buf);
    return true;
}

const int A = 26;
int id[A];
int to[A];

int S[2 * N];
int pos[2 * N];
int szs;
int z[2 * N];

inline void zf() 
{
    int n = szs;
    int l = 0, r = 0;
    z[0] = 0;

    for (int i = 1; i < n; i++) 
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        else
            z[i] = 0;

        while (i + z[i] < n && S[ z[i] ] == S[ i + z[i] ])
            z[i]++;

        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

vector<pt> res[N];

void calc(int c1, int c2) {
    int last = -1;
    szs = 0;
    int f = -1;
    forn(i, m) {
        if (c2 == int(t[i])) {
            if (last != -1) {
                pos[ szs ] = i;
                S[ szs++ ] = i - last;
            }
            last = i;
            if (f == -1)
                f = i;
        }
    }   
    if (f == -1)
        return;
    if (szs == 0) {
        forn(i, n) {
            if (c1 == int(s[i])) {
                if (i - f >= 0) 
                    res[i - f].pb(mp(c1 - 'a', c2 - 'a'));
            }
        }
        return;
    }
    
    int len = szs;
    S[szs++] = -1;
    
    last = -1;
    forn(i, n) {
        if (c1 == int(s[i])) {
            if (last != -1) {
                pos[ szs ] = i;
                S[ szs++] = i - last;
            }
            last = i;
        }
    }
    zf();
/*
    forn(i, szs) {
        cerr << S[i] << " ";
    }
    cerr << endl;
    forn(i, szs)
        cerr << pos[i] << " ";
    cerr << endl;
    forn(i, szs)
        cerr << z[i] << " ";
    cerr << endl;
//  */
    fore(i, len + 1, szs - 1) {
        if (z[i] == len) {
            int idx = pos[i];           
            if (idx - S[0] - f >= 0)
                res[idx - S[0] - f].pb(mp(c1 - 'a', c2 - 'a')); 
        }
    }
}

int tt[A];
int ans[N];
int szans;

inline void solve() {
    fore(c1, 'a', 'z') {
        fore(c2, 'a', 'z') {
            calc(c1, c2);
        }
    }
    
    memset(id, -1, sizeof id);
    forn(j, m) {
        if (id[ int(t[j] - 'a') ] == -1) {
            id[ int(t[j] - 'a') ] = j;
        }
    }
    szans = 0;
/*
    forn(i, n) {
        cerr << i << endl;
        forn(j, sz(res[i])) {
            cerr << "(" << char('a' + res[i][j].ft) << ", " << char('a' + res[i][j].sc) << ") ";        
        }
        cerr << endl;
    }
//*/
    forn(i, n - m + 1) {
        memset(to, -1, sizeof to);
        memset(tt, -1, sizeof tt);
        bool ok = true;
        
        forn(j, sz(res[i])) {
            int c1 = res[i][j].ft;
            int c2 = res[i][j].sc;
            if (to[c1] == c2 && to[c2] == c1) {
                tt[c2] = 0;
                continue;
            }
            if (to[c1] != -1 || to[c2] != -1) {
                ok = false;
                break;
            }
            tt[c2] = 0;
            to[c1] = c2;
            to[c2] = c1;
        }
        if (!ok)
            continue;
        forn(j, A) {
            if (id[j] == -1)
                continue;

            if (tt[j] == -1) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans[szans++] = i;
        }
    }
    printf("%d\n", szans);
    forn(i, szans) {
        printf("%d ", ans[i] + 1);
    }
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif

    cout << setprecision(25) << fixed;
    cerr << setprecision(10) << fixed;

    srand(int(time(NULL)));

    assert(read());
    solve();

#ifdef SU2_PROJ
    cerr << "TIME: " << clock() << endl;
#endif

    return 0;
}