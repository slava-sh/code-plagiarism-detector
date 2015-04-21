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
ll n, k, c, d;
ll a[MAXN], b[MAXN];
ll mas[MAXN];
ll pref[MAXN];
ll res;

/*
    if (n - amount) % k == 0:
        x = (n - amount) // k - 1
    else:
        x = (n - amount) // k        
    curr = c * x
    for j in range(amount):
        curr += d * mas[j]
*/
ll check(ll amount)
{
	ll x;
    if ((n - amount) % k == 0)
        x = (n - amount) / k - 1;
    else
        x = (n - amount) / k;        
    return c * x + d * pref[amount - 1];
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%lld%lld%lld%lld", &n, &k, &c, &d);
	
	for (ll i = 0; i < n; i++)
	{
		scanf("%lld%lld", &a[i], &b[i]);
		res += d * (b[i] - a[i]);
	}
	
	for (ll i = 0; i < n - 1; i++)
	{
		mas[i] = a[i + 1] - b[i];
		pref[i] = (i == 0 ? 0 : pref[i - 1]) + mas[i];
	}

	sort(mas, mas + n - 1);
	
	ll ans = res + check(0);

	for (ll i = 0; i < n; i++)
		ans = min(ans, res + check(i));
	
	printf("%lld", ans);
	return 0;
}