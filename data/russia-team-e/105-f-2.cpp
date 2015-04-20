#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long double ld;

const int maxN = 5000;
const ld Pi = atan(1.0) * 4;

int n, m;

bool Less(ld a, ld b)
{
	return (b - a > 1e-8);
}

bool Gr(ld a, ld b)
{
	return Less(b, a);
}

bool Eq(ld a, ld b)
{
	return !Less(a, b) && !Less(b, a);
}

bool GrOrEq (ld a, ld b)
{
	return Gr(a, b) || Eq(a, b);
}

ld sqr (ld a)
{
	return a * a;
}

ld myAbs (ld a)
{
	if (Eq(a, 0))
		return 0;
	if (Less(a, 0))
		return -a;
	return a;
}

struct point
{
	ld x, y;
	point () {}
	point (ld x_, ld y_)
	{
		x = x_;
		y = y_;
	}
	void scan ()
	{
		cin >> x >> y;
	}
	void print()
	{
		cout << x << " " << y << "\n";
	}
	ld vect (point a)
	{
		return x * a.y - y * a.x;
	}
	ld scal (point a)
	{
		return x * a.x + y * a.y;
	}
	point operator - (point a)
	{
		return point (x - a.x, y - a.y);
	}
	point operator + (point a)
	{
		return point (x + a.x, y + a.y);
	}
	point operator * (ld a)
	{
		return point (x * a, y * a);
	}
	ld len()
	{
		return sqrt(sqr(x) + sqr(y));
	}
	point ort()
	{
		return point (-y, x);
	}
	point norm()
	{
		ld l = len();
		return point(x / l, y / l);
	}
};

bool intersectLineWithCircle (point A, point a, point O, ld r, point *P1, point *P2)
{
	ld hlen = myAbs(a.vect(O - A) / a.len());
	point h = a.ort().norm() * hlen;
	if (!Eq((O + h - A).vect(a), 0))
		h = h * (-1);
	if (!Eq((O + h - A).vect(a), 0))
		throw;
	point H = O + h;
	if (Less(r, hlen))
		return false;
	ld len = sqrt(sqr(r) - sqr(hlen));
	*P1 = H + (a.norm() * len);
	*P2 = H - (a.norm() * len);
	return true;
}

bool inSegment (point P, point A, point B)
{
	if (!Eq((B - A).vect(P - A), 0))
		return false;
	if (GrOrEq((B - A).scal(P - A), 0) && GrOrEq((A - B).scal(P - B), 0))
		return true;
	return false;
}

int intersectSegmentWithCircle(point A, point B, point O, ld r, point *P1, point *P2)
{
	int cnt = 0;
	if (!intersectLineWithCircle(A, (B - A), O, r, P1, P2))
		return 0;
	if (inSegment(*P1, A, B))
		cnt++;
	if (inSegment(*P2, A, B))
	{
		if (cnt == 0)
			swap(*P1, *P2);
		cnt++;
	}
	return cnt;
}

point A[maxN], X;
point B[maxN];
int ind;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cout << fixed << setprecision(10);

	cin >> n;

	for (int i = 0; i < n; i++)
		A[i].scan();

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		ind = 0;
		X.scan();
		for (int j = 0; j < n; j++)
		{
			point P1, P2;
			int cnt = intersectSegmentWithCircle(A[j], A[(j + 1) % n], A[0], (X - A[0]).len(), &P1, &P2);
			if (cnt > 0)
			{
				B[ind++] = (P1 - A[0]);
			}
			if (cnt == 2)
			{
				B[ind++] = (P2 - A[0]);
			}
		}
		X = X - A[0];
		ld ans1 = 1000, ans2 = 0;
		for (int j = 0; j < ind; j++)
		{
			ld angle = atan2(X.vect(B[j]), X.scal(B[j]));
			if (Less(angle, 0))
				angle += 2 * Pi;
			if (angle < ans1)
				ans1 = angle;
			if (angle > ans2)
				ans2 = angle;
		}
		if (ind == 0)
		{
			ans1 = 2 * Pi;
			ans2 = 2 * Pi;
			ans1 = ans1 * 180 / Pi;
			ans2 = ans2 * 180 / Pi;
			cout << ans1 << " " << ans2 << "\n";
			continue;
		}
		ans1 = ans1 * 180 / Pi;
		ans2 = (2 * Pi - ans2) * 180 / Pi;
		cout << ans1 << " " << ans2 << "\n";
	}

	return 0;
}