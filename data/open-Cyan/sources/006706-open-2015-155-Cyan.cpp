#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

const long double eps = 0.00000000001;

struct point
{
	long double x, y;
	point(){}
	point(long double x, long double y) : x(x), y(y) {}
	point operator+(point p)
	{
		return point(x + p.x, y + p.y);
	}
	point operator-(point p)
	{
		return point(x - p.x, y - p.y);
	}
	bool operator<(point p)
	{
		return (make_pair(x, y) < make_pair(p.x, p.y));
	}
	bool operator>(point p)
	{
		return (make_pair(x, y) > make_pair(p.x, p.y));
	}
	long double len()
	{
		return sqrt(x * x + y * y);
	}
};

struct line
{
	long double a, b, c;
	line(){}
	line(point p, point q)
	{
		b = p.x - q.x;
		a = q.y - p.y;
		c = -a * p.x - b * p.y;
	}
	point operator*(line l)
	{
		return point((b * l.c - l.b * c) / (l.b * a - b * l.a), (a * l.c - l.a * c) / (l.a * b - a * l.b));
	}
	bool operator||(line l)
	{
		return (abs(a * l.b - b * l.a) < eps);
	}
	bool operator==(line l)
	{
		return (abs(a * l.b - l.a * b) < eps && abs(b * l.c - l.b * c) < eps && abs(a * l.c - c * l.a) < eps);
	}
	long double podst(long double x)
	{
		return ((-a * x - c) / b);
	}
};

long double getval(point p, point q, long double x)
{
	line l = line(p, q);
	return l.podst(x);
}

pair<int, vector<point> > v[100009];

bool cmp(pair<int, vector<point> > a, pair<int, vector<point> > b)
{
	return true;
}

int main()
{
	long double a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int l;
		cin >> l;
		v[i].second.resize(l + 1);
		v[i].first = i;
		for (int j = 0; j <= l; ++j)
		{
			cin >> v[i].second[j].x >> v[i].second[j].y;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			bool f1 = false;
			bool f2 = false;
			int i1 = 0, i2 = 0;
			if (v[i].second[i1].y < v[j].second[i2].y)
				f2 = true;
			if (v[i].second[i1].y > v[j].second[i2].y)
				f1 = true;
			while (i1 != (int)v[i].second.size() - 1 && i2 != (int)v[j].second.size() - 1)
			{
				long double c1 = 100000000000, c2 = 100000000000;
				if (i1 + 1 < (int)v[i].second.size())
				{
					c1 = v[i].second[i1 + 1].x;
				}
				if (i2 + 1 < (int)v[j].second.size())
				{
					c2 = v[j].second[i2 + 1].x;
				}
				if (c1 < c2)
				{
					++i1;
					long double ans = getval(v[j].second[i2], v[j].second[i2 + 1], v[i].second[i1].x);
					if (ans > v[i].second[i1].y + eps)
						f2 = true;
					if (ans < v[i].second[i1].y - eps)
						f1 = true;
				}
				else
				{
					++i2;
					long double ans = getval(v[i].second[i1], v[i].second[i1 + 1], v[j].second[i2].x);
					if (ans > v[j].second[i2].y + eps)
						f1 = true;
					if (ans < v[j].second[i2].y - eps)
						f2 = true;
				}
				if (f1 && f2)
				{
					cout << "No" << endl;
					cout << v[i].first + 1 << ' ' << v[j].first + 1 << endl;
					return 0;
				}
			}
		}
	cout << "Yes" << endl;
}