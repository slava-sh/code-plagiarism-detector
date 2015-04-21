#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <queue>
#include <sstream>
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 100001;
int z[MAXN];
int g[MAXN];
int z2[MAXN];
string s;
int n, l;

void countz()
{
	z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++)
	{
		z[i] = 0;
		if (r > i) z[i] = min(r - i, z[i - l]);
		while (s[z[i]] == s[z[i] + i]) z[i]++;
		if (i + z[i] > r) l = i, r = i + z[i];
	}
}

void countz2(int st)
{
	z2[st] = n;
	int l = 0, r = 0;
	for (int i = st + 1; i <= n; i++)
	{
		z2[i] = 0;
		if (r > i) z2[i] = min(r - i, z2[i - l + st]);
		while (s[z2[i] + st] == s[z2[i] + i]) z2[i]++;
		if (i + z2[i] > r) l = i, r = i + z2[i];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> l >> s;
	n = s.length();
	l = min(l, n);
	s += '#';
	countz();
	for (int i = 1; i <= l; i++)
	{
		if ((i + z[i] == n) && (n % i == 0))
		{
			cout << 1 << endl;
			cout << s.substr(0, i) << endl;
			return 0;
		}
	}
	for (int l1 = 1; l1 <= l; l1++)
	{
		int st = l1;
		while (z[st] >= l1) st += l1;
		countz2(st);
		int r2g = min(n - st, l);
		for (int i = n; i >= st; i--)
		{
			if (z[i] >= l1) g[i] = g[i + l1];
			else g[i] = i;
		}
		for (int l2 = r2g; l2 >= 1; l2--)
		{
			int cur = st + l2;
			while (true)
			{
				if (z2[cur] >= l2)
				{
					cur += l2;
					continue;
				}
				if (g[cur] != cur)
				{
					cur = g[cur];
					continue;
				}
				break;
			}
			if (cur == n)
			{
				cout << 2 << endl;
				cout << s.substr(0, l1) << endl;
				cout << s.substr(st, l2) << endl;
				return 0;
			}
		}
	}
	cout << 3 << endl;
	cout << "a" << endl;
	cout << "b" << endl;
	cout << "c" << endl;
	return 0;
}