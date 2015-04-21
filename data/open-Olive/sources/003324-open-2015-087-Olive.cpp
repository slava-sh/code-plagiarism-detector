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
int d[1001000];
int l[1001000];
int n;

int get () {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = f[i];
        l[d[i]] = i;
    }
    for (int i = n-1; i > 0; i--) {
        int lc = l[i];
        while (lc > 1 && d[lc] < d[lc - 1]) {
            swap(l[i], l[d[lc - 1]]);
            swap(d[lc], d[lc-1]);
            lc--;
            ans++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int lc = l[i];
        while (lc > 1 && d[lc] < d[lc - 1]) {
            swap(l[i], l[d[lc - 1]]);
            swap(d[lc], d[lc-1]);
            lc--;
            ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    int ans = 10000000;
    int a1 = -1, a2 = -1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            swap(f[i], f[j]);
            int u = get();
            //cout << i << " " << j << " " << u << endl;
            if (u < ans) {
                ans = u;
                a1 = i;
                a2 = j;
            }
            swap(f[i], f[j]);
        }
    }
    if (f[a1] < f[a2]) {
        a1 = -1;
        a2 = -1;
    }
    cout << a1 << " " << a2 << endl;
    return 0;
}
