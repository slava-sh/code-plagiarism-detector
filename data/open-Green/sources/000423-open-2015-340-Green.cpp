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

ll solve(ll curn, ll curk) {
    if (curk == 1ll) return (curn + 1ll) / 2ll;
    for (ll i = 2ll; (i * i) <= curn; ++i) {
        if (curn % i == 0ll) return solve(curn / i, curk - 1ll) * ((i + 1ll) / 2ll);
    }
    return (curn + 1ll) / 2ll;
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    cin >> n >> k;
    cout << solve(n, k);

    return 0;
}
