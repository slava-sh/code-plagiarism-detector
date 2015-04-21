#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 1e5;
const int MOD = 1e9 + 7;
const int PWR = 31;

int hsh[N], n;
ll power[N];

bool cmp(int i1, int i2, int l) {
    ll hsh1 = ((hsh[i1 + l - 1] - hsh[i1 - 1] + MOD) * power[n - i1]) % MOD;
    ll hsh2 = ((hsh[i2 + l - 1] - hsh[i2 - 1] + MOD) * power[n - i2]) % MOD;
    return (hsh1 == hsh2);
}

int main() {
    power[0] = 1;
    for (int i = 1; i < N; i++) {
        power[i] = (power[i - 1] * PWR) % MOD;
    }
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int l;
    cin >> l;
    string s;
    cin >> s;
    n = s.length();
    hsh[0] = 0;
    for (int i = 1; i <= n; i++) {
        hsh[i] = (hsh[i - 1] + power[i] * (s[i - 1] - 'a') * (s[i - 1] - 'a')) % MOD;
    }
    int lim = min(n, l);
    for (int i = 1; i <= lim; i++) {
        if (n % i != 0) {
            continue;
        }
        bool ok = true;
        for (int j = 1; j <= n; j += i) {
            if (cmp(1, j, i) == false) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << 1 << "\n";
            cout << s.substr(0, i) << "\n";
            return 0;
        }
    }
    cout << 2 << "\n";
    cout << "a" << "\n";
    cout << "b" << "\n";
    return 0;
}