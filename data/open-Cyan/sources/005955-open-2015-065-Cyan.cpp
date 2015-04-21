#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

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

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int LEFT, RIGHT;
    cin >> LEFT >> RIGHT;
    int n;
    cin >> n;

    vector <lom> v(n);
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
        int ok = 0;
        int u1 = 1, u2 = 1;
        if (v[i].p[0].y > v[j].p[0].y) ok = 1;
        else if (v[i].p[0].y < v[j].p[0].y) ok = -1;
        if (v[i].p.back().y > v[j].p.back().y)
        {
            if (ok == -1) {cout << "No\n" << i + 1 << " " << j + 1 << "\n"; return 0;}
            else ok = 1;
        }
        else if (v[i].p.back().y < v[j].p.back().y)
        {
            if (ok == 1) {cout << "No\n" << i + 1 << " " << j + 1 << "\n"; return 0;}
            else ok = -1;
        }
        while (u1 < v[i].l - 1 && u2 < v[j].l - 1)
        {
            if (v[i].p[u1].x < v[j].p[u2].x)
            {
                line L = build_line(v[j].p[u2 - 1], v[j].p[u2]);
                ld y = L.k * v[i].p[u1].x + L.b;
                if (v[i].p[u1].y > y)
                {
                    if (ok == -1) {cout << "No\n" << i + 1 << " " << j + 1 << "\n"; return 0;}
                    else ok = 1;
                }
                else if (v[i].p[u1].y < y)
                {
                    if (ok == 1) {cout << "No\n" << i + 1 << " " << j + 1 << "\n"; return 0;}
                    else ok = -1;
                }
                ++u1;
            }
            else if (v[i].p[u1].x > v[j].p[u2].x)
            {
                line L = build_line(v[i].p[u1 - 1], v[i].p[u1]);
                ld y = L.k * v[j].p[u2].x + L.b;
                if (y > v[j].p[u2].y)
                {
                    if (ok == -1) {cout << "No\n" << i + 1 << " " << j + 1 << "\n"; return 0;}
                    else ok = 1;
                }
                else if (y < v[j].p[u2].y)
                {
                    if (ok == 1) {cout << "No\n" << i + 1 << " " << j + 1 << "\n"; return 0;}
                    else ok = -1;
                }
                ++u2;
            }
            else if (v[i].p[u1].x == v[i].p[u2].x)
            {
                ++u1;
                ++u2;
            }
        }
    }

    cout << "Yes\n";

}


