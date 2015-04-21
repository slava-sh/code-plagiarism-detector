#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair < int , int > pair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = std::numeric_limits < double > ::infinity();
const ld LDINF = std::numeric_limits < ld > ::infinity();
const double EPS = 1e-9;

const int N = 200179;
const ull P = 1000000007ll;

struct Seg
{
	ll x1, y1, x2, y2;
	ld qx1, qy1, qx2, qy2;
	ll a, b, c;
	int num;

	void computeLine()
	{
		qx1 = x1 + (ld)0.01;
		qy1 = y1 + (ld)0.01;
		qx2 = x2 + (ld)0.01;
		qy2 = y2 + (ld)0.01;

		a = y2 - y1;
		b = x1 - x2;
		c = -a*x1 - b*y1;
	}

	inline int getS(ll x, ll y)
	{
		ll val = x*a + y*b + c;
		return (val > 0 ? 1 : (val < 0 ? -1 : 0));
	}
} seg[N];
int sc;

void check(Seg & s1, Seg & s2)
{
	if (s1.getS(s2.x1, s2.y1) * s1.getS(s2.x2, s2.y2) == -1 &&
		s2.getS(s1.x1, s1.y1) * s2.getS(s1.x2, s1.y2) == -1)
	{
		std::cout << "No\n" << s1.num + 1 << " " << s2.num + 1 << "\n";
	#ifdef LOCAL
		std::cerr << "TIME = " << clock() * 1. / CLOCKS_PER_SEC << "\n";;
	#endif
		exit(0);
	}
}

int n;
ll a, b;
std::vector < ll > gx[N], gy[N];

void myMain()
{
	std::cin >> a >> b >> n;
	for (int i = 0; i < n; ++i)
	{
		int m;
		std::cin >> m;
		for (int j = 0; j <= m; ++j)
		{
			ll x, y;
			std::cin >> x >> y;
			gx[i].push_back(x);
			gy[i].push_back(y);
			if (j != 0)
			{
				seg[sc].x1 = gx[i][gx[i].size() - 2];
				seg[sc].y1 = gy[i][gy[i].size() - 2];
				seg[sc].x2 = gx[i][gx[i].size() - 1];
				seg[sc].y2 = gy[i][gy[i].size() - 1];
				seg[sc].num = i;
				seg[sc].computeLine();
				++sc;
			}
		}
	}

	for (int i = 0; i < sc; ++i)
		for (int j = i + 1; j < sc; ++j)
			if (seg[i].num != seg[j].num)
				check(seg[i], seg[j]);

	std::cout << "Yes\n";
}

void generateTest()
{
	std::cout << "0 10\n";
	n = 100;
	std::cout << n << "\n";
	for (int i = 0; i < n; ++i)
	{
		std::cout << 10;
		for (int j = 0; j <= 10; ++j)
			std::cout << " " << j << " " << rand() % 10 + i*7;
		std::cout << "\n";
	}
}

int main()
{
#ifdef GEN
	freopen("input.txt", "w", stdout);
	generateTest();
	return 0;
#endif

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
#ifdef LOCAL
	std::cerr << "START\n";
#endif

	myMain();

#ifdef LOCAL
	std::cerr << "TIME = " << clock() * 1. / CLOCKS_PER_SEC << "\n";;
#endif
	return 0;
}
