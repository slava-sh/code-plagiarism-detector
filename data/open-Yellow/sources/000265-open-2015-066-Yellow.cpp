#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define prev prev_
#define next next_

int main() {
    #define task "a"
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n + 2, -(int)1.1e9);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cur = -1;
    for (int i = 1; i <= n + 1; i++) {
        cur += a[i] != a[i - 1];
    }
    int q;
    cin >> q;
    while(q--) {
        int i, c;
        cin >> i >> c;
        int f = (int)(a[i] != a[i - 1]) + (int)(a[i] != a[i + 1]);
        a[i] = c;
        int e = (int)(a[i] != a[i - 1]) + (int)(a[i] != a[i + 1]);
        cur += e - f;
        cout << cur << endl;
    }
    return 0;
}
