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
ld EPS = 1e-5;

struct point
{
    ld x, y;
    int lid, sid, aid;
    point() {}
    point(ld x, ld y, int lid, int sid):x(x), y(y), lid(lid), sid(sid) {}
};

struct seg
{
    point a, b;
    seg() {}
    seg(point a, point b):a(a), b(b) {}
};

vector<point> a;
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

void check(set<point>::iterator it)
{
    point t = *it;
    if (it != s.begin())
    {
        it--;
        if (geth(*it, t.x) < t.y)
        {
            rs.insert(mp(it->lid, t.lid));
            //cout << it->lid << " " << t.lid << endl;
        }
        else if (geth(*it, t.x) > t.y)
        {
            rs.insert(mp(t.lid, it->lid));
        }
        it++;
    }
    it++;
    if (it != s.end())
    {
        if (geth(*it, t.x) > t.y)
        {
            rs.insert(mp(t.lid, it->lid));
            //cout << t.lid << " " << it->lid << endl;
        }
        else if (geth(*it, t.x) < t.y)
        {
            rs.insert(mp(it->lid, t.lid));
        }
    }
}

int main()
{
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
            a.push_back(tp);
            va[i].push_back(tp);
        }
    }
    sort(a.begin(), a.end(), cmp);
    rep(i, a.size()) a[i].aid = i;
    rep(i, a.size())
    {
        if (a[i].sid != 0)
        {
            set<point>::iterator it = s.find(va[a[i].lid][a[i].sid-1]);
            check(it);
            s.erase(it);
        }
        s.insert(a[i]);
        check(s.find(a[i]));
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
