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
ll n, k, c, d, m;
ll a[MAXN], b[MAXN];
ll mas[MAXN];
ll pref[MAXN];
ll res;

ll check(ll amount)
{
	return c * ((n - amount) / k - 1 + (bool)((n - amount) % k)) + d * (amount == 0 ? 0 : pref[amount - 1]); 
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
	
	for (ll i = 0; i < m; i++)
	{
		mas[i] = a[i + 1] - b[i];
		pref[i] = (i == 0 ? 0 : pref[i - 1]) + mas[i];
	}

	sort(mas, mas + m);
	
	ll ans = res + check(0);

	for (ll i = 0; i < m; i++)
		ans = min(ans, res + check(i));
	
	printf("%lld", ans);
	return 0;
}