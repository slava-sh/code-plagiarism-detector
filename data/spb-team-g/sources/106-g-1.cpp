#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

#define ll long long

using namespace std;

int main() {
    freopen("merlin.in", "r", stdin);
    freopen("merlin.out", "w", stdout);
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    double s = 0;
    for (int i = 0; i < n; ++i)
        s += a[i];

    double x;
    for (int cur = n; cur >= 1; --cur) {
        x = s / cur;
        if ((upper_bound(a.begin(), a.end(), x) - a.begin()) >= cur) {
            cout << n - cur << endl;
            return 0;
        }
    }

    return 0;
}
