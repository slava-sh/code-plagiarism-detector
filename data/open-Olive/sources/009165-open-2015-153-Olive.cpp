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

ll MIN(ll a, ll b)
{
	if (a < b)
		return a;
	return b;
}

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
	return (a > b);
}

int main()
{
	cin.sync_with_stdio(0);
	ll n;
	vector<pair<ll, ll>> mostn, mostn2;
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
		mostn.push_back(make_pair(sum(a[i], n),i));
		init(a[i], 1);
	}
	for (int i = 0; i < 2 * maxseg + 1; ++i)
		seg[i] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		mostn2.push_back(make_pair(sum(0, a[i]),i));
		init(a[i], 1);
	}
	sort(mostn.begin(), mostn.end(), comp);
	sort(mostn2.begin(), mostn2.end(), comp);
	ll badd;
	for (int i = 0; i < MIN(500, mostn.size()); ++i)
		for(int j = 0; j < MIN(500, mostn2.size()); ++j)
		{
			swap(a[mostn[i].ss], a[mostn2[j].ss]);
			badd = bad(n);
			if (badd < cur)
			{
				cur = badd;
				ans = make_pair(mostn[i].ss, mostn2[j].ss);
			}
			swap(a[mostn[i].ss], a[mostn2[j].ss]);
		}
	cout << ans.ff + 1 << ' ' << ans.ss + 1;
	return 0;
}