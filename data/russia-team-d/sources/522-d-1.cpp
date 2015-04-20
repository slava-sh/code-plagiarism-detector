#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define sqr(x) ((x) * (x))
#define forn(i, n) for (int i = 0; i < n; i++)

vector<ll> a;
int n;
ll k;

bool can(ll x)
{
	ll r = a[0];
	for (int i = 1; i < n; i++)
	{
		r = max(a[i], r + x);
		if (r > k)
			return false;
	}
	return true;
}

int main()
{
	freopen("fence.in", "rt", stdin);
	freopen("fence.out", "wt", stdout);
	
	cin >> n >> k;
	a.resize(n);
	forn(i, n)
		cin >> a[i];
	sort(all(a));
	ll l = 0, r = a[0];
	while (l + 1 < r)
	{
		ll mid = (l + r) / 2;
		if (can(mid))
			l = mid;
		else 
			r = mid;
	}
	for (ll i = r; i >= l; i--)
		if (can(i))
		{
			cout << i;
			exit(0);
		}
}