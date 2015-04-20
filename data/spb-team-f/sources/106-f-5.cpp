
#include <iostream>
#include <math.h>
#include <stdio.h>

#define ll long long

using namespace std;

bool isPrime(int x) {
    if (x <= 3)
        return true;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

ll gcd(ll a, ll b) {
    ll c = -1;
    while (c != 0) {
        c = a % b, a = b, b = c;
    }
    return a;
}

int main() {
    freopen("gcm.in", "r", stdin);
    freopen("gcm.out", "w", stdout);
    ll a, b;

    cin >> a >> b;

    if (isPrime(a) && isPrime(b)) {
        cout << min(a, b) << ' ' << max(b, a) << endl;
        return 0;
    }

    int cur = (int)sqrt(a * b) + 1, res = gcd(a, b);
    a /= res;
    b /= res;
    cur = (int)sqrt(a * b) + 1,
    ll _ab = a * b;
    for (int i = cur; i > 0; --i) {
        if ((_ab % i == 0) && gcd(i, (_ab) / i) == res) {
            cur = i;
            break;
        }
    }

    int cur2 = (a * b) / cur;
    cout << min(cur, cur2) * res << ' ' << max(cur, cur2) * res << endl;

    return 0;
}
