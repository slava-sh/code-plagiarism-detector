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
	cin >> n >> d;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(all(a));
	reverse(all(a));
	int s = 0, c3d = 0, p;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 3 * d)
			s += a[i] - 2 * d, c3d++;
		else
		{
			p = i;
			break;
		}
	}
	int s1 = 0;
	if (s != 0)
		s1 = s + 2 * d;
	int c2d = 0;
	for (int i = p; i < n; i++)
	{
		if (a[i] >= 2 * d)
		{
			c2d++;
			if (c2d == 3)
				break;
			s += a[i] - d;
		}
	}
	int s2 = s;
	cerr << s1 << ' ' << s2 << ' ' << a[0] << endl;
	cout << max(s1, max(s2, max(a[0] + a[1] - 2 * d, a[0])));

}