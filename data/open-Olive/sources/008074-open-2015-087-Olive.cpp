#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int f[1001000];
int t[1001000];
int n;

void inc (int x) {
    for (; x <= n; x |= (x+1)) {
        t[x] += 1;
    }
}

int sum (int x) {
    int res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        res += t[x];
    }
    return res;
}

int sum (int l, int r) {
    if (l > r) return 0;
    //cout << "sum " << l << " " << r << endl;
    //cout << "ans: " << sum(r) - sum(l - 1) << endl;
    return sum(r) - sum(l-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    int ans = 0;
    int a1 = -1, a2 = -1;
    int d1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            t[j] = 0;
        }
        for (int j = i+1; j <= n; j++) {
            //cout << "ij " << i << " " << j << endl;
            d1 = sum(f[j] + 1, f[i] - 1);
            if (d1 > ans) {
                a1 = i;
                a2 = j;
                ans = d1;
            }
            inc(f[j]);
        }
    }
    //cout << ans << endl;
    cout << a1 << " " << a2 << endl;
    return 0;
}
