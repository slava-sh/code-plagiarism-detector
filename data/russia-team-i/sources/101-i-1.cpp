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

#define FILE "sochi"

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

int n, d;
vector<int> a;
int cnt, sum, fstMax, sndMax, totMax, ans;

int main() {
#ifdef HAKU
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        if (a[i] >= 3 * d) {
            sum += a[i], ++cnt;
        } else if (a[i] >= 2 * d) {
            if (a[i] > fstMax) {
                sndMax = fstMax;
                fstMax = a[i];
            } else if (a[i] > sndMax) {
                sndMax = a[i];
            }
        }
        totMax = max(totMax, a[i]);
    }
    if (fstMax)
        sum += fstMax, ++cnt;
    if (sndMax)
        sum += sndMax, ++cnt;
    if (cnt == 0)
        ans = totMax;
    else
        ans = max(sum - 2 * (cnt - 1) * d, totMax);

    cout << ans << "\n";
    return 0;
}
