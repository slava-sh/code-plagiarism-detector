#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> colors(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    set<int> borders;
    borders.insert(0);
    for (int i = 1; i < n; i++) {
        if (colors[i] != colors[i - 1]) {
            borders.insert(i);
        }
    }
    borders.insert(n);

    int Q;
    cin >> Q;
    while (Q--) {
        int p, c;
        cin >> p >> c;
        p--;

        int l = *borders.lower_bound(p);
        int r = *borders.upper_bound(p);

        if (n != 1 && colors[p] != c) {
            if (p == l && p == r - 1) {
                borders.erase(p);
                if (p == 0 || c != colors[p - 1]) {
                    borders.insert(p);
                }
                if (p + 1 != n && c == colors[p + 1]) {
                    borders.erase(p + 1);
                }
            } else if (p == l) {
                borders.insert(p + 1);
                if (p != 0 && c == colors[p - 1]) {
                    borders.erase(p);
                }
            } else if (p == r - 1) {
                borders.insert(p);
                if (p + 1 != n && c == colors[p + 1]) {
                    borders.erase(p + 1);
                }
            } else {
                borders.insert(p);
                borders.insert(p + 1);
            }
        }
        colors[p] = c;
        cout << (int) borders.size() - 1 << endl;
    }
}
