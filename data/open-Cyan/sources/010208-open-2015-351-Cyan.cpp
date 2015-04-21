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

int A, B, n, p[max_n];
pair<long long, pair<int, vector<point> > > v[max_n], v2[max_n];

bool cmp(const pair<long long, pair<int, vector<point> > > &p1, const pair<long long, pair<int, vector<point> > > &p2) {
    return p1.first < p2.first;
}

inline double get_y(line l, double x) {
    return (-l.C - l.A * x) / l.B;
}

inline bool intersect(point p1, point p2, point p3, point p4) {
    line l1 = line(p1, p2);
    line l2 = line(p3, p4);
    double y11 = get_y(l1, max(p1.x, p3.x));
    double y12 = get_y(l1, min(p2.x, p4.x));
    double y21 = get_y(l2, max(p1.x, p3.x));
    double y22 = get_y(l2, min(p2.x, p4.x));
    return y11 < y21 || y12 < y22;
}

inline bool bad(int a, int b) {
    int y1 = 1, y2 = 1;
    while (y1 < v[a].second.second.size() && y2 < v[b].second.second.size()) {
        //cout << y1 << " !! " << y2 << endl;
        if (intersect(v[a].second.second[y1 - 1], v[a].second.second[y1], v[b].second.second[y2 - 1], v[b].second.second[y2])) {
            return true;
        }
        if (y1 + 1 == v[a].second.second.size()) {
            ++y2;
        } else if (y2 + 1 == v[b].second.second.size()) {
            ++y1;
        } else {
            if (v[a].second.second[y1].x > v[b].second.second[y2].x) {
                ++y2;
            } else if (v[a].second.second[y1].x < v[b].second.second[y2].x) {
                ++y1;
            } else {
                ++y1;
                ++y2;
            }
        }
    }
    return false;
}

bool cmp2(int a, int b) {
    return bad(a, b);
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
            if (v[i].second.second.size()) {
                v[i].first += 1LL * (p.x - v[i].second.second.back().x) * (p.y + v[i].second.second.back().y);
            }
            v[i].second.second.push_back(p);
        }
        v[i].second.first = i;
        //cout << "              " << v[i].size() << endl;
    }
    sort(v, v + n, cmp);
    reverse(v, v + n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int poz = i;
        while (poz < n && v[i].first == v[poz].first) {
            ++poz;
        }
        --poz;
        i = poz;
        sort(p + i, p + poz, cmp2);
    }
    for (int i = 0; i < n; ++i) {
        v2[i] = v[p[i]];
    }
    for (int i = 0; i < n; ++i) {
        v[i] = v2[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (bad(i, j)) {
                printf("No\n%d %d\n", v[i].second.first + 1, v[j].second.first + 1);
                return 0;
            }
            break;
        }
    }
    printf("Yes\n");
    return 0;
}
