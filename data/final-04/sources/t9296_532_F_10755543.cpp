#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <set>
#include <ctime>
#include <map>
#include <cstring>
#include <iterator>
#include <queue>
 
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define pldld pair<ld, ld>
#define mp make_pair
#define ull unsigned long long
#define pss pair<string, string>
#pragma comment(linker, "/STACK:64000000")
#define null NULL

const int infi = 1e9 + 7;
const ll infl = 1e18;
const long double eps = 1e-8;
const long double eps1 = 1e-10;
const int mod = (1e9 + 7);
const ll mod1 = (1e9 + 7);
const ll mod2 = 1e9 + 9;
const ll p1 = 31;
const ll p2 = 37;
const ll p3 = 29;
const int ver1 = (62 * 62);
const int maxm = 10000;
const int maxx = 1e9, maxy = 1e9;

string ar, arz;
pll hash1[200500];
pll st[200500];
pll sum[30];
int used[30];
int p[30];
int pos[30];
vector <int> res;

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("ant.in", "r", stdin); freopen("ant.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cin >> ar >> arz;
    st[0] = mp(1, 1);
    for (int i = 1; i <= n; ++i) {
        st[i] = st[i - 1];
        st[i].first *= p1;
        st[i].second *= p2;
        st[i].second %= mod2;
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            hash1[i] = hash1[i - 1];
        }
        hash1[i].first += st[i].first * (ll)(ar[i] - 'a' + 1);
        hash1[i].second += st[i].second * (ll)(ar[i] - 'a' + 1);
        hash1[i].second %= mod2;
    }
    for (int i = 0; i < 26; ++i) {
        pos[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        int j = arz[i] - 'a';
        pos[j] = i;
        sum[j].first += st[i].first;
        sum[j].second += st[i].second;
        sum[j].second %= mod2;
    }
    int ans = 0;
    for (int i = 0; i + m - 1 < n; ++i) {
        pll q = mp(0, 0);
        memset(used, 0, sizeof used);
        memset(p, 0, sizeof p);
        int flag = 0;
        for (int j = 0; j < 26; ++j) {
            if (pos[j] == -1) {
                continue;
            }
            ll k = ar[pos[j] + i] + 1 - 'a';
            if (used[j]) {
                if (k - 1 != p[j]) {
                    flag = 1;
                    break;
                }
            }
            else {
                if (used[k - 1]) {
                    flag = 1;
                    break;
                }
                used[k - 1] = used[j] = 1;
                p[j] = k -1;
                p[k - 1] = j;
            }
            q.first += k * st[i].first * sum[j].first;
            q.second += ((k * st[i].second) % mod2 ) * sum[j].second;
            q.second %= mod2;
        }
        if (flag) {
            continue;
        }
        pll w = hash1[i + m - 1];
        if (i) {
            w.first -= hash1[i - 1].first;
            w.second -= hash1[i - 1].second;
            w.second += mod2;
            w.second %= mod2;
        }
        if (w == q) {
            ++ans;
            res.push_back(i + 1);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        cout << res[i] << ' ';
    }

    return 0;
}