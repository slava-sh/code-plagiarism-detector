#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long
#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int a[100005], n, k;

bool check(int m) {
    int kol = 0;
    for(int i = 1; kol <= k && i <= n; i ++)
        if(kol >= a[i] - m)
            kol += m;
        else
            kol = a[i];
    return (kol <= k);
}


int main() {
    in("fence.in");
    out("fence.out");
    int i, l, r, m;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    l = 0; r = a[1];
    while(l + 1 < r) {
        m = (l + r) / 2;
        if(check(m))
            l = m;
        else
            r = m;
    }
    if(check(r))
        l = r;
    cout << l;
}
