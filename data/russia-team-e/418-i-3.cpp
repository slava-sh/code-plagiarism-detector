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

#define NAME "sochi"

#define DEBUG

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

int n, d;
int max1, max2;

vector<int> bad; 

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	scanf("%d%d", &n, &d);

	int ans(0);
	int mx(-1);
	bool flag = false;
	for (int i(0); i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (a >= 3 * d)
		{
			ans += a - 2 * d;
			flag = true;
		}
		else if (a >= 2 * d)
		{
			bad.pb(a);
		}
		mx = max(mx, a);
	}

	sort(bad.begin(), bad.end(), greater<int>());
	for (uint i(0); i < min(2u, bad.size()); ++i)
	{
		ans += bad[i] - 2 * d;
		flag = true;
	}

	if (flag)
		ans += 2 * d;

	if (ans < mx)
		ans = mx;
	printf("%d\n", ans);
           
	return 0;
}