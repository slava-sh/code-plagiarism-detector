#include <bits/stdc++.h>
#include <vector>
#define N 100000

using namespace std;

typedef int64_t t;

struct point{
    t x, y;
};

point operator-(point a, point b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

point operator+(point a, point b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

point operator*(point a, t b)
{
    a.x *= b;
    a.y *= b;
    return a;
}

//t crossp(point a, point b)
//{
//    return a.x * b.y - a.y * b.x;
//}
//
//t dotp(point a, point b)
//{
//    return a.x * b.x + a.y * b.y;
//}
//
//struct segment{
//    point a, b;
//    #define ax a.x
//    #define ay a.y
//    #define bx b.x
//    #define by b.y
//};
//
//bool interseg(segment a, segment b)
//{
//
//}

struct partit{
    vector<point> p;
    point &operator[](int x)
    {
        return p[x];
    }
    t l, n;
};

bool operator<(partit a, partit b){return a.p[0].y < b.p[0].y;}

partit p[N];

int main()
{
    t n;
    t A, B;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    n = 0;
    cin >> A >> B >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].l;
        p[i].n = i;
        p[i].p.resize(p[i].l + 1);
        for (int j = 0; j <= p[i].l; ++j)
            cin >> p[i][j].x >> p[i][j].y;
    }
    sort(p, p + n);
    for (int i = 0; i < n; ++i)
//        for (int j = 0; j < n; ++j) if (j != i)
        {
            t j = i + 1;
            for (int k = 0; k <= p[i].l; ++k)
                for (int m = 0; m < p[j].l; ++m)
                {
                    if (p[j][m + 1].x < p[i][k].x)
                        continue;
                    if (p[j][m].x >= p[i][k].x)
                        break;
                    point a = p[j][m], b = p[j][m + 1];
                    t x = p[i][k].x;
                    t y = p[i][k].y;
                    if ((b.y - a.y) * (x - a.x) < (y - a.y) * (b.x - a.x))
                        (cout << "No\n" << p[i].n + 1 << ' ' << p[j].n + 1), exit(0);
                }
        }
    for (int i = 0; i < 500000000; ++i);
    cout << "Yes";
    return 0;
}
