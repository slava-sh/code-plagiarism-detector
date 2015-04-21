#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

const ld eps = 0.0001;

struct pt
{
    ld x, y;
};

struct lom
{
    int l;
    vector <pt> p;
};

struct line
{
    ld k, b;
};

line build_line(pt a, pt b)
{
    ld k = (b.y - a.y) / (b.x - a.x);
    line ans = {k, a.y - k * a.x};
    return ans;
}

bool le(ld a, ld b)
{
    return b - a >= eps;
}

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool ge(ld a, ld b)
{
    return a - b >= eps;
}

bool leq(ld a, ld b)
{
    return le(a, b) || eq(a, b);
}

bool geq(ld a, ld b)
{
    return ge(a, b) || eq(a, b);
}

int higher, smaller;
vector <lom> v;

ld LEFT, RIGHT;
int u1, u2;

void solve(int i, int j, ld x)
{
    if (eq(RIGHT, x))
    {
        if (ge(v[i].p.back().y, v[j].p.back().y)) ++higher;
        else if (le(v[i].p.back().y, v[j].p.back().y)) ++smaller;
        return;
    }
    for (; ; u1++)
        if (leq(v[i].p[u1].x, x) && geq(v[i].p[u1 + 1].x, x)) break;
    for (; ; u2++)
        if (leq(v[j].p[u2].x, x) && geq(v[j].p[u2 + 1].x, x)) break;
    line l1 = build_line(v[i].p[u1], v[i].p[u1 + 1]);
    line l2 = build_line(v[j].p[u2], v[j].p[u2 + 1]);
    ld y1 = l1.k * x + l1.b;
    ld y2 = l2.k * x + l2.b;
    if (ge(y1, y2)) ++higher;
    else if (le(y1, y2)) ++smaller;
}

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> LEFT >> RIGHT;
    int n;
    cin >> n;

    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        v[i].l = len + 1;
        v[i].p.resize(len + 1);
        for (int j = 0; j < len + 1; j++)
            cin >> v[i].p[j].x >> v[i].p[j].y;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
    {
        higher = smaller = 0;
        u1 = u2 = 0;
        for (int g = 0; g < v[i].l; g++)
            solve(i, j, v[i].p[g].x);
        u1 = u2 = 0;
        for (int g = 0; g < v[j].l; g++)
            solve(i, j, v[j].p[g].x);
        if (higher > 0 && smaller > 0) {cout << "No\n" << i + 1 << " " << j + 1 << "\n"; return 0;}
    }

    cout << "Yes\n";

}


