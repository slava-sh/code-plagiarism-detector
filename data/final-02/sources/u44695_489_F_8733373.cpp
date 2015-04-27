#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define ll long long

ll mod;
vector<ll> c(510), a(5);
map<vector <ll>, ll> mp[510];

ll solve(ll m, ll n) {
    if(m > n)
        return 1;
    if(mp[m].find(a) != mp[m].end())
        return mp[m][a];
    ll ans(0), x;
    if(a[0] >= 2) {
        a[0] -= 2;
        a[1] += 2;
        x = solve(m + 1, n);
        a[0] += 2;
        a[1] -= 2;
        ans = (ans + x * (a[0] * (a[0] - 1) / 2)) % mod;
    }
    if(a[1] >= 2) {
        a[1] -= 2;
        a[2] += 2;
        x = solve(m + 1, n);
        a[1] += 2;
        a[2] -= 2;
        ans = (ans + x * (a[1] * (a[1] - 1) / 2)) % mod;
    }
    if(a[0] >= 1 && a[1] >= 1) {
        a[0]--;
        a[2]++;
        x = solve(m + 1, n);
        a[0]++;
        a[2]--;
        ans = (ans + x * (a[0] * a[1])) % mod;
    }
    mp[m][a] = ans;
    return ans;
}


int main() {
//    freopen("1cf.txt", "r", stdin);
    ll n, m, i, j;
    cin >> n >> m >> mod;
    for(i = 1; i <= m; i++)
    for(j = 1; j <= n; j++) {
        char x;
        cin >> x;
        if(x == '1')
            c[j]++;
    }
    for(i = 1; i <= n; i++)
        a[c[i]]++;
//    for(i = 0; i <= 2; i++)
//        cout << a[i] << ' ';
//cout << "\n";
    cout << solve(m + 1, n);
    return 0;
}
