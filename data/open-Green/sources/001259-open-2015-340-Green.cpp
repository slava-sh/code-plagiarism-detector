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
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n,k;
map<ll, ll> mp[15];

ll fact[10005],divrs[1100105];
int factn[10005],facti, divri;

void factorize(ll num) {
    for (ll i = 2ll; (i * i) <= num; ++i) {
        if (num % i == 0ll) {
            fact[facti] = i;
            while (num % i == 0ll) { ++factn[facti]; num /= i; }
            ++facti;
        }
    }
    if (num != 1ll) {
        fact[facti] = num;
        factn[facti] = 1;
        ++facti;
    }
}

void brute(ll curnum, int curidx, int curcnt) {
    if (curnum != 1ll) divrs[divri++] = curnum;
    if (curidx < facti) {
        if (curcnt < factn[curidx]) brute(curnum * fact[curidx], curidx, curcnt + 1);
        brute(curnum, curidx + 1, 0);
    }
}

ll solve_old(ll curn, ll curk) {
    if (curk == 1ll) return (curn + 1ll) / 2ll;
    if (!mp[curk][curn]) {
        ll curans = (curn + 1ll) / 2ll;
        for (ll i = 2ll; (i * i) <= curn; ++i) {
            if (curn % i == 0ll) {
                curans = min(curans, solve_old(curn / i, curk - 1ll) * ((i + 1ll) / 2ll));
                curans = min(curans, solve_old(i, curk - 1ll) * (((curn / i) + 1ll) / 2ll));
            }
        }
        mp[curk][curn] = curans + 1ll;
    }
    return mp[curk][curn] - 1ll;
}

ll solve(ll curn, ll curk) {
    if (curk == 1ll) return (curn + 1ll) / 2ll;
    if (!mp[curk][curn]) {
        ll curans = (curn + 1ll) / 2ll;
        for (int i = 0; i < divri && (divrs[i] * divrs[i]) <= curn; ++i) {
            if (curn % divrs[i] == 0ll) {
                curans = min(curans, solve(curn / divrs[i], curk - 1ll) * ((divrs[i] + 1ll) / 2ll));
                curans = min(curans, solve(divrs[i], curk - 1ll) * (((curn / divrs[i]) + 1ll) / 2ll));
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
    factorize(n);
    brute(1ll, 0, 0);
    sort(divrs, divrs + divri);
    int m = 0;
    ll prev = -1ll;
    for (int i = 0; i < divri; ++i) {
        if (divrs[i] != prev)
            divrs[m++] = divrs[i];
        prev = divrs[i];
    }
    divri = m;

    cout << solve(n, k);
    ///cerr << endl;
    ///cerr << solve_old(n, k);

    return 0;
}
