#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define foreach(i, q) for (typeof(q.begin()) i = q.begin(); i != q.end(); ++i)

#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = int(1e9);
const int MOD = INF + 7;

ll gans(vector<ll>& a, ll N) {
    ll ans = 1;
    for (int i = 0; i < a.size(); ++i)
        ans *= (a[i] + 1) / 2;
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ll n;
    int k;
    cin >> n >> k;
    vi a;
    int d = 2;
    ll N = n;
    while (1ll * d * d <= n) {
        while (n % d == 0)
            a.pb(d), n /= d;
        d += 2 - (d == 2);
    }
    if (n > 1)
        a.pb(n);
    vector<ll> res(k, 1);
    for (int i = 0; i < min(k - 1, (int)a.size()); ++i)
        res[i] = a[i];
    for (int i = k - 1; i < a.size(); ++i)
        res[k - 1] *= a[i];
    cout << gans(res, N);
    return 0;
}
