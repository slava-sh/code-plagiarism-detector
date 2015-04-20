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

#define FILE "fence"

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], n, k;

bool test(int x) {
    int p = 0;
    for(int i = 0; i < n; i++) {
        int rep = min(p, a[i] - x);
        p += a[i] - rep;
        if(p > k)
            return false;
    }
    return true;
}

int main() {
#ifdef HAKU
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int l = 0, r = INF;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        r = min(r, a[i]);
    }
    r++;
    sort(a, a + n);
    while(l < r - 1) {
        int m = (l + r) / 2;
        if(test(m))
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
    return 0;
}
