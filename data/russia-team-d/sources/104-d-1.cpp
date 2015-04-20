#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define problem "fence"

using namespace std;

const int N = 100500;

int a[N];

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));

    int n, k;
    cin >> n >> k;
    int r = 2 * 1e9;
    for (int i = 0; i  < n; ++i) {
        scanf("%d", &a[i]);
        r = min(a[i], r);
    }
    ++r;
    int l = 0;
    sort(a, a + n);
    while(r - l > 1) {
        int x = (l + r) / 2;
        int h = 0;
        bool p = 1;
        for (int i = 0; i < n; ++i) {
            h = max(a[i], h + x);
//            printf("%d %d\n", x, h);
            if (h > k) {
                p = 0;
                break;
            }
        }
        if (p) {
            l = x;
        }
        else {
            r = x;
        }
    }
    printf("%d\n", l);
    return 0;
}
