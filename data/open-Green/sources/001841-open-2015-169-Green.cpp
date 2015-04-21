#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;

vector<int> mults;

void gen_mults(ll x)
{
    int cur = 2;
    while(x > 1 && cur * cur <= x)
    {
        while(x % cur == 0)
        {
            mults.pb(cur);
            x /= cur;
        }
        cur++;
    }
    if(x > 1)
        mults.pb(x);
}

ll dp[11][55];
const ll INF = (1000 * 1000 * 1000ll) * (1000 * 1000 * 1000ll);
ll pref[55];

ll get_mult(int l, int r)
{
    if(l <= r)
        return pref[r + 1] / pref[l];
    else
        return 1;
}

void solve(int k)
{
    for(int i = 0; i <= k; i++)
        for(int j = 0; j < 55; j++)
            dp[i][j] = INF;
    dp[0][0] = 1;

    for(int pos = 0; pos < k; pos++)
        for(int used = 0; used <= mults.size(); used++)
            for(int to_use = 0; used + to_use <= mults.size(); to_use++)
            {
                ll inc = get_mult(used, used + to_use - 1);
                if(inc & 1)
                    inc = inc / 2 + 1;
                else
                    inc = inc / 2;
                dp[pos + 1][used + to_use] = min(dp[pos + 1][used + to_use],
                                                 dp[pos][used] * inc);
            }
    cout << dp[k][mults.size()] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n;
    int k;
    cin >> n >> k;

    gen_mults(n);

    pref[0] = 1;
    for(int i = 1; i <= mults.size(); i++)
        pref[i] = pref[i - 1] * mults[i - 1];

    solve(k);

    return 0;
}
