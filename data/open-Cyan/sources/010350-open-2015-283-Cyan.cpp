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

int n;
ll a, b;
std::vector < ll > gx[N], gy[N];
int gs[N], g2s[N];
std::pair < pair , int >  pts[N];
int ptsc = 0;

ld getH(int g, ll x)
{
	int p = std::lower_bound(gx[g].begin(), gx[g].end(), x) - gx[g].begin();
	if (gx[g][p] == x)
		return gy[g][p];
	ll x1 = gx[g][p - 1];
	ll y1 = gy[g][p - 1];
	ll x2 = gx[g][p];
	ll y2 = gy[g][p];
	return y1 + (y2 - y1) * (x - x1) / (ld)(x2 - x1);
}

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
			if (gx[i].size() > 1)
			{
				ll x1 = gx[i][gx[i].size() - 1];
				ll y1 = gy[i][gy[i].size() - 1];
				ll x2 = gx[i][gx[i].size() - 2];
				ll y2 = gy[i][gy[i].size() - 2];
				if ((x - x1) * (y - y2) == (x - x2) * (y - y1))
				{
					gx[i].pop_back();
					gy[i].pop_back();
				}
			}
			gx[i].push_back(x);
			gy[i].push_back(y);
		}
		gs[i] = i;
	}

	std::sort(gs, gs + n, [](int a, int b)
	{
		int i = 0;
		int ms = std::min(gx[a].size(), gx[b].size());
		while (true)
		{
			if (i == ms)
				break;
			if (gx[a][i] == gx[b][i])
			{
				if (gy[a][i] == gy[b][i])
					++i;
				else
					return gy[a][i] < gy[b][i];
			} else
			{
				ll ax = gx[a][i];
				ll ay = gy[a][i];
				ll bx = gx[b][i];
				ll by = gy[b][i];
				ll x = gx[a][i - 1];
				ll y = gy[a][i - 1];
				return (ay-y)*(bx-x) < (by-y)*(ax-x);
			}
		}
		return false;
	});

	for (int i = 0; i < n; ++i)
		g2s[gs[i]] = i;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < gx[i].size(); ++j)
			pts[ptsc++] = {{gx[i][j], gy[i][j]}, i};

	std::sort(pts, pts + ptsc);
	for (int i = 0; i < ptsc; ++i)
	{
		ll x = pts[i].first.first;
		int g = pts[i].second;
		ll gh = pts[i].first.second;
		if (g2s[g] != 0)
		{
			int g1 = gs[g2s[g] - 1];
			if (getH(g1, x) > gh)
			{
				std::cout << "No\n" << g1 + 1 << " " << g + 1 << "\n";
				return;
			}
		}
		if (g2s[g] != n - 1)
		{
			int g1 = gs[g2s[g] + 1];
			if (getH(g1, x) < gh)
			{
				std::cout << "No\n" << g1 + 1 << " " << g + 1 << "\n";
				return;
			}
		}
	}
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
