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


#define INF 1000000000


struct point{
    long long x, y;
    point(){}
    point(long long _x, long long _y) {
        x = _x;
        y = _y;
    }
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};


int vec(point a, point b) {
    if (a.x * b.y - a.y * b.x < 0) {
        return 1;
    }
    if (a.x * b.y - a.y * b.x > 0) {
        return 2;
    }
    return 0;
}


bool operator ==(const point a, const point b) {
    return a.x == b.x && a.y == b.y;
}


int n;
int a, b1;
point p[1000][1000];
int l[1000];

int main() {
    cin >> a >> b1;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        l[i]++;
        for (int j = 0; j < l[i]; j++) {
            scanf("%lld %lld", &p[i][j].x, &p[i][j].y);
            v.push_back(p[i][j].x);
        }
    }
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    int v2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            v2++;
            if (v2 >= 2300) {
                cout << "Yes" << endl;
                return 0;
            }
            bool b = true;
            bool b2 = true;
            int k = 1;
            int k1 = 1;
            for (int g = 0; g < (int)v.size(); g++) {
                int x = v[g];
                double y = INF;
                while (k < l[i]) {
                    if (x >= p[i][k - 1].x && x <= p[i][k].x) {
                        y = double(p[i][k].y - p[i][k - 1].y) / double(p[i][k].x - p[i][k - 1].x);
                         y = p[i][k - 1].y + y * (x - p[i][k - 1].x);
                        break;
                    }
                    k++;
                }
                double y2 = INF;
                while (k1 < l[j]) {
                    if (x >= p[j][k1 - 1].x && x <= p[j][k1].x) {
                        y2 = double(p[j][k1].y - p[j][k1 - 1].y) / double(p[j][k1].x - p[j][k1 - 1].x);
                        y2 = p[j][k1 - 1].y + y2 * (x - p[j][k1 - 1].x);
                        break;
                    }
                    k1++;
                }
                if (y > y2) {
                    b = false;
                }
                if (y < y2) {
                    b2 = false;
                }
                //cout << y << ' ' << y2 << endl;
            }
            if (!b && !b2) {
                cout << "No" << endl;
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
