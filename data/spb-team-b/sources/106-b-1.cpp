#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (; a[ans] >= ans; ++ans) {
    }
    cout << ans << endl;
    return 0;
}
