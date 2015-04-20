#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#define LLD "%I64d"

#define FILENAME "travel"

struct point
{
	int x, y;
};

const int gox[4] = {0, 0, 1, -1};
const int goy[4] = {1, -1, 0, 0};
const int MW = 510;

int w, h, i, j, n, k;
point och[MW*MW], p, beg, too;
int d[MW][MW];
char t[MW][MW];
point from[MW][MW];
int ans, cur;
string s;
bool vis[MW][MW];
bool toq[MW][MW];

void Add(int dx, int dy)
{
	if (dx == 0)
	{
		if (dy == 1)
			s += 'E';
		else
			s += 'W';
	}
	else if (dx == 1)
		s += 'S';
	else	s += 'N';

}

int Check(int i, int j)
{
	int k;
	for (k = 0; k < 4; k++)
		if ((i + gox[k] >= 0 && j + goy[k] >= 0) && t[i + gox[k]][j + goy[k]] == 'T')
			return k;
	return k;
}

int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf("%d %d %d", &w, &h, &n);
	for (i = 0; i < h; i++) scanf("%s", t[i]);

	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			if (t[i][j] == 'V')
			{
				beg.y = j;
				beg.x = i;
				t[i][j] = 'A';
			}

	och[0] = beg;
	i = 0, j = 1;
	while (i < j)
	{
		p = och[i];
		vis[p.x][p.y] = 1;
		i++;
		for (k = 0; k < 4; k++)
		{
			too.x = p.x + gox[k], too.y = p.y + goy[k];
			if (too.x < 0 || too.x >= h) continue;
			if (too.y < 0 || too.y >= w) continue;
			if (vis[too.x][too.y]) continue;

			if (!toq[too.x][too.y])
			{
				toq[too.x][too.y] = true;
				och[j].x = too.x;
				och[j].y = too.y;
				j++;
			}
			if (d[too.x][too.y] <= d[p.x][p.y] + (t[too.x][too.y] == 'T'))
			{
				d[too.x][too.y] = d[p.x][p.y] + (t[too.x][too.y] == 'T'); 
				from[too.x][too.y] = p;
			}
		}
	}

	ans = 1e9;
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			if (t[i][j] == 'T')
			{
				if (Check(i, j) == 4)
					cur = 2*(n - d[i][j]);
				else
					cur = n - d[i][j];
				cur += abs(i - beg.x) + abs(j - beg.y);
				if (cur < ans)
				{
					p.x = i, p.y = j;
					ans = cur;
				}
			}


	s = "";
    k = Check(p.x, p.y);
	n = n - d[p.x][p.y];

	if (k == 4)
	{
		k = 0; 
		while ((p.x + gox[k] > 0 && p.y + goy[k] > 0) || t[p.x + gox[k]][p.y + goy[k]] != 'A') k++;

		for (i = 0; i < n; i++)
		{
			Add(-gox[k], -goy[k]);
			Add(gox[k], goy[k]);
		}
	}
	else
	{
		if (n % 2 == 1)
			Add(gox[k], goy[k]);
		for (i = 0; i < n/2; i++)
		{
			Add(-gox[k], -goy[k]);
			Add(gox[k], goy[k]);
		}
	}

	while (p.x != beg.x || p.y != beg.y)
	{
		too = from[p.x][p.y];
		Add(p.x - too.x, p.y - too.y);
		p = too;
	}
	reverse(s.begin(), s.end());
	cout << s << "\n";

	return 0;
}