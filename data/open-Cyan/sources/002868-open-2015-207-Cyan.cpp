#include <bits/stdc++.h>
#include <vector>
#define N 1000

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

//bool operator<(partit a, partit b)
//{
//    if (a.p[0].y != b.p[0].y)
//        return a.p[0].y < b.p[0].y;
//    for (int i = 0; i < a.l; ++i)
//        if ((a[i + 1].y - a[i].y) * (b[i + 1].x - b[i].x) != (a[i + 1].x - a[i].x) * (b[i + 1].y - b[i].y))
//            return (a[i + 1].y - a[i].y) * (b[i + 1].x - b[i].x) < (a[i + 1].x - a[i].x) * (b[i + 1].y - b[i].y)
//}

partit p[N];

int b[N][N];

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
//    random_shuffle(p, p + n);
//    sort(p, p + n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) if (j != i)
        {
//            t j = i + 1;
            for (int k = 0; k <= p[i].l; ++k)
            {
                int l = 0, r = p[j].l, m = l;
                while (r - l > 1)
                {
                    m = r + l >> 1;
                    if (p[j][m + 1].x < p[i][k].x)
                    {
                        l = m + 1;
                        continue;
                    }
                    if (p[j][m].x > p[i][k].x)
                    {
                        r = m;
                        continue;
                    }
                    l = m;
                    break;
                }
                m = l;
                for (l = max(m - 2, 0); l < m + 3 && l < p[j].l; ++l)
                {
                    point a = p[j][l], b = p[j][l + 1];
                    t x = p[i][k].x;
                    t y = p[i][k].y;
                    if ((b.y - a.y) * (x - a.x) < (y - a.y) * (b.x - a.x))
                        ::b[j][i] = 1;
                    if ((b.y - a.y) * (x - a.x) > (y - a.y) * (b.x - a.x))
                        ::b[i][j] = 1;
                }
            }
            if (b[i][j] && b[j][i])
                (cout << "No\n" << p[i].n + 1 << ' ' << p[j].n + 1), exit(0);
        }
//    for (volatile int i = 0; i < 450000000; ++i);
    cout << "Yes";
    return 0;
}