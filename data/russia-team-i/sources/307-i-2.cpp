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
typedef vector <ll> vl;

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	ll n, d;
	cin >> n >> d;
	vl a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	if (n == 1)
	{
		cout << a[0];
		return 0;
	}
	bool ind = 0;
	int f = -1;
	ll ans = 0;
	ll k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 3 * d)
		{
			k++;
			ans+= a[i];
			if (!ind)
			{
				f = i;
				ind = 1;
			}
		}
	}
	if (f >= 2)
	{
		if (a[f - 1] >= 2 * d  && a[f - 2] >= 2 * d)
		{
			ans+= a[f - 1];
			ans+= a[f - 2];
			k += 2;
		}
		if (a[f - 1] >= 2 * d && a[f - 2] < 2 * d)
		{
			ans+= a[f - 1];
			k++;
		}
	}
	if (f == 1)
	{
		if (a[0] >= 2 * d)
		{
			ans+= a[0];
		    k++;
		}
	}
	if (f == -1)
	{
		if (a[n - 1] + a[n - 2] - 2 * d >= a[n - 1])
			cout << a[n - 1] + a[n - 2] - 2 * d;
		else
			cout << a[n - 1];
		return 0;
	}
	k--;
	cout << ans - 2 * d * k;
	return 0;
}