#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define inf 2000000000

typedef long long ll;
typedef unsigned long long ull;

int n, m, j, i, h, q, qq, q1, q2, a[501], cur;
ll d[2][501][501], mod;
char buf[510];

inline bool check(int two, int one, int null, int str)
{
	return (two + one + null == n) && (two * 2 + one == str * 2);
}

void solve()
{
	scanf ("%d%d%I64d", &n, &m, &mod);
	for (j = 1; j <= m; j++)
	{
		scanf ("%s", &buf);
		for (i = 0; i < n; i++)
		{
			if (buf[i] == '1')
			{
				a[i + 1]++;
			}
		}
	}
	for (j = 1; j <= n; j++)
	{
		if (!a[j])
		{
			q1++;
		}
		if (a[j] == 1)
		{
			q2++;
		}
	}
	d[0][q1][q2] = 1LL;
	for (j = m + 1; j <= n; j++)
	{
		cur = 1 - cur;
		q1 = max(0, n - ((j) << 1));
		q2 = n - j;
		for (i = q1; i <= q2; i++)
		{
			qq = (n - i - ((j << 1) - (n - i)));
			d[cur][i][qq] = 0LL;
			if (qq >= 2)
			{
				if (check(n - qq - i, qq - 2, i + 2, j - 1))
				{
					d[cur][i][qq] += d[1 - cur][i + 2][qq - 2] * ((ll)(i + 2) * (ll)(i + 1) / 2LL);
					d[cur][i][qq] %= mod;
				}
			}
			if (qq >= 1 && (n - qq - i) >= 1)
			{
				if (check(n - qq - i - 1, qq, i + 1, j - 1))
				{
					d[cur][i][qq] += d[1 - cur][i + 1][qq] * ((ll)(i + 1) * (ll)(qq));
					d[cur][i][qq] %= mod;
				}
			}
			if ((n - qq - i) >= 2)
			{
				if (check(n - qq - i - 2, qq + 2, i, j - 1))
				{
					d[cur][i][qq] += d[1 - cur][i][qq + 2] * ((ll)(qq + 2) * (ll)(qq + 1) / 2LL);
					d[cur][i][qq] %= mod;
				}
			}
		}
	}
	printf ("%I64d\n", d[cur][0][0]);
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
	srand(33333);
	solve();
	return 0;
}
