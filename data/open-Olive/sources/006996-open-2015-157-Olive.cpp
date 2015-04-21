#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1234567890;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (is_sorted(a.begin(), a.end())) {
        cout << -1 << ' ' << -1 << endl;
        return 0;
    }

    int best = INF, ansi = -1, ansj = -1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i], a[j]);
            int cur = 0;
            for (int ii = 1; ii < n; ii++) {
                for (int jj = ii - 1; jj >= 0; jj--) {
                    if (a[ii] < a[jj]) {
                        cur++;
                    }
                }
            }
            if (cur < best) {
                best = cur;
                ansi = i + 1;
                ansj = j + 1;
            }
            swap(a[i], a[j]);
        }
    }

    cout << ansi << ' ' << ansj << endl;
}
