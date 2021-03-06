#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>

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

ll min(ll a, ll b) {
    if (a > b)
        return a;
    return b;
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

    ll cur = (int)sqrt(a * b) + 1, res = gcd(a, b);
    ll _ab = a * b;
    for (int i = cur; i > 0; --i) {
        if ((_ab % i == 0) && (i/res) * (_ab/i /res) == _ab/res) {
            cur = i;
            break;
        }
    }

    ll cur2 = (a * b) / cur;
    cout << cur * cur2 << ' ' << _ab << endl;
    cout << min(cur, cur2) << ' ' << max(cur, cur2) << endl;

    return 0;
}
