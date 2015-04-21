#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <string>
#include <cstring>
#define NAME ""
#define mp make_pair
#define mt make_tuple
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int nmax = 1000 * 1000;
const int inf = 1000 * 1000 * 1000;
const ll infll = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const ld pi = acos(-1.0);
const ll mod = 1000 * 1000 * 1000 + 7;
const ld eps = 1e-9;

template<typename T, typename T1>
ostream& operator <<  (ostream& cout, const pair<T, T1> &a)
{
	return (cout << "(" << a.first << "; " << a.second << ")");
}

template<typename T>
ostream& operator << (ostream& cout, const vector<T> &a)
{
	if (a.size() == 0)
		return (cout << "()");
	cout << "(";
	for (int i = 0; i < (int)a.size() - 1; i++)
		cout << a[i] << "; ";
	cout << a.back() << ")";
	return cout;
}

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

inline ostream& operator << (ostream& cout, point a)
{
	return (cout << "(" << a.x << "; " << a.y << ")");
}

inline ld len(point a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

inline point operator + (point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}

inline point operator - (point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}

inline point operator * (point a, ld b)
{
	return point(a.x * b, a.y * b);
}

inline point operator / (point a, ld b)
{
	return point (a.x / b, a.y / b);
}

inline bool operator == (point a, point b)
{
	return (abs(a.x - b.x) < eps && abs(a.y - b.y) < eps);
}

inline bool operator != (point a, point b)
{
	return (abs(a.x - b.x) > eps || abs(a.y - b.y) > eps);
}

inline ld vect(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

inline ld scal(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

inline bool operator < (point a, point b)
{
	bool f1 = (vect(point(1, 0), a) > -eps || ((abs(vect(point(1, 0), a)) < eps) && scal(point(1, 0), a) > -eps));
	bool f2 = (vect(point(1, 0), b) > -eps || ((abs(vect(point(1, 0), b)) < eps) && scal(point(1, 0), b) > -eps));
	if (f1 == f2)
		return vect(a, b) > 0;
  	else
  		return f1;
}

struct line
{
	ld a, b, c;
	line(){}
	line(ld A, ld B, ld C)
	{
		a = A;
		b = B;
		c = C;
	}
	line(point x, point y)
	{
		a = x.y - y.y;
		b = y.x - x.x;
		c = -(a * x.x + b * x.y);
	}
};

inline point cross(line a, line b)
{
	return point((b.c * a.b - a.c * b.b) / (a.a * b.b - a.b * b.a), (a.a * b.c - a.c * b.a) / (a.b * b.a - a.a * b.b));
}

int a1, b1, n, sz[nmax], ind[nmax], st[nmax];
vector<point> p[nmax];
vector<int> pr;
vector<pair<ld, int> > x;

bool cmp(int i, int j)
{
	if (p[i][ind[i]].y != p[j][ind[j]].y)
		return (p[i][ind[i]].y < p[j][ind[j]].y);
	return (vect(p[i][ind[i] + 1] - p[i][ind[i]], p[j][ind[j] + 1] - p[j][ind[j]]) > 0);
}

ld pos(int index, ld x)
{
	if (x == p[index][ind[index]].x)
		return p[index][ind[index]].y;
	point zz = p[index][ind[index] + 1] - p[index][ind[index]];
	ld answer = (zz / len(zz) * (x - p[index][ind[index]].x)).y + p[index][ind[index]].y;
	return answer;
}

int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	cin >> a1 >> b1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sz[i];
		p[i].resize(sz[i] + 1);
		for (int j = 0; j < sz[i] + 1; j++)
			cin >> p[i][j].x >> p[i][j].y;
	}
	p[n].pb(point(a1, inf));
	p[n].pb(point(b1, inf));
	p[n + 1].pb(point(a1, -inf));
	p[n + 1].pb(point(b1, -inf));
	for (int i = 0; i < n + 2; i++)
	{
		ld y = p[i].back().y;
		p[i].pb(point(inf, y));
	}
	sz[n] = sz[n + 1] = 1;
	pr.resize(n + 2);
	for (int i = 0; i < n + 2; i++)
		pr[i] = i;
	for (int i = 0; i < n + 2; i++)
		ind[i] = 0;
	sort(pr.begin(), pr.end(), cmp);
	for (int i = 0; i < n + 2; i++)
		st[pr[i]] = i;
	x.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < sz[i] + 1; j++)	
			x.pb(mp(p[i][j].x, i));
	sort(x.begin(), x.end());
	//cerr << x << endl;
	for (int i = 0; i < (int)x.size(); i++)
	{
		int index = x[i].second;
		int qq = st[index];
		if (pos(pr[qq - 1], x[i].first) > p[index][ind[index] + 1].y)
		{
			cout << "No\n";
			cout << index + 1 << " " << pr[qq - 1] + 1 << endl;
			return 0;
		}
		if (pos(pr[qq + 1], x[i].first) < p[index][ind[index] + 1].y)
		{
			cout << "No\n";
			cout << index + 1 << " " << pr[qq + 1] + 1 << endl;
			return 0;
		}
		if (x[i].first != a1)
			ind[index]++;
	}
	cout << "Yes\n";
}                                                                     