#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 300000;

int cnt;
ll md = 1e9 + 7;
ll ans = 0;
ll pr[N], g[N], s[N], n, p, k;

int fnd (int v) {
    if (pr[v] == v)
        return v;
    int h = fnd(pr[v]);
    pr[v] = h;
    return h;
}

int un(int aa, int bb) {
    if (aa == bb && aa == -1) return -1;
    if (aa == -1) {
        return bb;
    }
    if (bb == -1) {
        return aa;
    }
    pr[aa] = bb;
    return bb;
}

void unit (int v1, int v2, bool eq) {
    v1 = fnd(v1);
    v2 = fnd(v2);
    if (v1 == s[v2]) {
        if (eq) {
            cout << "0";
            exit(0);
        }
        else return;
    }

    if (v1 == v2) {
        if (eq)
            return;
        else {
            cout << "0";
            exit(0);
        }
    }

    if (!eq)
        v1 = s[v1];

    int w1 = un(v1, v2);
    int w2 = un(s[v1], s[v2]);
    if (w1 >= 0) s[w1] = w2;
    if (w2 >= 0) s[w2] = w1;

    cnt--;

}

int main() {
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);

    cin >> n;
    cnt = n;
    for (int i = 0; i < n; i++) {
        pr[i] = i;
        s[i] = -1;
    }
    cin >> k;
    if (k > 0) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        cin >> k;
        if (k == -1) continue;
        if (i + k > n) {
            cout << 0;
            return 0;
        }
        for (int j = 0; j < k; j++)
            unit(j, i + j, true);
        if (i + k < n)
            unit(k, i + k, false);
    }

    ans = 1;
    for (int i = 0; i < cnt; i++)
        ans = (ans * 2) % md;
    cout << ans;

    return 0;
}
