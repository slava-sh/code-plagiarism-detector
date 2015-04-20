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

int n, d;

int main()
{
	freopen("sochi.in", "rt", stdin);
	freopen("sochi.out", "wt", stdout);
	
	int n, d;
	cin >> n >> d;
	vector<int> a;
	int res = 0;
	int ans = 0;
	forn(i, n)
	{
		int tmp;
		cin >> tmp;
		if (tmp >= 3 * d)
		{
			if (res != 0)
				res -= 2 * d;
			res += tmp;
		}
		else if (tmp >= 2 * d)
			a.pb(tmp);
		ans = max(ans, tmp);
	}
	sort(a.rbegin(), a.rend());
	if (sz(a) > 0)
		res += (a[0] - 2 * d);
	if (sz(a) > 1)
		res += (a[1] - 2 * d);
	cout << max(ans, res);
}