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

const int maxn = 3e5+5;
ld EPS = 1e-10;

struct point
{
    ld x, y;
    int lid, sid;
    point() {}
    point(ld x, ld y, int lid, int sid):x(x), y(y), lid(lid), sid(sid) {}
};

struct seg
{
    point a, b;
    seg() {}
    seg(point a, point b):a(a), b(b) {}
};

vector<point> va[maxn];

bool cmp(point a, point b)
{
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool operator < (point a, point b)
{
    if (a.y != b.y) return a.y < b.y;
    return a.lid < b.lid;
}

set<point> s;
set<pii> rs;

ld geth(point p, ld x)
{
    point p1, p2;
    if (abs(p.x - x) < EPS) return p.y;
    if (p.x < x)
    {
        p1 = p;
        p2 = va[p.lid][p.sid+1];
    }
    else
    {
        p2 = p;
        p1 = va[p.lid][p.sid-1];
    }
    ld k = (p1.y-p2.y)/(p1.x-p2.x);
    ld b = p1.y - k*p1.x;
    return k*x+b;
}

void check(point a, point t)
{
    if (abs(geth(a, t.x) - t.y) > EPS)
    {
        if (geth(a, t.x) < t.y)
        {
            rs.insert(mp(a.lid, t.lid));
            //cout << it->lid << " " << t.lid << endl;
        }
        else if (geth(a, t.x) > t.y)
        {
            rs.insert(mp(t.lid, a.lid));
        }
    }
}

void check(set<point>::iterator it)
{
    point t = *it;
    bool ok = 0;
    if (it != s.begin())
    {
        ok = 1;
        it--;
        check(*it, t);
        it++;
    }
    it++;
    if (it != s.end())
    {
        check(*it, t);
        if (ok)
        {
            t = *it;
            it--;
            it--;
            check(*it, t);
        }
    }
}

struct ev
{
    int t;
    point p;
    ev(){}
    ev(int t, point p):t(t), p(p){}
};

bool operator < (ev a, ev b)
{
    if (a.p.x != b.p.x) return a.p.x < b.p.x;
    return a.t < b.t;
}

vector<ev> e;

int main()
{
    ios_base::sync_with_stdio(0);
    int A, B;
    cin >> A >> B;
    int n;
    cin >> n;
    rep(i, n)
    {
        int tn;
        cin >> tn;
        rep(j, tn+1)
        {
            point tp;
            tp.lid = i;
            tp.sid = j;
            cin >> tp.x >> tp.y;
            va[i].push_back(tp);
            if (j != 0) e.push_back(ev(0, tp));
            e.push_back(ev(1, tp));
        }
    }
    sort(e.begin(), e.end());
    rep(i, e.size())
    {
        if (e[i].t == 0)
        {
            point p = e[i].p;
            set<point>::iterator it = s.find(va[p.lid][p.sid-1]);
            check(it);
            s.erase(it);
        }
        else
        {
            s.insert(e[i].p);
            check(s.find(e[i].p));
        }
    }
    srep(it, rs)
    {
        if (rs.find(mp(it->se, it->fi)) != rs.end())
        {
            cout << "No" << endl;
            cout << it->fi+1 << " " << it->se+1;
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
