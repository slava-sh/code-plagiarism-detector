#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(int n, int k) {
    if (n == 1 || k == 0) return (n + 1) >> 1;
    int i;
    for (i = 2; i * i <= n && n % i; i++);
    if (n % i) return (n + 1) >> 1;
    i = n / i;
    return (i + 1) / 2 * f(n / i, k - 1);
}

main() {
    int n, k;
    cin >> n >> k;

    cout << f(n, k) << endl;
}
