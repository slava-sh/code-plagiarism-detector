#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX;

struct Point {
    double x, y;

    Point() {};
    Point(double x, double y) : x(x), y(y) {};
};

struct Line {
    double a, b, c;

    Line() {};
    Line(Point pt1, Point pt2) {
        a = pt2.y - pt1.y;
        b = pt1.x - pt2.x;
        c = -a * pt1.x - b * pt1.y;
    }

    double getY(double x) {
        return double(-a * x - c) / double(b);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double A, B;
    scanf("%lf%lf", &A, &B);

    int n;
    scanf("%d", &n);

    vector<vector<Point> > vit(n);
    for (int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);

        vit[i].resize(l + 1);

        for (int j = 0; j <= l; j++) {
            scanf("%lf%lf", &vit[i][j].x, &vit[i][j].y);
        }
    }

    for (int ii = 0; ii < n - 1; ii++) {
        for (int jj = ii + 1; jj < n; jj++) {
            bool ok1 = true, ok2 = true;
            {
                vector<Point> up = vit[ii], down = vit[jj];
                int j = 0;
                for (int i = 1; i < (int)up.size(); i++) {
                    Line lnUp = Line(up[i - 1], up[i]);
                    while (j < (int)down.size() && down[j].x <= up[i].x) {
                        if (lnUp.getY(down[j].x) < down[j].y) {
                            ok1 = false;
                            break;
                        }
                        j++;
                    }
                    if (!ok1) break;
                }
            }
            {
                vector<Point> up = vit[jj], down = vit[ii];
                int j = 0;
                for (int i = 1; i < (int)up.size(); i++) {
                    Line lnUp = Line(up[i - 1], up[i]);
                    while (j < (int)down.size() && down[j].x <= up[i].x) {
                        if (lnUp.getY(down[j].x) < down[j].y) {
                            ok2 = false;
                            break;
                        }
                        j++;
                    }
                    if (!ok2) break;
                }
            }

            if (!ok1 && !ok2) {
                cout << "No" << endl;
                cout << ii + 1 << ' ' << jj + 1 << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
