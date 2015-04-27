#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

#define FILENAME ""

int m;
int n;

int col[600];
int table[600][600];
int mod;

inline ll get(int x, int y) {
    if (!y)
        re 1;

    ll ans = x;
    if (y > 1) {
        ans *= (x - 1);
        ans /= 2;
    }

    re ans;
}

int getans(int k, int c1) {
    if (k == 0)
        re c1 == 0;

    if (c1 % 2 || c1 > 2 * k)
        re 0;

    int &ans = table[k][c1];
    if (ans != -1)
        re ans;

    ans = 0;
    int c0 = (2 * k - c1) / 2;

//    cout << "c0 = " << c0 << endl;

    for (int z1 = 0; z1 <= 2; z1++) {
        int z0 = 2 - z1;
        if (z1 > c1 || z0 > c0)
            continue;
        int nc1 = c1 - z1 + z0;

        ans += (get(c1, z1) * get(c0, z0) * getans(k - 1, nc1)) % mod;
        if (ans >= mod)
            ans -= mod;
    }

//    cout << k << ' ' << c1 << ' ' << ans << endl;

    re ans;
}

int main() {

#ifdef LOCAL_BOBER
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    cin >> n >> m >> mod;
    rep(i, m) {
        string s;
        cin >> s;
        rep(j, n) {
            if (s[j] == '1')
                col[j]++;
        }
    }

    int c1 = count(col, col + n, 1);

    fill(table, -1);
    cout << getans(n - m, c1) << endl;

    re 0;
}
