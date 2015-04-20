#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define pb push_back;
#define rs resize;
#define inf 1e9;

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long long ll;
typedef vector<ll> vl;

bool f(ll x, vl &a, ll n, ll k)
{
	ll s = a[0];
	for (ll i = 1; i < n; ++i)
		s = max(s + x, a[i]);
	return s <= k;
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	ll n;
	ll k;
	cin >> n >> k;
	vl a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll l = 0, r = a[0];
	while (l < r)
	{
		ll m = (l + r) / 2 + 1;
		if (f(m, a, n, k))
			l = m;
		else
			r = m - 1;
	}
	cout << l;
	return 0;
}