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
const ll maxseg = 131072;
const ll inf = 4611686018427387904;
const double pi = 3.141592653589793238462643383279502884;
const double eps = 1e-9;
const double inff = 1e100;

ll t[maxn];
ll n, a[maxn];

ll ssum(int r)
{
	ll result = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		result += t[r];
	return result;
}

void inc(int i)
{
	for (; i < n; i = (i | (i + 1)))
		++t[i];
}

ll sum(int l, int r)
{
	return ssum(r - 1) - ssum(l);
}

ll bad()
{
	for (int i = 0; i < n; ++i)
		t[i] = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += sum(a[i], n);
		inc(a[i]);
	}
	return ans;
}

int main()
{
	cin.sync_with_stdio(0);
	cin >> n;
	ll cur = inf;
	pair<ll, ll> ans = make_pair(-2, -2);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cur = bad();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			ll badd;
			swap(a[i], a[j]);
			badd = bad();
			if (badd < cur)
			{
				ans = make_pair(i, j);
				cur = badd;
			}
			swap(a[i], a[j]);
		}
	cout << ans.ff + 1 << ' ' << ans.ss + 1;
	return 0;
}