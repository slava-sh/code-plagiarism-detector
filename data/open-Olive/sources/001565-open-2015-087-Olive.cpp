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
int g[1001000];

int fans1 (int x) {
    return abs(x - f[x]) + 2 * f[x];
}

pair<int,int> max1 (int l, int r) {
    pair<int,int> ans;
    ans.F = fans1(g[l]);
    ans.S = g[l];
    for (int i = l+1; i <= r; i++) {
        if (fans1(g[i]) > ans.F) {
            ans.F = fans1(g[i]);
            ans.S = g[i];
        }
    }
    return ans;
}

int fans2 (int x) {
    return abs(x - f[x]) - 2 * f[x];
}

pair<int,int> max2 (int l, int r) {
    pair<int,int> ans;
    ans.F = fans2(g[l]);
    ans.S = g[l];
    for (int i = l; i <= r; i++) {
        cout << g[i] << " " << fans2(g[i]) << endl;
        if (fans2(g[i]) > ans.F) {
            ans.F = fans1(g[i]);
            ans.S = g[i];
        }
    }
    return ans;
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        g[f[i]] = i;
    }
    int ans = -1;
    int a1, a2;
    a1 = -1;
    a2 = -1;
    for (int i = 5; i <= n; i++) {
        if (i > 1) {
            pair<int,int> ff = max1(1, i - 1);
            if (ff.F - 2 * i + abs(i - f[i]) > ans) {
                ans = ff.F - 2 * i + abs(i - f[i]);
                a1 = i;
                a2 = ff.S;
            }
        } else if (i < n) {
            pair<int,int> ff = max2(i + 1, n);
            if (ff.F + 2 * i + abs(i - f[i]) > ans) {
                ans = ff.F + 2 * i + abs(i - f[i]);
                a1 = i;
                a2 = ff.S;
            }
        }
    }
    cout << a1 << " " << a2 << endl;
    return 0;
}
