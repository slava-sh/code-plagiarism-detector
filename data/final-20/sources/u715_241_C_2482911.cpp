#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <numeric>
typedef long long ll;
using namespace std;
const double eps = 1e-9;
typedef pair<int,int> pii;
const int MOD = 1000000007;

int i, j, k, m, n, hl, hr, ans;
int a[105], b[105], v[105], u[105];
char c[105];

void solve()
{
    for (i = 1; i <= n; i++)
    {
        int curr = 0;
        double y1 = hl;
        double y2;
        if (i % 2 == 0)
            y2 = hr + i * 100;
        else
            y2 = 100-hr + i * 100;

        for (j = 1; j <= n; j++)
            u[j] = 1;

        bool good = true;
        for (j = 1; j <= i; j++)
        {
            double y = 100 * j;
            double x = 100000.0 / (y2 - y1) * (y - y1);

            for (k = 1; k <= n; k++)
                if (c[k] == j%2 && a[k] - eps < x && x < b[k] + eps) break;
            if (k == n+1 || !u[k]) { good = false; break; }
            u[k] = 0;
            curr += v[k];
        }
        if (good)
        {
            ans = max(ans, curr);
            // cout << curr << endl;
        }
    }
}

int main() {
    // freopen("x.in", "r", stdin);
    cin >> hl >> hr >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i] >> c[i] >> a[i] >> b[i];
        c[i] = (c[i] == 'T');
    }
    solve();
    hl = 100-hl;
    hr = 100-hr;
    for (i = 1; i <= n; i++)
        c[i] = 1 - c[i];
    solve();
    cout << ans << endl;
    return 0;
} 
