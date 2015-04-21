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
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    int n;
    cin >> n;
    vi a(n);
    int k = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        if (a[i] != a[i - 1])
            k++;
    k++;
    int q;
    cin >> q;
    while (q--) {
        int p, x;
        cin >> p >> x;
        p--;
        if (a[p] == x) {
            cout << k << endl;
            continue;
        }
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (p == 0) {
            if (a[0] == a[1])
                k++;
            else
                if (a[1] == x)
                    k--;
        } else
            if (p == n - 1) {
                if (a[n - 1] == a[n - 2])
                    k++;
                else
                    if (a[n - 2] == x)
                        k--;
            } else
                if (a[p - 1] == a[p + 1]) {
                    if (a[p] == a[p - 1])
                        k += 2;
                    else
                        if (a[p - 1] == x)
                            k -= 2;
                } else
                    if (a[p] != a[p - 1] && a[p] != a[p + 1]) {
                        if (a[p - 1] == x || a[p + 1] == x)
                            k--;
                    } else
                        if (a[p - 1] != x && a[p + 1] != x)
                            k++;
        a[p] = x;
        cout << k << endl;
    }
    return 0;
}
