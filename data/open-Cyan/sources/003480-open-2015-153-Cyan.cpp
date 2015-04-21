#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define ss second
#define ff first

const ll maxn = 401;
const ll maxseg = 131072;
const ll inf = 4611686018427387904;
const double pi = 3.141592653589793238462643383279502884;
const double eps = 1e-6;
const double inff = 1e100;

struct point
{
	double x;
	double y;
	point(double xx = 0, double yy = 0)
	{
		x = xx;
		y = yy;
	}
};

struct vect
{
	double x;
	double y;
	vect(double xx = 0, double yy = 0)
	{
		x = xx;
		y = yy;
	}
};

double scal(vect a, vect b)
{
	return a.x * b.x + a.y * b.y;
}

double vec(vect a, vect b)
{
	return a.x * b.y - a.y * b.x;
}

vect make_vect(point a, point b)
{
	return vect(b.x - a.x, b.y - a.y);
}

struct segm
{
	point a;
	point b;
	segm(point aa = point(), point bb = point())
	{
		a = aa;
		b = bb;
	}
};

struct line
{
	double a, b, c;
	line(point aa, point bb)
	{
		vect cc = make_vect(aa, bb);
		a = cc.y;
		b = -cc.x;
		c = - a * aa.x - b * aa.y;
	}
};

bool raz(point a, point b, line c)
{
	return ((a.x * c.a + a.y * c.b + c.c) * (b.x * c.a + b.y * c.b + c.c) < -eps);
}

bool segmp(segm a, segm b)
{
	line aa = line(a.a, a.b);
	line bb = line(b.a, b.b);
	return ((raz(a.a, a.b, bb)) && (raz(b.a, b.b, aa)));
}

vector<segm> d[maxn];

bool ttry(ll a, ll b)
{
	for (int i = 0; i < d[a].size(); ++i)
		for (int j = 0; j < d[b].size(); ++j)
			if (segmp(d[a][i], d[b][j]))
			{
				cout << "No\n";
				cout << a + 1 << ' ' << b + 1 << '\n';
				exit(0);
			}
}

int main()
{
	cin.sync_with_stdio(0);
	ll a, b, n, x, xx, yy;
	vector<point> c[maxn];
	cin >> a >> b >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		for (int j = 0; j < x + 1; ++j)
		{
			cin >> xx >> yy;
			c[i].push_back(point(xx, yy));
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < c[i].size() - 1; ++j)
			d[i].push_back(segm(c[i][j], c[i][j + 1]));
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			ttry(i, j);
	cout << "Yes";
	return 0;
}