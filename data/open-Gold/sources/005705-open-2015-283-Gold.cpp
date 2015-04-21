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

const int N = 3179;

int n, k;
ll c, d;
ll b[N];
ll dp[N][N];
ll ans;

void myMain()
{
	std::cin >> n >> k >> c >> d;
	ll pf = -1;
	for (int i = 0; i < n; ++i)
	{
		ll s, f;
		std::cin >> s >> f;
		ans += (f - s) * d;
		if (i != 0)
			b[i] = s - pf;
		pf = f;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
		{
			if (i == 0)
			{
				dp[i][j] = (j == k - 1 ? 0 : LINF);
				continue;
			}
			dp[i][j] = LINF;
			dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + d * b[i]);
			if (j == k - 1)
				dp[i][j] = std::min(dp[i][j], dp[i - 1][0] + c);
			else
				dp[i][j] = std::min(dp[i][j], dp[i - 1][j + 1]);
		}

	ll mans = LINF;
	for (int j = 0; j < k; ++j)
		mans = std::min(mans, dp[n - 1][j]);
	std::cout << ans + mans << "\n";
}

void generateTest()
{
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
