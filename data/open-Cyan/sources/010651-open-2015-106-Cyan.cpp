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
typedef double ld;

const int nmax = 2000 * 100;
const ld inf = 1e10;
const ll infll = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const ld pi = acos(-1.0);
const ll mod = 1000 * 1000 * 1000 + 7;
const ld eps = 1e-5;

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

vector<point> p[nmax];
ld a1, b1;
int n, sz[nmax];
vector<int> zz;

ld pos(int index1, int index2, ld x)
{
	point zz = p[index1][index2 + 1] - p[index1][index2];
	if (abs(len(zz)) < eps)
		return p[index1][index2].y;
	zz = zz / len(zz);
	ld answer = (zz * (x - p[index1][index2].x) / zz.x).y + p[index1][index2].y;
	return answer;
}

inline bool cmp(int i, int j)
{
	bool fa = false, fb = false;
	int index = 0;
	for (int q = 0; q < sz[i] + 1; q++)
	{
		while (p[i][q].x > p[j][index + 1].x)
			index++;
	 	if (p[i][q].y - pos(j, index, p[i][q].x) > eps)
	 		fa = true;
	 	if (p[i][q].y - pos(j, index, p[i][q].x) < -eps)
	 		fb = true;
	 	if (fa && fb)
		{
			cout << "No\n";
			cout << i + 1 << " " << j + 1 << endl;
			exit(0);
		}
	}
	index = 0;
	for (int q = 0; q < sz[j] + 1; q++)
	{
		while (p[j][q].x > p[i][index + 1].x)
			index++;
	 	if (p[j][q].y - pos(i, index, p[j][q].x) > eps)
	 		fb = true;
	 	if (p[j][q].y - pos(i, index, p[j][q].x) < -eps)
	 		fa = true;
	 	if (fa && fb)
		{
			cout << "No\n";
			cout << i + 1 << " " << j + 1 << endl;
			exit(0);
		}
	}
	return fa;
}

int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	int aa1, bb1;
	scanf("%d%d", &aa1, &bb1);
	a1 = aa1;
	b1 = bb1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &sz[i]);
		p[i].resize(sz[i] + 1);
		for (int j = 0; j < sz[i] + 1; j++)
		{
			scanf("%d%d", &aa1, &bb1);
			p[i][j] = point(aa1, bb1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		ld y = p[i].back().y;
		p[i].pb(point(inf, y));
	}
	zz.resize(n);
	for (int i = 0; i < n; i++)
		zz[i] = i;
	stable_sort(zz.begin(), zz.end(), cmp);
	cout << "Yes\n";
}                                                                     