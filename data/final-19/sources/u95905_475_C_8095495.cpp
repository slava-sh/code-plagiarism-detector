#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <list>
#include <set>
#include <queue>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

typedef long long lli;
typedef long li;

template <class T>
bool Maximize (T &v, T nv) { if (nv > v) return v = nv, 1; return 0; }

template <class T>
bool Minimize (T &v, T nv) { if (nv < v) return v = nv, 1; return 0; }

template <class T>
T Mod (T &v, T mod) { return v = (v % mod + mod) % mod; }

const lli INFLL = numeric_limits<lli>::max();
const li INF = numeric_limits<li>::max(), N = 1001;

char a[N][N];
li s[N][N];
li sy, sx, h, w, c, all;

inline bool inBounds (li y, li x)
{
	return y > 0 && x > 0 && x <= w && y <= h;
}

inline li sum (li y0, li x0, li y1, li x1)
{
	return s[y1][x1] - s[y1][x0 - 1] - s[y0 - 1][x1] + s[y0 - 1][x0 - 1];
}

inline bool ok (li y, li x, li hh, li ww)
{
	return inBounds(y + hh - 1, x + ww - 1) && !sum(y, x, y + hh - 1, x + ww - 1);
}

bool dfs (li y, li x, li hh, li ww)
{
	bool down = ok(y + 1, x, hh, ww);
	bool right = ok(y, x + 1, hh, ww);

	if (!(down | right)) return 1;

	if (down ^ right)
	{
		return down ? (c += ww, dfs(y + 1, x, hh, ww)) : (c += hh, dfs(y, x + 1, hh, ww));
	}

	return 0;
}

bool ok (li hh, li ww)
{
	if (!ok(sy, sx, hh, ww)) return 0;
	c = hh * ww;
	return dfs(sy, sx, hh, ww) && c == all;
}

void solve ()
{
	scanf("%ld %ld", &h, &w);

	bool inited = 0;
	for (li y = 1; y <= h; ++ y)
	{
		getchar();
		for (li x = 1; x <= w; ++ x)
		{
			a[y][x] = getchar();
			s[y][x] = s[y - 1][x] + s[y][x - 1] - s[y - 1][x - 1];
			if (a[y][x] == 'X')
			{
				all ++;
				if (!inited) inited = 1, sy = y, sx = x;
			}
			else s[y][x] ++;
		}
	}

	li res = INF;

	for (li hh = 1; hh < N; ++ hh)
	{
		for (li ww = 1; ww < N; ++ ww)
		{
			if (res < hh * ww) continue;
			if (ok(hh, ww))
				Minimize(res, hh * ww);
		}
	}

	printf("%ld\n", res == INF ? -1 : res);
}

void init ()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
}

int main()
{
	init();
	solve();
	return 0;
}
