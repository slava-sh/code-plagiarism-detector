#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define NAME "polygon"

//#define DEBUG

#ifdef DEBUG
#define eprintf(...) printf(__VA_ARGS__), fflush(stdout)
#else
#define eprintf(...)
#endif

typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define frs first
#define scn second
#define mp make_pair
#define pb push_back
#define ins insert

typedef pair<int, int> pii;

struct TVector
{
	ld x, y;
	explicit TVector(ld x = 0, ld y = 0):
		x(x), y(y)
	{
	}
	TVector operator +(TVector const &b) const
	{
		return TVector(x + b.x, y + b.y);
	}
	void operator -=(TVector const &b)
	{
		x -= b.x;
		y -= b.y;
	}
	TVector operator -(TVector const &b) const
	{
		return TVector(x - b.x, y - b.y);
	}
	TVector operator *(ld const k) const
	{
		return TVector(x * k, y * k);
	}
	TVector operator /(ld const k) const
	{
		return TVector(x / k, y / k);
	}

	ld operator %(TVector const &b) const
	{
		return x * b.y - y * b.x;
	}

	ld lensqr() const
	{
		return x * x + y * y;
	}
	ld len() const
	{
		return sqrt(x * x + y * y);
	}
	ld angle() const
	{
		return atan2(y, x);
	}
};

const int N = 2000;
ld const EPS = 1e-7;

int n;
TVector points[N];
set<ld> ans1, ans2;

inline ld norm(ld a)
{
	while (a <= 0.0)
		a += 2 * M_PI;
	while (a > 2 * M_PI)
		a -= 2 * M_PI;
	return a;
}

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	scanf("%d", &n);
	for (int i(0); i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		points[i] = TVector(x, y);
	}

	for (int i(n - 1); i >= 0; --i)
		points[i] -= points[0];

	int m;
	scanf("%d", &m);
	while (m --> 0)
	{
		eprintf("======================================================================================\n");
		int x, y;
		scanf("%d%d", &x, &y);
		TVector shot(x, y);
		ld r = shot.len();
		ld omega = shot.angle();

		ans1.clear();
		ans2.clear();
		for (int i(0); i < n; ++i)
		{
			TVector A = points[i];
			TVector B = points[(i + 1) % n];
			TVector AB = B - A;

			ld distA = A.len();
			ld distB = B.len();
			if (distA < r && distB < r)
				continue;
			eprintf("! A = %.9lf %.9lf\n", (double)A.x, (double)A.y);
			eprintf("! B = %.9lf %.9lf\n", (double)B.x, (double)B.y);
			eprintf("! AB = %.9lf %.9lf\n", (double)AB.x, (double)AB.y);

			ld cosa;
			if (A.lensqr() == 0.0 || B.lensqr() == 0.0)
				cosa = 1;
			else
				cosa = (A.lensqr() + AB.lensqr() - B.lensqr()) / 2.0 / A.len() / AB.len();
			if (cosa < -1.0 - EPS || cosa > 1.0 + EPS)
				continue;
			eprintf("! i = %d cosa = %.9lf\n", i, (double)cosa);
			ld D = A.lensqr() * cosa * cosa - A.lensqr() + shot.lensqr();
			if (D < 0.0)
				continue;

			ld x1 = A.len() * cosa + sqrt(D);
			ld x2 = A.len() * cosa - sqrt(D);

			if (x1 >= -EPS && x1 =< AB.len() + EPS)
			{
				TVector inter = (A + AB * x1 / AB.len());
				eprintf("!   i = %d inter1 = %.9lf %.9lf\n", i, (double)inter.x, (double)inter.y);
				ld phi = inter.angle();
				ld t = norm(omega - phi);
				ans1.ins(t);
				ans2.ins(2 * M_PI - t);
			}
			if (x2 >= -EPS && x2 =< AB.len() + EPS)
			{
				TVector inter = (A + AB * x2 / AB.len());
				eprintf("!   i = %d inter2 = %.9lf %.9lf\n", i, (double)inter.x, (double)inter.y);
				ld phi = inter.angle();
				ld t = norm(omega - phi);
				ans1.ins(t);
				ans2.ins(2 * M_PI - t);
			}
		}

		ld a1, a2;
		if (ans1.size() == 0)
			a1 = 360;
		else	
			a1 = *(ans1.begin()) * 180.0 / M_PI;
		if (ans2.size() == 0)
			a2 = 360;
		else	
			a2 = *(ans2.begin()) * 180.0 / M_PI;

		printf("%.13lf %.13lf\n", (double) a2, (double) a1);
	}

	return 0;
}