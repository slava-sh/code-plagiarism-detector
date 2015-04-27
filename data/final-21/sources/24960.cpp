#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <ctime>
#include <queue>

using namespace std;

typedef long long i64;
const int N = 2 * 100 * 1000;
i64 pw[N];

void init()
{
	pw[0] = 1;
	for (int i = 1; i < N; ++i)
			pw[i] = pw[i - 1] * 29;
}

i64 h[N], revh[N];
int n;

void calc(string s)
{
	for (int i = 0; i < n; ++i)
	{
		h[i] = pw[i] * (s[i] - 'a');
		if (i)
			h[i] += h[i - 1];
	}
	for (int i = n - 1; i >= 0; --i)
	{
		revh[i] = pw[n - i - 1] * (s[i] - 'a');
		if (i < n - 1)
				revh[i] += revh[i + 1];
	}
}

i64 geth(int l, int r)
{
	return (h[r] - (l ? h[l - 1] : 0)) * pw[N - r - 1];
}

i64 getrevh(int l, int r)
{
	int pow = n - l - 1;
	return (revh[l] - (r == n - 1 ? 0 : revh[r + 1])) * pw[N - pow - 1];
}

int solve(string s)
{
	s = s + s;
	n = s.length();
	calc(s);
	for (int i = 0; i <= n / 2; ++i)
			if (geth(i, i + n / 2 - 1) == getrevh(i, i + n / 2 - 1))
					return i;
	return -1;
}

int main()
{
	freopen("inventory.in", "r", stdin);
	freopen("inventory.out", "w", stdout);

	int t;
	cin >> t;

	init();

	for (int i = 0; i < t; ++i)
	{
		string s;
		cin >> s;
		cout << solve(s) << "\n";
	}

	return 0;
}
