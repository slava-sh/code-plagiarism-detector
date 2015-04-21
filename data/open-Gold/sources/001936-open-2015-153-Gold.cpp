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

int main()
{
	cin.sync_with_stdio(0);
	ll n, k, c, d, a[maxn], b[maxn], e[maxn], ans = 0, ans2, vk, best = inf;
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
	for (int i = 0; i <= n / k + 1; ++i)
	{
		ans = ans2;
		vk = (i + 1) * k - 1;
		for (int j = 0; j <= n - 2 - vk; ++j)
			ans += e[j] * d;
		ans += c * i;
		if (ans < best)
			best = ans;
	}
	cout << best;
	return 0;
}