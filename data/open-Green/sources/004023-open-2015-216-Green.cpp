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

ll pr[N], k, n;
bool used[LIM + 10];
vector <ll> prime, dvs;
int lim;

void gen(int c, bool take, ll d) {
    if (c == lim) {
        dvs.push_back(d);
        return;
    }
    gen(c + 1, false, d);
    if (c == 0 || (c != 0 && prime[c - 1] != prime[c])) {
        gen(c + 1, true, d * prime[c]);
    } else
    if (take) {
        gen(c + 1, true, d * prime[c]);
    }
}

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
    ll n, k;
    cin >> n >> k;
    ll help = n;
    int i = 1;
    while (pr[i] * pr[i] <= help) {
        while (help % pr[i] == 0) {
            prime.push_back(pr[i]);
            help /= pr[i];
        }
        i++;
    }
    if (help != 1) {
        prime.push_back(help);
    }
    lim = prime.size();
    gen(0, false, 1);
    /*
    cout << "SIZE " << dvs_size << "\n";
    for (int i = 0; i < dvs_size; i++) {
        cout << dvs[i] << " ";
    }
    cout << "\n"
    */
    sort(dvs.begin(), dvs.end());
    int dvs_size = dvs.size();
    ll ans = 1;
    while (k != 0) {
        if (k == 1) {
            ans *= (n + 1) / 2;
            break;
        }
        if (n % 2 == 0) {
            n /= 2;
            k--;
            continue;
        }
        ll x = (pow(n, 1.0 / k) + 1);
        int l = 0, r = dvs_size;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (dvs[mid] <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        while (n % dvs[l] != 0) {
            l--;
        }
        ll z = dvs[l];
        ans *= (z + 1) / 2;
        n /= z;
        k--;
    }
    cout << ans << "\n";//}
    return 0;
}