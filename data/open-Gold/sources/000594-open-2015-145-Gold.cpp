#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef long long ll;

const ll nmax = 220000;

ll a[nmax], b[nmax], t[nmax], sum[nmax];
ll n, k, c, d;


void read()
{
    fin >> n >> k >> c >> d;
    for (ll i = 0; i < n; i++)
        fin >> a[i] >> b[i];
}


void solve()
{
    for (ll i = 1; i < n; i++)
        t[i] = a[i] - b[i - 1];
    sort(t + 1, t + n);
    reverse(t + 1, t + n);
    sum[1] = (b[n - 1] - a[0]) * d;
    ll ans = sum[1];
    for (ll i = 2; i <= n; i++)
    {
        sum[i] = sum[i - 1] - d * t[i - 1];
        if ((i + 1) % k == 0)
            sum[i] += c;
        ans = min(ans, sum[i]);
    }
    fout << ans << endl;
}


int main()
{
    read();
    solve();
    return 0;
}
