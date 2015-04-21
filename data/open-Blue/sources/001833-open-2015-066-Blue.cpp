#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define prev prev_
#define next next_

const int INF = (int)1e9;

int abs_(int x) {
    return max(x, -x);
}

int main() {
    #define task "a"
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int l;
    string s;
    cin >> l>> s;
    int n = sz(s);
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1];
        while (p[i] && s[p[i]] != s[i]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            p[i]++;
        }
    }
    int len = n - p[n - 1];
    if (n % len != 0) {
        len = n;
    }
    if (len > l) {
        cout << 2 << endl;
        cout << "a" << endl;
        cout << "b" << endl;
    } else {
        cout << 1 << endl;
        cout << s.substr(0, len) << endl;
    }
    return 0;
}
