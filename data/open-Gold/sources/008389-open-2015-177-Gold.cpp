#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 200500;
typedef long long ll;
const ll INF = 1e18;
ll n, k, c, d, m;
ll a[MAXN], b[MAXN];
ll mas[MAXN];
ll pref[MAXN];
ll res;

ll check(ll amount)
{
	return c * ((n - amount) / k - 1 + (bool)((n - amount) % k)) + d * pref[amount - 1]; 
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%lld%lld%lld%lld", &n, &k, &c, &d);
	
	m = n - 1;
	for (ll i = 0; i < n; i++)
	{
		scanf("%lld%lld", &a[i], &b[i]);
		res += d * (b[i] - a[i]);
	}

	if (n == 1)
	{
		cout << d * (b[0] - a[0]);
		return 0;
	}

	for (ll i = 0; i < m; i++)
	{
		mas[i] = a[i + 1] - b[i];
		pref[i] = (i == 0 ? 0 : pref[i - 1]) + mas[i];
	}

	sort(mas, mas + m);

	ll r = n - 1;
    ll l = 0;
    while (r - l > 2)
	{
        ll mid1 = l + (r - l) / 3;
        ll mid2 = l + ((r - l) / 3) * 2;

        if (check(mid1) < check(mid2))
            r = mid2;
        else
            l = mid1;
	}

	ll ans = res + check(l);

	for (ll i = l; i <= r; i++)
	{
		ans = min(ans, res + check(i));
	}

	printf("%lld", ans);
	return 0;
}