#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1e9 + 7;
const int P = 127;

int a[3], p[20010];
ll h[20010], st[20010];

int hh(int l, int r) {
    if (l == 0) return h[r];
    ll cur = (h[l - 1] * st[r - l + 1]) % M;
    return (h[r] - cur + M) % M;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l;
    cin >> l;
    string s;
    cin >> s;
    int n = s.size();

    if (l >= n) {
        cout << 1 << endl;
        cout << s << endl;
        return 0;
    }

    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    int k = n - p[n - 1];
    if (k <= l && n % k == 0) {
        cout << 1 << endl;
        for (int i = 0; i < k; ++i) cout << s[i];
        cout << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) a[s[i] - 'a']++;
    if (a[0] == 0) {
        cout << 2 << endl;
        cout << 'b' << endl << 'c' << endl;
        return 0;
    }
    if (a[1] == 0) {
        cout << 2 << endl;
        cout << 'a' << endl << 'c' << endl;
        return 0;
    }
    if (a[2] == 0) {
        cout << 2 << endl;
        cout << 'a' << endl << 'b' << endl;
        return 0;
    }

    if (l >= (n + 1) / 2) {
        cout << 2 << endl;
        for (int i = 0; i < (n + 1) / 2; ++i) cout << s[i];
        cout << endl;
        for (int i = (n + 1) / 2; i < n; ++i) cout << s[i];
        cout << endl;
        return 0;
    }

    h[0] = s[0];
    for (int i = 1; i < n; ++i) {
        h[i] = (h[i - 1] * P + s[i]) % M;
    }
    st[0] = 1;
    for (int i = 1; i < n; ++i) {
        st[i] = (st[i - 1] * P) % M;
    }
    for (int x = 0; x < l; ++x) {
        int i = x;
        if (p[i] > 0 && (i + 1) % (i + 1 - p[i]) == 0) continue;
        while (i + x + 1 < n && i + 1 == p[i + x + 1]) i += x + 1;
        for (int j = 0; j < l && i + j + 1 < n; ++j) {
            bool fl = true;
            for (int i2 = i + j + 2; i2 < n; ) {
                if (i2 + x < n && hh(i2, i2 + x) == hh(0, x)) {
                    i2 += x + 1;
                } else if (i2 + j < n && hh(i2, i2 + j) == hh(i + 1, i + j + 1)) {
                    i2 += j + 1;
                } else {
                    fl = false;
                    break;
                }
            }
            if (fl) {
                cout << 2 << endl;
                for (int i2 = 0; i2 <= x; ++i2) cout << s[i2];
                cout << endl;
                for (int i2 = i + 1; i2 <= i + j + 1; ++i2) cout << s[i2];
                cout << endl;
                return 0;
            }
        }
    }


    cout << 3 << endl;
    cout << 'a' << endl << 'b' << endl << 'c' << endl;

    return 0;
}

