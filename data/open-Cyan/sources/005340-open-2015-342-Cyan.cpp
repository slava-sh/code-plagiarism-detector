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


int vec(point a, point b) {
    if (1LL * a.x * b.y < 1LL * a.y * b.x) {
        return 1;
    }
    if (1LL * a.x * b.y > 1LL * a.y * b.x) {
        return 2;
    }
    return 0;
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
                   // cout << point(p[j][g1], p[i][g - 1]).x << ' ' << point(p[j][g1], p[i][g - 1]).y << endl;
                 //   cout << g1 + 1 << endl;
                    if (vec(point(p[j][g1], p[i][g - 1]), point(p[i][g], p[i][g - 1])) == 1 &&
                        vec(point(p[i][g], p[i][g - 1]), point(p[j][g1 - 1], p[i][g - 1])) == 2) {
                        t = false;
                   //     cout << "opa" << endl;
                    }
                    if (vec(point(p[j][g1], p[i][g - 1]), point(p[i][g], p[i][g - 1])) == 2 &&
                        vec(point(p[i][g], p[i][g - 1]), point(p[j][g1 - 1], p[i][g - 1])) == 1) {
                        t = false;
                      //  cout << "opa" << endl;
                    }
                    bool t1 = true;
                    if (vec(point(p[i][g], p[j][g1 - 1]), point(p[j][g1], p[j][g1 - 1])) == 2 &&
                        vec(point(p[j][g1], p[j][g1 - 1]), point(p[i][g - 1], p[j][g1 - 1])) == 1) {
                        t1 = false;
                    }
                    if (vec(point(p[i][g], p[j][g1 - 1]), point(p[j][g1], p[j][g1 - 1])) == 1 &&
                        vec(point(p[j][g1], p[j][g1 - 1]), point(p[i][g - 1], p[j][g1 - 1])) == 2) {
                        t1 = false;
                    }

                    if (!t && !t1) {
                    //cout << g1 + 1 << endl;
                  //  cout << g + 1 << endl;
                  //cout << p[i][g - 1].x << ' ' << p[i][g - 1].y << endl;
                    // cout << p[j][g1 - 1].x << ' ' << p[j][g1 - 1].y << endl;
                        b = false;
                    }
                }
            }
            if (!b) {
                cout << "No" << endl;
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
