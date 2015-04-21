#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>


using namespace std;




struct point{
    int x, y;
    point(){}
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};


bool vec(point a, point b) {
    if (1LL * a.x * b.y < 1LL * a.y * b.x) {
        return true;
    }
    return false;
}


bool operator ==(const point a, const point b) {
    return a.x == b.x && a.y == b.y;
}


int n;
int a, b;
point p[1000][1000];
int l[1000];

int main() {
    cin >> a >> b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        l[i]++;
        for (int j = 0; j < l[i]; j++) {
            cin >> p[i][j].x >> p[i][j].y;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int l1 = 1;
            bool b = true;
            for (int g = 1; g < l[i] && b; g++) {
                while (l1 < l[j] && p[j][l1].x <= p[i][g - 1].x) {
                    l1++;
                }
                for (int g1 = l1; g1 < l[j] && b; g1++) {
                    if (p[j][g1] == p[i][g] || p[j][g1] == p[i][g - 1] || p[j][g1 - 1] == p[i][g] || p[j][g1 - 1] == p[i][g - 1]) {
                        continue;
                    }
                      //cout << "opa" << endl;
                    bool t = true;
                    if (vec(point(p[j][g1], p[i][g - 1]), point(p[i][g], p[i][g - 1])) &&
                        vec(point(p[i][g], p[i][g - 1]), point(p[j][g1 - 1], p[i][g - 1]))) {
                        t = false;
                    }
                    if (!vec(point(p[j][g1], p[i][g - 1]), point(p[i][g], p[i][g - 1])) &&
                        !vec(point(p[i][g], p[i][g - 1]), point(p[j][g1 - 1], p[i][g - 1]))) {
                        t = false;
                    }
                    if (vec(point(p[i][g], p[j][g1 - 1]), point(p[j][g1], p[j][g1 - 1])) &&
                        vec(point(p[j][g1], p[j][g1 - 1]), point(p[i][g - 1], p[j][g1 - 1]))) {
                        t = false;
                    }
                    if (!vec(point(p[i][g], p[j][g1 - 1]), point(p[j][g1], p[j][g1 - 1])) &&
                        !vec(point(p[j][g1], p[j][g1 - 1]), point(p[i][g - 1], p[j][g1 - 1]))) {
                        t = false;
                    }
                    if (t) {
                        b = false;
                    }
                }
            }
            if (!b) {
                cout << "NO" << endl;
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
