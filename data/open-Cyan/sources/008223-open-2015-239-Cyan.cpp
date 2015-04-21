#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define mp make_pair
#define x first
#define y second
#define point pair<long double, long double>
#define pb push_back
#define For(i, a, b) for(int i = a; i < b; ++i)
#define eps 1e-13
#define abs(a) a < 0 ? -a : a

using namespace std;



int n, m;
vector <point> arr[10000];



point vec(point a, point b) {
    return mp(b.x - a.x, b.y - a.y);
}
double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
double scal(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}
double alf(point a, point b) {
    return atan2(cross(a, b), scal(a, b));
}
double distAB(point a, point b, point c) {
    return abs(cross(vec(a, b), vec(a, c)) / dist(a, b));
}
point gr901(point a) {
    return mp(a.y, -a.x);
}
point gr902(point a) {
    return mp(-a.y, a.x);
}
point gotoA(point a, point b) {
    return mp(a.x + b.x, a.y + b.y);
}
bool inlineAB(point a, point b, point c) {
    return abs(0 - distAB(a, b, c)) < eps;
}
point normto(point a, double s) {
    return mp(a.x / dist(mp(0, 0), a) * s, a.y / dist(mp(0, 0), a) * s);
}
point gotoAB(point a, point b, point c) {
    point a1 = normto(gr901(vec(a, b)), distAB(a, b, c));
    point a2 = normto(gr902(vec(a, b)), distAB(a, b, c));
    if (inlineAB(a, b, gotoA(c, a1))) {
        return gotoA(c, a1);
    }
    else {
        return gotoA(c, a2);
    }
}
bool inAB(point a, point b, point c) {
    return abs(dist(a, c) + dist(c, b) - dist(a, b)) < eps;
}
bool crossAB(point a, point b, point c, point d) {
    if ((normto(vec(a, b), 1) == mp((long double)1, (long double)0)) || (normto(vec(c, d), (long double)1) == mp((long double)1, (long double)0))) {
        return false;
    }
    if (abs(cross(normto(vec(a, b), 1), normto(vec(c, d), 1))) < eps) {
        return false;
    }
    point ans1 = normto(vec(a, b), 1);
    point ans2 = normto(vec(a, c), 1);
    point ans3 = normto(vec(a, d), 1);
    if (cross(ans1, ans2) * cross(ans1, ans3) < 0) {
        ans1 = normto(vec(c, d), 1);
        ans2 = normto(vec(c, a), 1);
        ans3 = normto(vec(c, b), 1);
        return cross(ans1, ans2) * cross(ans1, ans3) < 0;
    }
    return false;
}
bool crossG(int a1, int a2) {
    vector <pair<pair <point, int>, bool> > edge;
    For(i, 0, (int)arr[a1].size() - 1) {
        edge.pb(mp(mp(arr[a1][i], i), true));
    }
    For(i, 0, (int)arr[a2].size() - 1) {
        edge.pb(mp(mp(arr[a2][i], i), false));
    }
    int L = 0, R = 0;
    sort(edge.begin(), edge.end());
    For(i, 0, edge.size()) {
        if (edge[i].y) {
            if (inAB(arr[a2][R], arr[a2][R + 1], arr[a1][L + 1])) {
                int yx = arr[a1][L + 1].y;
                if (((yx < arr[a2][R].y) ^ (yx < arr[a2][R + 1].y)) &&
                    ((yx < arr[a1][L].y) ^ (yx < arr[a1][edge[i].x.y + 1].y))) {
                    return true;
                }
            }
            L = edge[i].x.y;
        }
        else {
            swap(L, R);
            swap(a1, a2);
            if (inAB(arr[a2][R], arr[a2][R + 1], arr[a1][L + 1])) {
                int yx = arr[a1][L + 1].y;
                if (((yx < arr[a2][R].y) ^ (yx < arr[a2][R + 1].y)) &&
                    ((yx < arr[a1][L].y) ^ (yx < arr[a1][edge[i].x.y + 1].y))) {
                    return true;
                }
            }
            swap(L, R);
            swap(a1, a2);
            R = edge[i].x.y;
        }
        //cout << L << ' ' << R  << ' ' << i << endl;
        if (crossAB(arr[a1][L], arr[a1][L + 1], arr[a2][R], arr[a2][R + 1])) {
            return true;
        }
    }
    return false;
}


int main() {
    cin >> n >> m;
    cin >> n;
    For(i, 0, n) {
        cin >> m;
        For(j, 0, m + 1) {
            int a, b;
            cin >> a >> b;
            arr[i].pb(mp(a, b));
        }
    }
    For(i, 0, n) {
        For(j, i + 1, n) {
            if (crossG(i, j)) {
                cout << "No" << endl;
                cout << i + 1 << ' ' << j + 1 << endl;\
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}

