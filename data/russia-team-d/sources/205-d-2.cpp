#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
vector <ll> mas;

ll k;
bool Check(ll s)
{
	ll r = 0;
	for (int i = 0; i < mas.size(); i++)
	{
		r = max(r + s, mas[i]);
		if (s > mas[i])
			return false;
	}
	if (r <= k)
		return true;
	return false;
}
int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	ll n;
	cin >> n >> k;
	mas.resize(n);
	for (int i = 0; i < n; i++)
		cin >> mas[i];
	sort(mas.begin(), mas.end());
	ll l = 0, r = k + 1;
	while (l + 1 < r)
	{
		ll s= (l + r) / 2;
		if (Check(s))
			l = s;
		else
		    r = s;
	}
	cout << l;
	return 0;
}