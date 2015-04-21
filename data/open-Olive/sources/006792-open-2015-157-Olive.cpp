#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = 0;
    vector<int> inv(n);
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] < a[j]) {
                inv[i]++;
            }
        }
        if (inv[i] >= inv[mx]) {
            mx = i;
        }
    }

    int mxi = 0;
    for (int i = 0; i < mx; i++) {
        if (inv[i] > 0) break;
        if (a[mxi] < a[i]) {
            mxi = i;
        }
    }

    if (is_sorted(a.begin(), a.end())) {
        cout << -1 << ' ' << -1 << endl;
        return 0;
    }

    cout << mxi + 1 << ' ' << mx + 1 << endl;
}
