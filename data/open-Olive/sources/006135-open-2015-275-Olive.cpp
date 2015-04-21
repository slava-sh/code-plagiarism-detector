#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define forn(i,a,b) for(int i = a; i < (int)b; i++)
#define srep(i, a) for(__typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef long double ld;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int maxn = 5005;
const int INF = 1e9;

int a[maxn];
int dp[maxn][maxn];

inline int calcx(int l, int r, int v)
{
    if (l == 0) return dp[v][r];
    return dp[v][r] - dp[v][l-1];
}

inline pii calcxy(int l, int r, int v)
{
    int x = calcx(l, r, v);
    return mp(x, r-l+1-x);
}

int main()
{
    int n;
    cin >> n;
    bool ok = 1;
    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
        if (i != 0 && a[i] < a[i-1]) ok = 0;
    }
    rep(i, n)
    {
        dp[i][0] = a[0] > i;
        forn (j, 1, n)
        {
            dp[i][j] = dp[i][j-1] + (a[j] > i);
        }
    }
    if (ok)
    {
        cout << "-1 -1";
        return 0;
    }
    int ri, rj, rd = INF;
    rep(i, n)
    {
        forn(j, i+1, n)
        {
            pii p1 = calcxy(i, j-1, a[j]);
            pii p2 = calcxy(i+1, j-1, a[i]);
            int td = -p1.fi+p1.se+p2.fi-p2.se;
            if (td < rd)
            {
                rd = td;
                ri = i;
                rj = j;
            }
        }
    }
    cout << ri+1 << " " << rj+1;
    return 0;
}
