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

const int maxn = (int)1e6 + 5;

pair<int, int> ft[maxn];
int n, a[maxn], pr[maxn];
int v[maxn], vlen;

void assignFT(int r, pair<int, int> x) {
    while (r < maxn) {
        if (x > ft[r]) ft[r] = x;
        r |= r + 1;
    }
}

pair<int, int> maxFT(int r) {
    pair<int, int> x = ft[r];
    while (r >= 0) {
        if (ft[r] > x) x = ft[r];
        r = (r & (r + 1)) - 1;
    }
    return x;
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    n = nextInt<int>();

    for (int i = 1; i <= n; i++) {
        a[i] = n - nextInt<int>() + 1;
    }

    for (int i = 1; i <= n; i++) {
        pair<int, int> t = maxFT(a[i] - 1);
        pr[i] = t.second;
        assignFT(a[i], make_pair(t.first + 1, i));
    }

    pair<int, int> t = maxFT(maxn - 1);

    int i = t.second;

    while (i != 0) {
        v[vlen++] = i;
        i = pr[i];
    }

    reverse(v, v + vlen);

    if (vlen == 1) {
        puts("-1 -1");
        exit(0);
    }

    printf("%d %d\n", v[0], v[vlen - 1]);

    return 0;
}
