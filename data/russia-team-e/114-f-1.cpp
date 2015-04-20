#define _USE_MATH_DEFINES
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

#define FILENAME "polygon"

struct pt
{
	int x, y;
	pt(){}
	pt(int x, int y): x(x), y(y) {}
};

inline pt operator-(const pt &a, const pt &b)
{
	return pt(a.x - b.x, a.y - b.y);
}

const ld eps = 1e-8;
const int maxn = 2005;

pt p[maxn];
int n, m;
ld anscw, ansccw;

void intersect(pt a, pt b, ll r, ld &t1, ld &t2)
{
	ld dx = b.x - a.x;
	ld dy = b.y - a.y;
	ld x1 = a.x;
	ld y1 = a.y;
	ld A = dx * dx + dy * dy;
	ld B = dx * x1 + dy * y1;
	ld C = x1 * x1 + y1 * y1 - r;
	ld D = B * B - A * C;
	if (D <= -eps)
	{
		t1 = -1;
		t2 = -1;
		return;
	}
	if (D < eps)
	{
		t1 = -B / A;
		t2 = -1;
		return;
	}
	t1 = (-B + sqrt(D)) / A;
	t2 = (-B - sqrt(D)) / A;
}

void check(ld a, ld b)
{
	a *= 180 / M_PI;
	b *= 180 / M_PI;
	if (abs(a - b) < eps)
	{
		anscw = 0;
		ansccw = 0;
		return;
	}
	if (a < b)
	{
		anscw = min(anscw, 360 - (b - a));
		ansccw = min(ansccw, b - a);
	} else
	{
		anscw = min(anscw, a - b);
		ansccw = min(ansccw, 360 - (a - b));
	}
}


int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	pt center = p[0];
	for (int i = 0; i < n; i++) p[i] = p[i] - center;
	p[n] = p[0];
	scanf("%d", &m);
	cout.precision(20);
	for (int i = 0; i < m; i++)
	{
//		cout << "new i = " << i << endl;
		pt q;
		scanf("%d%d", &q.x, &q.y);
		q = q - center;
		ld beta = atan2((ld)q.y, (ld)q.x);
		ll r = (ll)q.x * q.x + (ll)q.y * q.y;
//		cout << r << endl;
		anscw = 360;
		ansccw = 360;
		for (int j = 0; j < n; j++)
		{
			ld t1, t2;
			intersect(p[j], p[j + 1], r, t1, t2);
//			cout << t1 << ' ' << t2 << endl;
			if (t1 > -eps && t1 < 1 + eps)
			{
				ld x = p[j].x + (p[j + 1].x - p[j].x) * t1;
				ld y = p[j].y + (p[j + 1].y - p[j].y) * t1;
//				cout << x << ' ' << y << ' ' << x * x + y * y << endl;
				ld alpha = atan2(y, x);
				check(alpha, beta);
			}
			if (t2 > -eps && t2 < 1 + eps)
			{
				ld x = p[j].x + (p[j + 1].x - p[j].x) * t2;
				ld y = p[j].y + (p[j + 1].y - p[j].y) * t2;
//				cout << x << ' ' << y << endl;
				ld alpha = atan2(y, x);
				check(alpha, beta);
			}
		}
		cout << anscw << ' ' << ansccw << endl;
	}
	return 0;
}