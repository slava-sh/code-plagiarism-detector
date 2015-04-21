#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

const ld eps = 0.0000001;

struct pt
{
    int x, y;
};

struct lom
{
    int l;
    vector <pt> p;
    int u;
};

struct line
{
    ld k, b;
};

line build_line(pt a, pt b)
{
    ld k = (b.y - a.y) * 1.0 / (b.x - a.x);
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

vector <lom> v;

ld solve(int i, ld x)
{
    line l = build_line(v[i].p[v[i].u], v[i].p[v[i].u + 1]);
    return l.k * x + l.b;
}

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int LEFT, RIGHT;
    cin >> LEFT >> RIGHT;
    int n;
    cin >> n;

    set <int> s;

    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        v[i].l = len + 1;
        v[i].p.resize(len + 1);
        v[i].u = 0;
        for (int j = 0; j < len + 1; j++)
        {
            cin >> v[i].p[j].x >> v[i].p[j].y;
            s.insert(v[i].p[j].x);
        }
    }

    vector <vector <int> > matr(n, vector <int> (n, 0));

    for (set <int> :: iterator it = s.begin(); it != s.end(); it++)
    {
        int x = *it;
        vector <ld> x_pos(n);
        for (int i = 0; i < n; i++)
            if (v[i].p[v[i].u].x < x) ++v[i].u;
        for (int i = 0; i < n; i++)
            x_pos[i] = solve(i, x);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
        {
            if (le(x_pos[i], x_pos[j]))
            {
                if (matr[i][j] == 1) {cout << "No\n" << i + 1 << " " << j + 1 << "\n"; return 0;}
                else matr[i][j] = -1;
            }
            else if (ge(x_pos[i], x_pos[j]))
            {
                if (matr[i][j] == -1) {cout << "No\n" << i + 1 << " " << j + 1 << "\n"; return 0;}
                else matr[i][j] = 1;
            }
        }

    }

    cout << "Yes\n";

}


