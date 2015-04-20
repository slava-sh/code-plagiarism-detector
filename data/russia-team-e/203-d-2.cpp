#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, a[100001];

bool f(int m) {
    int t = a[0];
    if (a[0] - m < 0) return false;
    for (int i = 1; i < n; ++i) {
        if (t > k) return false;
        if (a[i] - m < 0) return false;
        if (a[i] - m > t) t = a[i];
        else t += m;
        if (t > k) return false;
    }
    return true;
}


int main () {
    freopen ("fence.in","r",stdin);
    freopen ("fence.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort (a, a + n);
    int l = 0;
    int r = k;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (f(m)) l = m;
        else r = m;
    }
    if (f(r)) cout << r;
    else cout << l;
}
