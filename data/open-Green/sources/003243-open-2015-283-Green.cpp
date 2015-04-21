#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef long double ld;
typedef std::pair < int , int > pair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = std::numeric_limits < double > ::infinity();
const ld LDINF = std::numeric_limits < ld > ::infinity();
const double EPS = 1e-9;

const int N = 2000179;
const ll MOD = 1000000007;

ll n;
int k;
std::vector < int > ns;
ll d[11][N];

int main()
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	std::cin >> n >> k;
	for (ll i = 1; i*i <= n; ++i)
		if (n % i == 0)
		{
			ns.push_back(i);
			if (i*i != n)
				ns.push_back(n / i);
		}
	std::sort(ns.begin(), ns.end());

	for (int i = 1; i <= k; ++i)
		for (int j = 0; j < ns.size(); ++j)
		{
			ll cn = ns[j];
			if (i == 1)
			{
				d[i][j] = (cn + 1) >> 1;
				continue;
			}
			d[i][j] = LINF;
			for (int q = 0; q <= j; ++q)
			{
				ll nn = ns[q];
				if (cn % nn != 0)
					continue;
				d[i][j] = std::min(d[i][j], ((cn / nn + 1) >> 1) * d[i - 1][q]);
			}
		}
	std::cout << d[k][ns.size() - 1];

	return 0;
}
