#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define ss second
#define ff first

const ll maxn = 100000;
const ll maxseg = 8192;
const ll inf = 4611686018427387904;
const double pi = 3.141592653589793238462643383279502884;
const double eps = 1e-9;
const double inff = 1e100;

ll seg[maxseg * 2 + 1];

ll summ(ll v, ll l, ll r, ll L, ll R)
{
	if ((L >= l) && (R <= r))
		return seg[v];
	if ((L > r) || (R < l))
		return 0;
	return summ(v * 2, l, r, L, (L + R) / 2) + summ(v * 2 + 1, l, r, (L + R) / 2 + 1, R);
}

void init(ll n, ll k)
{
	ll cur = n + maxseg;
	seg[cur] = k;
	while (cur != 0)
	{
		cur /= 2;
		seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
	}
	return;
}

ll sum(int l, int r)
{
	return summ(1, l, r, 0, maxseg - 1);
}

ll a[maxn];

ll bad(ll n)
{
	for (int i = 0; i < 2 * maxseg + 1; ++i)
		seg[i] = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += sum(a[i], n);
		init(a[i], 1);
	}
	return ans;
}

int main()
{
	cin.sync_with_stdio(0);
	ll n, mostbad = -1, mostn, mostbad2 = -1, mostn2;
	cin >> n;
	ll cur = inf;
	pair<ll, ll> ans = make_pair(-2, -2);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		--a[i];
	}
	cur = bad(n);
	bool f = true;
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] > a[i + 1])
			f = false;
	}
	if (f)
	{
		cout << -1 << ' ' << -1;
		return 0;
	}
	for (int i = 0; i < 2 * maxseg + 1; ++i)
		seg[i] = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sum(a[i], n) > mostbad)
		{
			mostn = i;
			mostbad = sum(a[i], n);
		}
		init(a[i], 1);
	}
	for (int i = 0; i < 2 * maxseg + 1; ++i)
		seg[i] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (sum(0, a[i]) == mostbad2)
		{
			mostbad2 = sum(0, a[i]);
			if (a[mostn2] < a[i])
				mostn2 = i;
		}
		if (sum(0, a[i]) > mostbad2)
		{
			mostn2 = i;
			mostbad2 = sum(0, a[i]);
		}
		init(a[i], 1);
	}
	if (mostbad == -1)
	{
		cout << -1 << ' ' << -1;
		return 0;
	}
	cout << mostn2 + 1 << ' ' << mostn + 1;
	return 0;
	for (int i = 0; i < n; ++i)
		{
			for (int i = 0; i < 2 * maxseg + 1; ++i)
				seg[i] = 0;
			ll badd;
			
			if (badd < cur)
			{
				ans = make_pair(i, mostn);
				cur = badd;
			}
		}
	cout << ans.ff + 1 << ' ' << ans.ss + 1;
	return 0;
}