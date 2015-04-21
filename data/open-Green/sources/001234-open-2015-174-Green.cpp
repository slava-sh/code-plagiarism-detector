#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> divisors;

void factorize(int n) {
    divisors.clear();
    int i = 1;
    while (i * i < n) {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n / i);
        }
        i++;
    }
    if (i * i == n) divisors.push_back(i);
}

int f(int n, int k) {
    if (n == 1 || k == 1) return (n + 1) >> 1;
    int i;
    for (i = 2; i * i <= n && n % i; i++);
    if (n % i) return (n + 1) >> 1;
    return (i + 1) / 2 * f(n / i, k - 1);
}

int f2(int n, int k) {
    if (k == 1) return (n + 1) >> 1;
    int result = (n + 1) >> 1;
    for (auto d: divisors) {
        if (n % d == 0) {
            result = min(result, (d + 1) / 2 * f(n / d, k - 1));
        }
    }
    return result;
}

main() {
    /*factorize(45);
    cout << f(45, 2) << ' ' << f2(45, 2) << endl;
    int n, k = 2;
    //cin >> n >> k;
    for (int n = 1; n < 10000; n++) {
        factorize(n);
        if (f(n, k) != f2(n, k)) {
            cout << n << endl;
            break;
        }
    }*/

    int n, k;
    cin >> n >> k;

    factorize(n);
    cout << f2(n, k) << endl;
}
