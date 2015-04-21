#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 101111, inf = 1011111111;

struct point {
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
    }
    void write() {
        cout << "(" << x << " " << y << ") ";
    }
    point() {
    }
    point(int x, int y) : x(x), y(y) {
    }
    point operator - (const point &p) const {
        return point(x - p.x, y - p.y);
    }
};

struct line {
    long long A, B, C;
    line() {
    }
    line(point a, point b) {
        A = a.y - b.y;
        B = b.x - a.x;
        C = -A * a.x - B * a.y;
    }
};

int A, B, n;
vector<point> v[max_n];

double dist(point a, double x, double y) {
    return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
}

double dist(point a, point b) {
    return dist(a, b.x, b.y);
}

inline bool is_in(point a, point b, double x, double y) {
    return fabs(dist(a, b) - dist(a, x, y) - dist(b, x, y)) <= 0.000001;
}

inline bool not_equal(point a, double x, double y) {
    return fabs(a.x - x) > 0.000001 || fabs(a.y - y) > 0.000001;
}

inline double get_y(line l, double x) {
    return (-l.C - l.A * x) / l.B;
}

inline bool intersect(point p1, point p2, point p3, point p4) {
    line l1 = line(p1, p2);
    line l2 = line(p3, p4);
    double y11 = get_y(l1, p1.x);
    double y12 = get_y(l1, p2.x);
    double y21 = get_y(l2, p1.x);
    double y22 = get_y(l2, p2.x);
    return y11 < y21 || y12 < y22;
}

inline bool bad(int a, int b) {
    int y1 = 1, y2 = 1;
    while (y1 < v[a].size() && y2 < v[b].size()) {
        //cout << y1 << " !! " << y2 << endl;
        if (intersect(v[a][y1 - 1], v[a][y1], v[b][y2 - 1], v[b][y2])) {
            return true;
        }
        if (y1 + 1 == v[a].size()) {
            ++y2;
        } else if (y2 + 1 == v[b].size()) {
            ++y1;
        } else {
            if (v[a][y1].x > v[b][y2].x) {
                ++y2;
            } else if (v[a][y1].x < v[b][y2].x) {
                ++y1;
            } else {
                ++y1;
                ++y2;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &A, &B, &n);
    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        ++m;
        while (m--) {
            point p;
            p.read();
            v[i].push_back(p);
        }
        //cout << "              " << v[i].size() << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (bad(i, j) && bad(j, i)) {
                printf("No\n%d %d\n", i + 1, j + 1);
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
