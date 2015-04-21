#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n,k;

map<ll, int> mp[15];

ll solve(ll curn, ll curk) {
    if (curk == 1ll) return (curn + 1ll) / 2ll;
    if (!mp[curk][curn]) {
        ll curans = (curn + 1ll) / 2ll;
        for (ll i = 2ll; (i * i) <= curn; ++i) {
            if (curn % i == 0ll) {
                curans = min(curans, solve(curn / i, curk - 1ll) * ((i + 1ll) / 2ll));
                curans = min(curans, solve(i, curk - 1ll) * (((curn / i) + 1ll) / 2ll));
            }
        }
        mp[curk][curn] = curans + 1ll;
    }
    return mp[curk][curn] - 1ll;
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    cin >> n >> k;
    cout << solve(n, k);

    return 0;
}
