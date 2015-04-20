
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define eps 1e-9
#define INF 1e+9
#define txt "travel"

using namespace std;
struct para
{
	int x1, x2, y1, y2, r;
	bool c; //0-x1, 1-x2
} l; // l - nearest two
struct point
{
	int x, y, r;
} c, b; // c - character b-nearest
int rx(int i, int j)
{
	return abs(c.x - j) + abs(c.y - i);
}
int w, h, n, ans1, ans2;
char a[510][510];
int main()
{
	freopen(txt".in", "r", stdin);
	freopen(txt".out", "w", stdout);
	cin >> w >> h >> n;
	c.x=c.y=-1;
	b.r = l.r = INF;
	b.x=1000;
	b.y=1000;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'V')
			{
				c.x = j;
				c.y = i;
			}
		}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] == 'T')
			{
				if (rx(i, j) < b.r)
				{
					b.r = rx(i, j);
					b.x = j;
					b.y = i;
				}
			}
			if (a[i][j] == 'T' && (i != n-1 && a[i+1][j] == 'T'))
			{
				if (rx(i, j) < l.r || rx(i+1, j) < l.r)
				{
					if (rx(i, j) < rx(i+1, j))
					{
						l.c = 0;
						l.r = rx(i, j);
					}
					else
					{
						l.c = 1;
						l.r = rx(i+1, j);
					}
					l.x1 = j;
					l.x2 = j;
					l.y1 = i;
					l.y2 = i+1;
				}
			}
			else if (a[i][j] == 'T' && (j != n-1 && a[i][j+1] == 'T'))
			{
				if (rx(i, j) < l.r || rx(i, j+1) < l.r)
				{
					if (rx(i, j) < rx(i, j+1))
					{
						l.c = 0;
						l.r = rx(i, j);
					}
					else
					{
						l.c = 1;
						l.r = rx(i, j+1);
					}
					l.x1 = j;
					l.x2 = j+1;
					l.y1 = i;
					l.y2 = i;
				}
			}
		}
	ans1 = b.r + (n-1)*2 - 1;
	ans2 = l.r + n - 1;
	if (ans1 < ans2)
	{
		if (c.x < b.x)
			for (int i = 0; i < b.x-c.x; i++)
				cout << 'E';
		else
			for (int i = 0; i < c.x-b.x; i++)
				cout << 'W';
		if (c.y < b.y)
			for (int i = 0; i < b.y-c.y; i++)
				cout << 'N';
		else
			for (int i = 0; i < c.y-b.y; i++)
				cout << 'S';
		if (w - b.x - 1 != 0)
		{
			for (int i = 0; i < n-1; i++)
				cout << "EW";
			return 0;
		}
		else if (b.x != 0)
		{
			for (int i = 0; i < n-1; i++)
				cout << "WE";
			return 0;
		}
		if (h - b.y - 1 != 0)
		{
			for (int i = 0; i < n-1; i++)
				cout << "NS";
			return 0;
		}
		else
		{
			for (int i = 0; i < n-1; i++)
				cout << "SN";
			
			return 0;
		}
	}
	else
	{
		if (l.c == 0)
		{
			if (c.x < l.x1)
			for (int i = 0; i < l.x1-c.x; i++)
				cout << 'E';
		else
			for (int i = 0; i < c.x-l.x1; i++)
				cout << 'W';
		if (c.y < l.y1)
			for (int i = 0; i < l.y1-c.y; i++)
				cout << 'S';
		else
			for (int i = 0; i < c.y-l.y1; i++)
				cout << 'N';
		}
		else
		{
			if (c.x < l.x2)
			for (int i = 0; i < l.x2-c.x; i++)
				cout << 'E';
		else
			for (int i = 0; i < c.x-l.x2; i++)
				cout << 'W';
		if (c.y < l.y2)
			for (int i = 0; i < l.y2-c.y; i++)
				cout << 'N';
		else
			for (int i = 0; i < c.y-l.y2; i++)
				cout << 'S';
		}
		if (l.x1 == l.x2)
		{
			if (l.c)
			{
				if (l.y2 > l.y1)
					for (int i = 0; i < n-1; i++)
					{
						cout << "N";
						i++;
						if (i >= n-2)
							break;
						cout << "S";
					}
				else
					for (int i = 0; i < n-1; i++)
					{
						cout << "S";
						i++;
						if (i >= n-2)
							break;
						cout << "N";
					}
			}
		}
			else
			{
				if (l.x2 < l.x1)
					for (int i = 0; i < n-1; i++)
					{
						cout << "W";
						i++;
						if (i >= n-2)
							break;
						cout << "E";
					}
				else
					for (int i = 0; i < n-1; i++)
					{
						cout << "E";
						i++;
						if (i >= n-2)
							break;
						cout << "W";
					}
			}
	}
	return 0;
}