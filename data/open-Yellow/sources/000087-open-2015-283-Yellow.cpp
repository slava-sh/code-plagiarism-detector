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

const int N = 100179;
const ll MOD = 1000000007;

int n;
int a[N];
int ans = 1;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		if (i != 0 && a[i - 1] != a[i])
			++ans;
	}
	
	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int p, c;
		std::cin >> p >> c;
		--p;
		if (p != 0 && a[p - 1] != a[p]) --ans;
		if (p != n - 1 && a[p + 1] != a[p]) --ans;
		a[p] = c;
		if (p != 0 && a[p - 1] != a[p]) ++ans;
		if (p != n - 1 && a[p + 1] != a[p]) ++ans;
		std::cout << ans << "\n";
	}

	return 0;
}
