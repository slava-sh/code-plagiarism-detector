#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int n, l1, r1, l2, r2, m;
    cin >> n >> m >> l1 >> r1 >> l2 >> r2;
    vector<int> h(n), a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    for (int i = 0; i < n; ++i) {
        if (h[i] >= l1 && h[i] <= r1)
            a[i] = true;
        if (h[i] >= l2 && h[i] <= r2)
            b[i] = true;
    }

    int ans1 = 0, ans2 = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] && b[i] && cur < m)
            ++cur;
    }


    int cur1 = 0, cur2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] && !b[i])
            cur1++;
        if (b[i] && !a[i])
            cur2++;
    }

    //cout << ans1 << ' ' << ans2 << ' ' << cur << endl;
    //cout << cur1 << ' ' << cur2 << endl;

    for (int i = cur; i < m; ++i) {
        if (i % 2 == 0 && cur1 > ans1) {
            ans1++;
        }
        if (i % 2 == 1 && cur2 > ans1) {
            ans2++;
        }
    }

    ans2 += cur / 2;
    ans1 += cur - cur / 2;

   // cout << ans1 << ' ' << ans2 << endl;

    if (ans1 > ans2) {
        cout << "Petya\n";
    }
    else {
        if (ans1 == ans2)
            cout << "Draw\n";
        else
            cout << "Vasya\n";
    }

    return 0;
}
