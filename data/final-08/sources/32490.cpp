#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    double ps[n + 1];

    for (int i = 0; i < n + 1; ++i) {
        cin >> ps[i];
    }

    double ret = 0.0;

    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n + 1; ++b) {
            if (2 * a > n || 2 * b < n) {
                continue;
            }

            double ca = (0.5 * n - b) / (a - b);
            double cb = (0.5 * n - a) / (b - a);

            ret = max(ret, ca * ps[a] + cb * ps[b]);
        }
    }

    cout << ret;

    return 0;
}
