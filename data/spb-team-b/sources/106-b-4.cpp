#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 1;
    for (; a[ans] >= ans && ans <= n; ++ans) {
    }
    cout << ans - 1 << endl;
    for (int i = 1; i < ans; ++i) {
        cout << i << ' ' << i << endl;
    }
    return 0;
}
