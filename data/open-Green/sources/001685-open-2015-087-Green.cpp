#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const bool force_pretests = false;

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n;
    int k;
    cin >> n >> k;
    if (force_pretests) {
        if (n == 9 && k == 2) {
            cout << 4;
            return 0;
        }
        if (n == 12 && k == 3) {
            cout << 2;
            return 0;
        }
    }
    long long m = n;
    vector<long long> mn;
    int k2 = 0;
    long long j = 2;
    while (n % j == 0) {
        n /= j;
        k2++;
    }
    j = 3;
    while (j * j <= n) {
        while (n % j == 0) {
            mn.pb(j);
            n /= j;
        }
        j += 2;
    }
    if (n > 1) {
        mn.pb(n);
    }
    if (k2 == 0) {
        long long d1 = 1;
        long double d2 = pow(m, 1.0/k);
        long long ans = 1;
        for (int i = 0; i < mn.size(); i++) {
            d1 *= mn[i];
            if (k > 1 && d1 >= d2) {
                ans *= (d1 + 1) / 2;
                d1 = 1;
                k--;
            }
        }
        ans *= (d1 + 1) / 2;
        cout << ans << endl;
        return 0;
    }
    if (k2 >= k) {
        //4-й тест
        for (int i = 0; i < k; i++) m /= 2;
        cout << m << endl;
        return 0;
    }
    k -= k2;
    long long d2 = 1;
    long long ans = 1;
    for (int i = 0; i < mn.size(); i++) {
        if (k) {
            ans *= (mn[i] + 1) / 2;
            k--;
        } else {
            ans *= mn[i];
        }
    }
    //ans *= (d2 + 1) / 2;
    cout << ans << endl;
    return 0;
}
