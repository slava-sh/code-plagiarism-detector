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

struct Event
{
	ll x, y;
	bool start;
	int num;

	bool operator < (const Event & e) const
	{
		if (x == e.x)
			return start < e.start;
		return x < e.x;
	}
} e[N * 2];
int ec;

ll cx;
struct Seg
{
	ll x1, y1, x2, y2;
	ll a, b, c;
	int num;

	void computeLine()
	{
		a = y2 - y1;
		b = x1 - x2;
		c = -a*x1 - b*y1;
	}

	inline int getS(ll x, ll y)
	{
		ll val = x*a + y*b + c;
		return (val > 0 ? 1 : (val < 0 ? -1 : 0));
	}

	ll cmp (const Seg & s) const
	{
		return -(y1 * (s.x2-s.x1) + (cx - x1) * (y2 - y1) * (s.x2-s.x1)) +
			s.y1*(x2-x1) + (cx - s.x1) * (x2-x1) * (s.y2 - s.y1);
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

struct cmpr
{
	bool operator ()(int a, int b) const
	{
		ll x = seg[a].cmp(seg[b]);
		if (x == 0)
			return a < b;
		return x > 0;
	}
};

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

				e[ec].x = seg[sc].x1;
				e[ec].y = seg[sc].y1;
				e[ec].start = true;
				e[ec].num = sc;
				++ec;
				e[ec].x = seg[sc].x2;
				e[ec].y = seg[sc].y2;
				e[ec].start = false;
				e[ec].num = sc;
				++ec;
				++sc;
			}
		}
	}

	std::sort(e, e + ec);
	std::set < int , cmpr > ss;
	for (int i = 0; i < ec; ++i)
	{
		cx = e[i].x;
		if (e[i].start)
		{
			auto it = ss.insert(e[i].num).first;
			if (it != ss.begin())
			{
				auto it1 = it;
				--it1;
				check(seg[*it], seg[*it1]);
			}
			auto it2 = it;
			++it2;
			if (it2 != ss.end())
				check(seg[*it], seg[*it2]);
		}
		else
		{
			auto it = ss.find(e[i].num);
			auto it1 = it;
			std::cerr << "?";
			++it1;
			std::cerr << "!\n";
			if (it1 != ss.end() && it != ss.begin())
			{
				auto it2 = it;
				--it2;
				check(seg[*it1], seg[*it2]);
			}
			ss.erase(it);
		}
	}
	std::cout << "Yes\n";
}

void generateTest()
{
	std::cout << "0 10\n";
	n = 3;
	std::cout << n << "\n";
	for (int i = 0; i < n; ++i)
	{
		std::cout << 10;
		for (int j = 0; j <= 10; ++j)
			std::cout << " " << j << " " << rand() % 10;
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
