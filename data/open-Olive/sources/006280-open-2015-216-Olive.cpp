#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 1e6 + 10;

int tree[N], a[N], n, inv[N];

int sum(int x) {
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        res += tree[i];
    }
    return res;
}

void modify(int x) {
    for (int i = x; i < N; i = (i | (i + 1))) {
        tree[i]++;
    }
}

int get_lower(int l, int r, int x) {
    int res = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] < x) {
            res++;
        }
    }
    return res;
}

int get_upper(int l, int r, int x) {
    int res = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] > x) {
            res++;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        inv[i] = i - sum(a[i]) - 1;
        modify(a[i]);
    }
    ll brute = 0;
    for (int i = 1; i <= n; i++) {
        brute += inv[i];
    }
    ll ans = brute;
    int p1 = -1, p2 = -1;
    for (int i1 = 1; i1 <= n; i1++) {
        for (int i2 = i1 + 1; i2 <= n; i2++) {
            if (a[i1] < a[i2]) {
                continue;
            }
            ll cur = brute - 1;
            cur = cur + get_upper(i1 + 1, i2 - 1, a[i1]);
            cur = cur - get_lower(i1 + 1, i2 - 1, a[i1]);
            cur = cur - get_upper(i1 + 1, i2 - 1, a[i2]);
            cur = cur + get_lower(i1 + 1, i2 - 1, a[i2]);
            if (ans > cur) {
                ans = cur;
                p1 = i1;
                p2 = i2;
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        cout << inv[i] << " ";
    }
    cout << "\n";
    cout << ans << "\n";
    */
    cout << p1 << " " << p2 << "\n";
    return 0;
}