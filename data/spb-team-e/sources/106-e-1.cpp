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
        if (ans1 + ans2 == m) {
            break;
        }
        if (a[i] && !b[i]) {
            ++ans1;
            continue;
        }
        if (!a[i] && b[i]) {
            ++ans2;
            continue;
        }
        if (!a[i] && !b[i])
            continue;
        if (cur % 2 == 0) {
            ++ans1;
        }
        else {
            ++ans2;
        }
        ++cur;
    }

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
