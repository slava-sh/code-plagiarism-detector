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

int main()
{
	freopen("che.in", "rt", stdin);
	freopen("che.out", "wt", stdout);

	int n, R;
	cin >> n >> R;
	vector<int> a(n);
	forn(i, n)
		cin >> a[i];
	ll ans = 0;
	int r = 0;
	for (int l = 0; l < n; l++)
	{
		while (r < n && a[r] - a[l] <= R)
			r++;
		ans += ll(n - r);
	}
	cout << ans;
}