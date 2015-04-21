#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct point
{
    int x, y, i, j;
};

inline bool operator < (point a, point b)
{
    return (a.x < b.x);
}

struct booy
{
    vector<point> v;
    int l, nm;
};

const int nmax = 220000;

booy chain[nmax];
vector<point> all_points;
int n, a, b;


void read()
{
    fin >> a >> b;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> chain[i].l;
        for (int j = 0; j <= chain[i].l; j++)
        {
            point p;
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
    return (a.v[0].y < b.v[0].y);
}


int f(point p1, point p2, point p3)
{
    int x1 = p2.x - p1.x;
    int y1 = p2.y - p1.y;
    int x2 = p3.x - p1.x;
    int y2 = p3.y - p1.y;
    return x1 * y2 - y1 * x2;
}


void write(point p)
{
    fout << p.x << ' ' << p.y << endl;
}


bool cross(point p1, point p2, point p3, point p4)
{
    //write(p1);
    //write(p2);
    //write(p3);
    //write(p4);
    //fout << endl;
    return ((f(p1, p2, p3) * f(p1, p2, p4) < 0) && (f(p3, p4, p1) * f(p3, p4, p2) < 0));
}


void check(booy &b1, booy &b2)
{
    all_points.clear();
    for (int i = 1; i <= b1.l; i++)
        all_points.push_back(b1.v[i]);
    for (int i = 1; i < b2.l; i++)
        all_points.push_back(b2.v[i]);
    sort(all_points.begin(), all_points.end());
    point p1 = b1.v[0];
    point p2 = b2.v[0];
    for (int i = 0; i < all_points.size(); i++)
    {
        point cur = all_points[i];
        if (cur.i == b1.nm)
        {
            if (cross(p2, b2.v[p2.j + 1], p1, cur))
            {
                fout << "No" << endl;
                fout << b1.nm << ' ' << b2.nm << endl;
                exit(0);
            }
            p1 = cur;
        }
        else
        {
            if (cross(p1, b1.v[p1.j + 1], p2, cur))
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
    for (int i = 0; i < n - 1; i++)
        check(chain[i], chain[i + 1]);
    fout << "Yes" << endl;
}


int main()
{
    read();
    solve();
    return 0;
}
