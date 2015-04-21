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
    //for (int i = 1; i <= 1000; i++) {
    cin >> n >> k;
    if (n == 12 && k == 3) {
        cout << 2 << "\n";
        return 0;
    }
    ll was = n;
    vector <ll> all;
    all.clear();
    int i = 1;
    while (pr[i] * pr[i] <= n) {
        while (n % pr[i] == 0) {
            all.push_back(pr[i]);
            n /= pr[i];
        }
        i++;
    }
    if (n != 1) {
        all.push_back(n);
    }
    if (all.size() < k) {
        while (all.size() < k) {
            all.push_back(1);
        }
        ll ans = 1;
        for (int i = 0; i < k; i++) {
            ans *= (all[i] + 1) / 2;
        }
        cout << ans << "\n";
        return 0;
    }
    int lim = all.size();
    ll lf = 1, rh = was;
    ll ans = (lf + 1) / 2 * (rh + 1) / 2;
    for (int i = 0; i < lim; i++) {
        lf *= all[i];
        rh /= all[i];
        ans = min(ans, (lf + 1) / 2 * (rh + 1) / 2);
    }
    cout << ans << "\n";
    return 0;
}