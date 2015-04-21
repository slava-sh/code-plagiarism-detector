#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 100000 + 10;
const int EPS = 1e-9;

vector <pii> lines[N];
int was;

double myabs(int &x, double &y) {
    return (x < y ? y - x : x - y);
}

double myabs(double &x, double &y) {
    return (x < y ? y - x : x - y);
}

double get_coord(int i, int j, double x) {
    return lines[i][j - 1].second + (lines[i][j].second - lines[i][j - 1].second) * ((x - lines[i][j - 1].first) / (lines[i][j].first - lines[i][j - 1].first));
}

void check(int new_was, int i, int j) {
    if (was == 1 && new_was == 2) {
        cout << "No\n";
        cout << i << " " << j << "\n";
        exit(0);
    }
    if (was == 2 && new_was == 1) {
        cout << "No\n";
        cout << i << " " << j << "\n";
        exit(0);
    }
    was = new_was;
}

double get_intersect(double &x1, double &y1, double &x2, double &y2, double &i1, double &j1, double &i2, double &j2) {
    double a1 = y1 - y2;
    double b1 = x2 - x1;
    double c1 = x1 * y2 - x2 * y1;
    double a2 = j1 - j2;
    double b2 = i2 - i1;
    double c2 = i1 * j2 - i2 * j1;
    return (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1);
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int leng;
        cin >> leng;
        for (int j = 0; j <= leng; j++) {
            int x, y;
            cin >> x >> y;
            x -= a;
            lines[i].push_back(make_pair(x, y));
        }
    }
    b -= a;
    a = 0;
    cout << setprecision(6) << fixed;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            //cout << "LOOKING IN " << i << " " << j << "\n";
            int i1 = 0, i2 = 0;
            was = 0;
            double lf = 0;
            while (true) {
                while (i1 < lines[i].size() && myabs(lines[i][i1].first, lf) <= EPS) {
                    i1++;
                }
                if (i1 == lines[i].size()) {
                    break;
                }
                while (i2 < lines[j].size() && myabs(lines[j][i2].first, lf) <= EPS) {
                    i2++;
                }
                if (i2 == lines[j].size()) {
                    break;
                }
                double rh = min(lines[i][i1].first, lines[j][i2].first);
                double y11 = get_coord(i, i1, lf);
                double y12 = get_coord(i, i1, rh);
                double y21 = get_coord(j, i2, lf);
                double y22 = get_coord(j, i2, rh);
                /*
                cout << "RANGE FROM " << lf << " " << rh << "\n";
                cout << "COORD FOR FIRST: " << y11 << " " << y12 << "\n";
                cout << "COORD FOR SECOND: " << y21 << " " << y22 << "\n";
                cout << "\n";
                */
                int cmp1;
                if (myabs(y11, y21) <= EPS) {
                    cmp1 = 0;
                } else if (y11 > y21) {
                    cmp1 = 1;
                } else {
                    cmp1 = 2;
                }
                int cmp2;
                if (myabs(y12, y22) <= EPS) {
                    cmp2 = 0;
                } else if (y12 > y22) {
                    cmp2 = 1;
                } else {
                    cmp2 = 2;
                }
                //cout << cmp1 << " " << cmp2 << "\n";
                if (cmp1 == 0 && cmp2 == 0) {
                    lf = rh;
                    continue;
                }
                if (cmp1 == 0 && cmp2 == 1) {
                    lf = rh;
                    check(1, i, j);
                    continue;
                }
                if (cmp1 == 0 && cmp2 == 2) {
                    lf = rh;
                    check(2, i, j);
                    continue;
                }
                if (cmp1 == 1 && cmp2 == 0) {
                    lf = rh;
                    was = 1;
                    continue;
                }
                if (cmp1 == 1 && cmp2 == 1) {
                    lf = rh;
                    was = 1;
                    continue;
                }
                if (cmp1 == 1 && cmp2 == 2) {
                    cout << "No\n";
                    cout << i << " " << j << "\n";
                    return 0;
                }
                if (cmp1 == 2 && cmp2 == 0) {
                    lf = rh;
                    was = 2;
                    continue;
                }
                if (cmp1 == 2 && cmp2 == 1) {
                    cout << "No\n";
                    cout << i << " " << j << "\n";
                    return 0;
                }
                if (cmp1 == 2 && cmp2 == 2) {
                    lf = rh;
                    was = 2;
                    continue;
                }
            }
        }
    }
    cout << "Yes\n";
    return 0;
}