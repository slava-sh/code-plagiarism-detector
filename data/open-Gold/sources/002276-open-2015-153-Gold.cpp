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

const ll maxn = 3001;
const ll maxseg = 131072;
const ll inf = 4611686018427387904;
const double pi = 3.141592653589793238462643383279502884;
const double eps = 1e-9;
const double inff = 1e100;

ll MAX(ll a, ll b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	cin.sync_with_stdio(0);
	ll n, k, c, d, a[maxn], b[maxn], e[maxn], ans = 0, ans2, ans3, vk, best = inf, right, left, mid1, mid2;
	bool f[maxn];
	cin >> n >> k >> c >> d;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i];
		ans += (b[i] - a[i]) * d;
	}
	ans2 = ans;
	for (int i = 0; i < n - 1; ++i)
		e[i] = a[i + 1] - b[i];
	sort(e, e + n - 1);
	right = n / k + 1;
	left = 0;
	while (right - left > 2)
	{
		mid1 = (right - left) / 3 + left;
		mid2 = right - (right - left) / 3;
		ans2 = ans;
		ans3 = ans;
		vk = (mid1 + 1) * k - 1;
		for (int j = 0; j <= n - 2 - vk; ++j)
			ans2 += e[j] * d;
		ans2 += c * mid1;
		vk = (mid2 + 1) * k - 1;
		for (int j = 0; j <= n - 2 - vk; ++j)
			ans3 += e[j] * d;
		ans3 += c * mid2;
		if (ans2 < ans3)
			right = mid2;
		else
			left = mid1;
	}
	for (int i = MAX(left - 1, 0); i < left + 3; ++i)
	{
		ans2 = ans;
		vk = (i + 1) * k - 1;
		for (int j = 0; j <= n - 2 - vk; ++j)
			ans2 += e[j] * d;
		ans2 += c * i;
		if (ans2 < best)
			best = ans2;
	}
	cout << best;
	return 0;
}