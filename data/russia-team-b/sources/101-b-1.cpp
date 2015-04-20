#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

#define FILE "che"

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const int MAXN = 300 * 1000 + 5;
pair<int, char> a[3 * MAXN];

int main() {
#ifdef HAKU
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int n, r;
    cin >> n >> r;
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        a[3 * i] = mp(d - r, 0);
        a[3 * i + 1] = mp(d, 1);
        a[3 * i + 2] = mp(d + r, 2);
    }
    sort(a, a + 3 * n);
    int k = 0;
    ll ans = 0;
    for(int i = 0; i < 3 * n; i++)
        if(a[i].se == 0)
            ans -= k;
        else if(a[i].se == 1)
            k++;
        else
            ans += k;
    ans -= n;
    cout << (n * (n - 1) - ans) / 2 << '\n';
    return 0;
}
