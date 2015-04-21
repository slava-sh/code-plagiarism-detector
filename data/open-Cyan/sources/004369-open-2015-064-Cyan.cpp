#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template<class T> T nextInt() {
    T x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
    int x, y;
    pt() {}
    pt(int x, int y) : x(x), y(y) {}
};

const int maxn = 300500;
const ld EPS = 1e-10;

int N, A, B;
vector<pt> v[maxn];

bool isBad(vector<pt> & a, vector<pt> & b) {
    int i = 0, j = 0;
    bool wasSmaller = false, wasBigger = false;
    while (true) {
        int curX = a[i].x;
        if (b[j].x < curX) curX = b[j].x;
        ld y, yy;
        if (a[i].x == curX) y = a[i].y;
        else {
            y = (curX - a[i].x) / (a[i + 1].x - a[i].x) * (a[i + 1].y - a[i].y) + a[i].y;
        }
        if (b[j].x == curX) yy = b[j].y;
        else {
            yy = (curX - b[j].x) / (b[j + 1].x - b[j].x) * (b[j + 1].y - b[j].y) + b[j].y;
        }
        if (y + EPS < yy) wasSmaller = true;
        if (yy + EPS < y) wasBigger = true;
        if (i + 1 == (int)a.size()) break;
        if (a[i + 1].x < b[j + 1].x) i++;
        else if (b[j + 1].x < a[i + 1].x) j++;
        else {
            i++; j++;
        }
    }
    return wasBigger && wasSmaller;
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    A = nextInt<int>();
    B = nextInt<int>();

    N = nextInt<int>();

    for (int i = 1; i <= N; i++) {
        int l = nextInt<int>();
        v[i].resize(l + 1);
        for (int j = 0; j <= l; j++) {
            v[i][j].x = nextInt<int>();
            v[i][j].y = nextInt<int>();
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            if (isBad(v[i], v[j])) {
                puts("No");
                printf("%d %d\n", i, j);
                exit(0);
            }

    puts("Yes");

    return 0;
}
