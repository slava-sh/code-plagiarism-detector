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
int xs[1005], xslen;

bool isBad(vector<pt> & a, vector<pt> & b) {
    int i = 0, j = 0, xslen = 0;
    while (i < (int)a.size() || j < (int)b.size())
        if (i == (int)a.size()) xs[xslen++] = b[j++].x;
        else if (j == (int)b.size()) xs[xslen++] = a[i++].x;
        else if (a[i].x < b[j].x) xs[xslen++] = a[i++].x;
        else xs[xslen++] = b[j++].x;
    int itx = 0;
    i = 0, j = 0;
    bool wasSmaller = false, wasBigger = false;
    while (itx < xslen) {
        int curX = xs[itx++];
        while (i + 1 < (int)a.size() && a[i + 1].x <= curX) i++;
        while (j + 1 < (int)b.size() && b[j + 1].x <= curX) j++;
        ld y, yy;
        if (a[i].x == curX) y = a[i].y;
        else {
            y = ld(curX - a[i].x) / (a[i + 1].x - a[i].x) * (a[i + 1].y - a[i].y) + a[i].y;
        }
        if (b[j].x == curX) yy = b[j].y;
        else {
            yy = ld(curX - b[j].x) / (b[j + 1].x - b[j].x) * (b[j + 1].y - b[j].y) + b[j].y;
        }
        if (y + EPS < yy) wasSmaller = true;
        if (yy + EPS < y) wasBigger = true;
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
