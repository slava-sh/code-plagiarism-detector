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
ll res;

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
	m = n - 1;

	for (ll i = 0; i < m; i++)
	{
		mas[i] = a[i + 1] - b[i];
	//	cout << mas[i] << ' ';
	}
	sort(mas, mas + m);
	ll ans = c * (n / k + (bool)n % k - 1) + res;

	for (ll amount = 0; amount < n; amount++)
	{
		ll curr = 0;
		for (ll j = 0; j < amount; j++)
		{
			curr += d * mas[j];
		}
		curr += c * ((n - amount) / k + (bool)(n - amount) % k - 1);
		ans = min(ans, curr + res);
 		//printf("%lld: %lld\n", amount, res + curr);
	}
	printf("%lld", ans);
	return 0;
}