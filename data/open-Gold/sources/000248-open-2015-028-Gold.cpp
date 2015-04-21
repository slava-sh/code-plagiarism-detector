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
const ll INFll = 1ll * INF * INF;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    int n, k, c, d;
    cin >> n >> k >> c >> d;
    vector<pii> a(n);
    vi b(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i].F >> a[i].S;
    for (int i = 0; i < n - 1; ++i)
        b[i] = a[i + 1].F - a[i].S;
    sort(b.rbegin(), b.rend());
    ll ans;
    ll cur = 1;
    ll s = 0;
    s = 1ll * (a.back().S - a[0].F) * d;
    ans = s;
    for (int i = 0; i < n - 1; ++i) {
        cur++;
        if (cur == k + 1)
            cur = 1, s += c;
        s -= 1ll * b[i] * d;
        ans = min(ans, s);
    }
    cout << ans;
    return 0;
}
