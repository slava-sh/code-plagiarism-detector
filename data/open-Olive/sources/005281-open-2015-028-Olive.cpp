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

short bl[5001][5001], br[5001][5001], sl[5001][5001], sr[5001][5001];

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
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
            br[i][j] = br[i][j - 1] + (a[j] > a[i]), sr[i][j] = sr[i][j - 1] + (a[j] < a[i]);
        for (int j = i - 1; j >= 0; --j)
            sl[i][j] = sl[i][j + 1] + (a[j] < a[i]), bl[i][j] = bl[i][j + 1] + (a[j] > a[i]);
    }
    int ans = 0, a1 = -2, a2 = -2;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int tmp = -br[i][j] + sr[i][j] + bl[j][i] - sl[j][i];
            if (tmp > ans)
                ans = tmp, a1 = i, a2 = j;
        }
    }
    cout << a1 + 1 << " " << a2 + 1;
    return 0;
}
