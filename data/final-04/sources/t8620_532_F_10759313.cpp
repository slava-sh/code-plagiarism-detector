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
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <complex>

using namespace std;

#define pb push_back
#define pii pair<int, int>
#define pdi pair<double, int>
#define pdii pair<pdi, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define psi pair<string, int>
#define vi vector<int>
#define inf 2000000000
//#define mod1 1000333
//#define mod 1000000123
#define y1 uhgeg
#define lim 31700
#define eps 1e-9
#define prime1 31
#define prime2 41

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> comp;

int n, j, i, h, k, q1, q2, q, mx, cur, l, d, m, para[26], cnt[200500];
char s[200500], t[200500];
vector<int> v;
ll st[200500], hsh[26], hsh0[26];
bool b[26];

bool check()
{
	for (int j = 0; j < 26; j++)
	{
		para[j] = -1;
	}
	for (int j = 0; j < 26; j++)
	{
		if (!b[j])
		{
			continue;
		}
		if (para[j] != -1)
		{
			continue;
		}
		int i = 0;
		for (i = 0; i < 26; i++)
		{
			if (hsh[i] == hsh0[j] && para[i] == -1)
			{
				if (b[i] && hsh0[i] != hsh[j])
				{
					continue;
				}
				para[i] = j;
				para[j] = i;
				break;
			}
		}
		if (i == 26)
		{
			return 0;
		}
	}
	return 1;
}

void init()
{
	scanf ("%d %d\n%s\n%s", &n, &m, &s, &t);
	for (j = m - 1; j >= 0; j--)
	{
		b[t[j] - 'a'] = 1;
	}
}

void solve(ll mod)
{
	st[0] = 1LL;
	for (j = 1; j <= 200100; j++)
	{
		st[j] = st[j - 1] << 1;
		if (st[j] >= mod)
		{
			st[j] -= mod;
		}
	}
	for (j = 0; j < 26; j++)
	{
		hsh[j] = hsh0[j] = 0LL;
	}
	for (j = m - 1; j >= 0; j--)
	{
		for (i = 0; i < 26; i++)
		{
			hsh0[i] <<= 1;
			if (hsh0[i] >= mod)
			{
				hsh0[i] -= mod;
			}
		}
		hsh0[t[j] - 'a']++;
		if (hsh0[t[j] - 'a'] >= mod)
		{
			hsh0[t[j] - 'a'] -= mod;
		}
	}
	for (j = n - 1; j + m >= n; j--)
	{
		for (i = 0; i < 26; i++)
		{
			hsh[i] <<= 1;
			if (hsh[i] >= mod)
			{
				hsh[i] -= mod;
			}
		}
		hsh[s[j] - 'a']++;
		if (hsh[s[j] - 'a'] >= mod)
		{
			hsh[s[j] - 'a'] -= mod;
		}
	}
	if (check())
	{
		cnt[j + 1]++;
	}
	for (; j >= 0; j--)
	{
		hsh[s[j + m] - 'a'] += (mod - st[m - 1]);
		if (hsh[s[j + m] - 'a'] >= mod)
		{
			hsh[s[j + m] - 'a'] -= mod;
		}
		for (i = 0; i < 26; i++)
		{
			hsh[i] <<= 1;
			if (hsh[i] >= mod)
			{
				hsh[i] -= mod;
			}
		}
		hsh[s[j] - 'a']++;
		if (hsh[s[j] - 'a'] >= mod)
		{
			hsh[s[j] - 'a'] -= mod;
		}
		if (check())
		{
			cnt[j]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	srand(333);
	init();
	solve(1000000123);
	solve(1000000007);
	for (j = 0; j < n; j++)
	{
		if (cnt[j] == 2)
		{
			k++;
		}
	}
	printf ("%d\n", k);
	for (j = 0; j < n; j++)
	{
		if (cnt[j] >= 2)
		{
			printf ("%d ", j + 1);
		}
	}
	return 0;
}