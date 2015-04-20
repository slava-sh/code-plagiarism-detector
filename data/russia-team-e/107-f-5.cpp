#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>
#define ld long double

using namespace std;

const int nmax = 3000;
const ld eps = 1e-10;

struct point
{
	ld x, y;
	point(){}
	point(ld X, ld Y)
	{
		x = X;
		y = Y;
	}
};

bool operator ==(point a, point b)
{
	return a.x == b.x && a.y == b.y;
}

point operator -(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}

point operator +(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}

point operator *(point a, ld b)
{
	return point(a.x * b, a.y * b);
}

point operator /(point a, ld b)
{
	return point(a.x / b, a.y / b);
}

ld vect(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

ld scal(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

point norm(point a)
{
	return point(-a.y, a.x);
}

ld len(point a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

int n;
point p[nmax];
vector<point> z;

pair<point, point> cross(point c, ld r, point a, point b)
{
	ld dist = abs(vect(b - a, c - a)) / len(b - a);
	point q = norm(b - a) / len(b - a) * dist;
	if (!(abs(vect(q + c, b - a)) < eps))
		q = norm(norm(norm(b - a))) / len(b - a) * dist;
	point q1, q2;
	ld lena = sqrt(r * r - dist * dist);
	q1 = (b - a);
	q2 = (a - b);
	q1 = q1 / len(q1) * lena;
	q2 = q2 / len(q2) * lena;
	return make_pair(q1 + q + c, q2 + q + c);
}

vector <ld> ag;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cout.setf(ios::fixed);
	cout.precision(15);
	ld pi = asin(1.0) * 2;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	p[n] = p[0];
	int k;
	cin >> k;
	point g;
	for (int i = 0; i < k; i++)
	{
		cin >> g.x >> g.y;
		ld r = len(g - p[0]) - 1e-9;
		z.clear();
		for (int i = 0; i < n; i++)
		{
			if (abs(vect(p[i + 1] - p[i], p[0] - p[i])) > len(p[i + 1] - p[i]) * r)
				continue;
			pair<point, point> ans = cross(p[0], r, p[i], p[i + 1]);
			if (scal(p[i] - ans.first, p[i + 1] - ans.first) < 0)
				z.push_back(ans.first - p[0]);
			if (scal(p[i] - ans.second, p[i + 1] - ans.second) < 0)
				z.push_back(ans.second - p[0]);
		}
		if (z.size() == 0)
		{
			cout << 360.0 << ' ' << 360.0 << endl;
			continue;
		}
		ag.clear();
		for (int j = 0; j < z.size(); j++)
		{
			ag.push_back(atan2(z[j].y, z[j].x));
		}
		ld nag = atan2(g.y - p[0].y, g.x - p[0].x);
		sort(ag.begin(), ag.end());
		ag.push_back(ag[0]);
		for (int i = 0; i < (int)ag.size(); i++)
		{
			if ((ag[i] > nag) || (i == (int)ag.size() - 1))
			{
				if (i == 0) i = (int)ag.size() - 1;
				ld aa = (ag[i] - nag) * 180.0 / pi;
				if (aa <= 0) aa += 360.0;
				cout << aa << " ";
				aa = (nag - ag[i - 1]) * 180.0 / pi;
				if (aa <= 0) aa += 360.0;
				cout << aa << endl;
				break;
			}
		}
	}
}