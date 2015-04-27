#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;

int n, m, t[100100], r[100100], a[100100];
bool ans[100100], inf[100100];

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	int fs = n + 10;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> t[i] >> r[i]; t[i]--;
		if (r[i] == 1) fs = min(fs, i);
	}
	if (fs == n + 10)
	{
		int nons = 0;
		for (int i = 0; i < n - 1; i++)
			if (t[i] >= 0) a[t[i]]--;
			else nons++;
		for (int i = 0; i < m; i++)
			if (a[i] <= nons) cout << 'Y';
			else cout << 'N';
	}
	else
	{
		int nons = 0;
		for (int i = 0; i < fs; i++)
			if (t[i] >= 0) a[t[i]]--;
			else nons++;
		fill(ans, ans + m, false);
		fill(inf, inf + m, false);
		for (int i = fs; i < n - 1; i++)
			if (t[i] >= 0) inf[t[i]] = true;
		int mnv = 1000000000;
		for (int i = 0; i < m; i++)
			if (!inf[i] && a[i] <= nons)
			{
				ans[i] = true;
				if (a[i] < mnv) mnv = a[i];
			}
		nons -= mnv;
		for (int i = fs; i < n - 1; i++)
			if (t[i] >= 0) a[t[i]]--;
			else nons++;
		for (int i = 0; i < m; i++)
			if (!ans[i] && a[i] <= nons) ans[i] = true;
		for (int i = 0; i < m; i++)
			if (ans[i]) cout << 'Y';
			else cout << 'N';
	}
	cout << endl;
}

int main()
{
	int tst;
	cin >> tst;
	for (int test = 0; test < tst; test++)
		solve();
}