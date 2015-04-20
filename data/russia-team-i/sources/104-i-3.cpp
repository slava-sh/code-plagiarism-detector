#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

#define problem "sochi"

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main()
{
    assert(freopen(problem".in", "r", stdin) != NULL);
    assert(freopen(problem".out", "w", stdout));

    int n, d;
    cin >> n >> d;
    vector <int> a(n);
    int mx = -1;
    for (int i = 0;i < n; ++i) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    sort(a.begin(), a.end(), comp);
    for (; a.back() < d;) a.pop_back();
    sort(a.begin(), a.end());
    if ((int) a.size() <= 1) {
        printf("%d\n", mx);
        return 0;
    }
    int ans = 0;
    for (; a.size() > 2;) {
        if (a.back() >= 3 * d) {
            ans += a.back() - 2 * d;
            a.pop_back();
        }
        else {
            break;
        }
    }
    for (int i = 0; i < 2; ++i) {
        ans += a.back() - d;
        a.pop_back();
    }
    printf("%d\n", ans > mx ? ans : mx);
    return 0;
}
