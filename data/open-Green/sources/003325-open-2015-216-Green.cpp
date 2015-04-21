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
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int LIM = 33000000;
const int N = 2100000;
const int K = 10;
const ll INF = 2e18;

ll pr[N], mas[100], k, n;
bool used[LIM + 10];
ll f[N][K + 1];

int main() {
        int cnt = 0;
    for (ll i = 2; i <= LIM; i++) {
        if (used[i]) {
            continue;
        }
        cnt++;
        pr[cnt] = i;
        ll j = i * i;
        while (j <= LIM) {
            used[j] = true;
            j += i;
        }
    }
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    while (k != 0) {
        if (k == 1) {
            ans *= (n + 1) / 2;
            break;
        }
        ll x = (sqrt(n) + 1);
        while (n % x != 0) {
            x--;
        }
        ans *= (n / x + 1) / 2;
        n = x;
        k--;
    }
    cout << ans << "\n";
    return 0;
}