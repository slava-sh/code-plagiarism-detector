#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define forn(i,a,b) for(int i = a; i < (int)b; i++)
#define srep(i, a) for(__typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int maxn = 1e5+5;

struct st
{
    int l, r, d;
    st(){}
    st(int l, int r, int d):l(l), r(r), d(d){}
};

st d[maxn*4];
int a[maxn];

inline st unite(st a, st b)
{
    return st(a.l, b.r, a.d + b.d - (a.r == b.l));
}

void build(int v, int l, int r)
{
    if (l+1 == r)
    {
        d[v] = st(a[l], a[l], 1);
        return;
    }
    int m = (l+r)/2;
    build(v*2, l, m);
    build(v*2+1, m, r);
    d[v] = unite(d[v*2], d[v*2+1]);
}

void change(int v, int l, int r, int tl, int tr, int x)
{
    if (l >= r || tl >= tr) return;
    if (l >= tr || tl >= r) return;
    if (l == tl && r == tr)
    {
        d[v] = st(x, x, 1);
        return;
    }
    int m = (l+r)/2;
    change(v*2, l, m, tl, min(tr, m), x);
    change(v*2+1, m, r, max(tl, m), tr, x);
    d[v] = unite(d[v*2], d[v*2+1]);
}

int main()
{
    int n;
    cin >> n;
    rep(i, n)
        cin >> a[i];
    build(1, 0, n);
    int m;
    cin >> m;
    rep(i, m)
    {
        int l, x;
        cin >> l >> x;
        change(1, 0, n, l-1, l, x);
        cout << d[1].d << endl;
    }
    return 0;
}
