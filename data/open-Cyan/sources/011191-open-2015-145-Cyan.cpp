#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct poll
{
    ll x, y, i, j;
};

inline bool operator < (poll a, poll b)
{
    return (a.x < b.x);
}

struct booy
{
    vector<poll> v;
    ll l, nm;
};

const ld eps = 1e-10;
const ll nmax = 220000;

booy chain[nmax];
vector<poll> all_polls;
ll n, a, b;


void read()
{
    fin >> a >> b;
    fin >> n;
    for (ll i = 0; i < n; i++)
    {
        fin >> chain[i].l;
        for (ll j = 0; j <= chain[i].l; j++)
        {
            poll p;
            fin >> p.x >> p.y;
            p.i = i + 1;
            p.j = j;
            chain[i].v.push_back(p);
        }
        chain[i].nm = i + 1;
    }
}


bool cmp(booy a, booy b)
{
    //fout << "KOPI" << a.nm << ' ' << b.nm << endl;
    ll i = 0;
    while ((i <= min(a.l, b.l)) && (a.v[i].y == b.v[i].y))
        i++;
    if (i > min(a.l, b.l))
        return (a.l < b.l);
    //fout << (a.v[i].y < b.v[i].y) << endl;
    return (a.v[i].y < b.v[i].y);
}


ll f(poll p1, poll p2, poll p3)
{
    ll x1 = p2.x - p1.x;
    ll y1 = p2.y - p1.y;
    ll x2 = p3.x - p1.x;
    ll y2 = p3.y - p1.y;
    return x1 * y2 - y1 * x2;
}


void write(poll p)
{
    fout << p.x << ' ' << p.y << endl;
}


bool razn(ll a, ll b)
{
    return (((a > 0) && (b < 0)) || ((a < 0) && (b > 0)));
}


bool cross(poll p1, poll p2, poll p3, poll p4)
{
    /*write(p1);
    write(p2);
    write(p3);
    write(p4);
    fout << endl;*/
    //fout << f(p1, p2, p3) << ' ' << f(p1, p2, p4) << "  " << f(p3, p4, p1) << ' ' << f(p3, p4, p2) << endl;
    return (razn(f(p1, p2, p3), f(p1, p2, p4)) && razn(f(p3, p4, p1), f(p3, p4, p2)));
}


bool vyshe(poll p1, poll p2, poll p3)
{
    //write(p1);
    //write(p2);
    //write(p3);
    ld x = p1.x;
    ld x1 = p2.x;
    ld x2 = p3.x;
    ld y1 = p2.y;
    ld y2 = p3.y;
    //fout << x1 << ' ' << x2 << endl;
    assert(x2 - x1 > eps);
    ld y = (x * y2 - x * y1 - x1 * y2 + x2 * y1) / (x2 - x1);
    //fout << y << ' ' << p1.y << endl;
    //fout << endl;
    return (p1.y > y + eps);
}


bool nizhe(poll p1, poll p2, poll p3)
{
    //write(p1);
    //write(p2);
    //write(p3);
    ld x = p1.x;
    ld x1 = p2.x;
    ld x2 = p3.x;
    ld y1 = p2.y;
    ld y2 = p3.y;
    //fout << x1 << ' ' << x2 << endl;
    assert(x2 - x1 > eps);
    ld y = (x * y2 - x * y1 - x1 * y2 + x2 * y1) / (x2 - x1);
    //fout << "nizhe " << y << ' ' << p1.y << endl;
    //fout << endl;
    return (p1.y < y - eps);
}


void check(booy &b1, booy &b2)
{
    //fout << b1.nm << ' '<< b2.nm << endl;
    all_polls.clear();
    for (ll i = 1; i <= b1.l; i++)
        all_polls.push_back(b1.v[i]);
    for (ll i = 1; i <= b2.l; i++)
        all_polls.push_back(b2.v[i]);
    sort(all_polls.begin(), all_polls.end());
    //fout << b1.l << ' ' << b2.l << ' ' << all_polls.size() << endl;
    /*for (ll i = 0; i < all_polls.size(); i++)
        fout << all_polls[i].x << ' ' << all_polls[i].y << "  ";
    fout << endl;*/
    poll p1 = b1.v[0];
    poll p2 = b2.v[0];
    for (ll i = 0; i < all_polls.size(); i++)
    {
        poll cur = all_polls[i];
        if (cur.i == b1.nm)
        {
            if ((p2.j < b2.l) && vyshe(cur, p2, b2.v[p2.j + 1]))
            {
                fout << "No" << endl;
                fout << b1.nm << ' ' << b2.nm << endl;
                exit(0);
            }
            p1 = cur;
        }
        else
        {
            if ((p1.j < b1.l) && nizhe(cur, p1, b1.v[p1.j + 1]))
            {
                fout << "No" << endl;
                fout << b1.nm << ' ' << b2.nm << endl;
                exit(0);
            }
            p2 = cur;
        }
    }
}


void solve()
{
    sort(chain, chain + n, cmp);
    //for (ll i = 0; i < n; i++)
        //fout << chain[i].nm << endl;
    for (ll i = 0; i < n - 1; i++)
        check(chain[i], chain[i + 1]);
    fout << "Yes" << endl;
}


int main()
{
    read();
    solve();
    return 0;
}
