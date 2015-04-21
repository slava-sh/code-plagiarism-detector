#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct point
{
    int x, y;
    point() {}
    point(int _x, int _y) : x(_x), y(_y) {}
};

struct vect
{
    int x, y;
    vect(const point& a, const point& b)
    {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

long long cp(vect a, vect b)
{
    long long ax = a.x, bx = b.x, ay = a.y, by = b.y;
    return ax * by - bx * ay;
}

long long dp(vect a, vect b)
{
    long long ax = a.x, bx = b.x, ay = a.y, by = b.y;
    return ax * bx + ay * by;
}

bool is_point_in_segment(point p, point a, point b)
{
    return cp(vect(p, a), vect(p, b)) == 0 && dp(vect(p, a), vect(p, b)) < 0;
}

int signum(long long a)
{
    if (a < 0)
        return -1;
    else if (a == 0)
        return 0;
    return 1;
}

bool do_segments_intersect(point a, point b, point c, point d)
{
    if (cp(vect(a, b), vect(c, d)) == 0)
        return false;
    return signum(cp(vect(a, c), vect(a, b))) * signum(cp(vect(a, b), vect(a, d))) > 0 && signum(cp(vect(c, a), vect(c, d))) * signum(cp(vect(c, d), vect(c, b))) > 0;
}

bool is_point_down_of(point p, point a, point b)
{
   // cout << cp(vect(a, p), vect(b, p)) << endl;
    return cp(vect(a, p), vect(b, p)) <= 0;
}

vector<vector<point> > massives;

bool is_down_of(const int& a, const int& b)
{
    int i = 0, j = 1;
    while (i < (int)massives[a].size() && j < (int)massives[b].size())
    {
        if (i > 0 && do_segments_intersect(massives[a][i - 1], massives[a][i], massives[b][j - 1], massives[b][j]))
                return false;
        if (massives[a][i].x <= massives[b][j].x)
        {
            if (!is_point_down_of(massives[a][i], massives[b][j - 1], massives[b][j]))
                return false;
            i += 1;
        }
        else
            j += 1;
    }
    return true;
}

int main()
{
//    freopen("~/dbg/input.txt", "r", stdin);
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    massives.resize(n);
    vector<int> to_sort;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        massives[i].resize(l + 1);
        for (int j = 0; j < l + 1; j++)
            cin >> massives[i][j].x >> massives[i][j].y;
        to_sort.push_back(i);
    }
    sort(to_sort.begin(), to_sort.end(), is_down_of);
    for (int i = 0; i < n - 1; i++)
    {
        if (!is_down_of(to_sort[i], to_sort[i + 1]))
        {
            cout << "No" << endl;
            cout << to_sort[i] + 1 << " " << to_sort[i + 1] + 1 << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
