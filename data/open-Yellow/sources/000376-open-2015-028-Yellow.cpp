#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif // LOCAL
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int q;
    cin >> q;
    while (q--) {
        int p, x;
        cin >> p >> x;
        a[p - 1] = x;
        int k = 1;
        for (int i = 1; i < n; ++i)
            k += (a[i] != a[i - 1]);
        cout << k << endl;
    }
    return 0;
}
