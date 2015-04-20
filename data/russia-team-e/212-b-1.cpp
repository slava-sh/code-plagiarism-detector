#include <cstdio>
#include <iostream>

using namespace std;

int n, R, mas[300000];

int main() {
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    cin >> n >> R;

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> mas[i];
        int l = 0, r = i;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (mas[i] - mas[m] > R) {
                l = m;
            } else {
                r = m;
            }
        }
        ans += l;
        if (mas[i] - mas[l] > R) {
            ++ans;
        }
    }

    cout << ans;

    return 0;
}