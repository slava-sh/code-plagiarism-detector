#include <bits/stdc++.h>

using namespace std;

#define int __int_128_t

struct Point {
    int x, y;
};

struct Curve {
    int number;
    vector<Point> points;
};

int A, B;
int N;
vector<Curve> curves;

bool cmp_begin_curve(const Curve &a, const Curve &b) {
    return a.points[0].y < b.points[0].y;
}

void get_height(const Point &p, const Point &q, int x, int &y, int &b) {
    int a = p.y - q.y;
    b = q.x - p.x;
    int c = -(a * p.x + b * p.y);
    y = -(c + a * x);
}

void tmp_check_intersection(const Curve &a, const Curve &b) {
    int is_up = 0, is_down = 0;
    for (int j = 0; j < a.points.size(); j++) {
        const Point &p = a.points[j];
        for (int i = 0; i < (int) b.points.size() - 1; i++) {
            if (!(p.x >= b.points[i].x && p.x <= b.points[i + 1].x)) continue;

            int y, k;
            get_height(b.points[i], b.points[i + 1], p.x, y, k);

            if (y / k < p.y) is_up = 1;
            if (y / k > p.y) is_down = 1;
        }
    }

    if (is_down && is_up) {
        cout << "No" << endl;
        cout << a.number << ' ' << b.number << endl;
        throw 1LL;
    }
}

void check_intersection(const Curve &a, const Curve &b) {
    tmp_check_intersection(a, b);
    tmp_check_intersection(b, a);
}

void solve(int l, int r) {
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    for (int i = l; i < r; i++) {
        if (i != m) {
            check_intersection(curves[i], curves[m]);
        }
    }
    solve(l, m);
    solve(m + 1, r);
}

main() {
    ios_base::sync_with_stdio(false);

    cin >> A >> B;
    cin >> N;

    if (N == 1) {
        cout << "Yes" << endl;
        return 0;
    }

    curves.assign(N, Curve());
    int number_dsasdsadasds = 1;
    for (auto &i: curves) {
        int l;
        cin >> l;
        i.number = number_dsasdsadasds++;
        i.points.assign(l + 1, Point {});
        for (int j = 0; j <= l; j++) {
            cin >> i.points[j].x >> i.points[j].y;
        }
    }

    sort(curves.begin(), curves.end(), cmp_begin_curve);

   /* for (int i = 0; i < N - 1; i++) {
        Curve &a = curves[i], &b = curves[i + 1];
        if (a.points.back().y > b.points.back().y) {
            cout << "No" << endl;
            cout << a.number << ' ' << b.number << endl;
            return 0;
        }
    }*/

    try {
        solve(0, N);
    } catch(int) {
        return 0;
    } catch(long long) {
        return 0;
    }

    cout << "Yes" << endl;
}
