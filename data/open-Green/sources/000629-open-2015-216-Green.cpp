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
const int N = 3000000;

ll pr[N], mas[100], k;
bool used[LIM + 10];

ll count_res(int x, ll n) {
    if (x > k) {
        return ((n + 1) / 2);
    }
    ll gg = count_res(x + 1, n / mas[x]);
    return ((mas[x] + 1) / 2) * gg;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    scanf("%lld %lld", &n, &k);
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
    while (all.size() < k) {
        all.push_back(1);
    }
    for (int i = 1; i < k; i++) {
        mas[i] = all[i - 1];
    }
    int lim = all.size();
    mas[k] = 1;
    for (int i = k; i <= lim; i++) {
        mas[k] *= all[i - 1];
    }
    printf("%lld\n", count_res(1, was));
    return 0;
}