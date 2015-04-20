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

#define NAME "fence"

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

int const N = 100000 + 10;

int n, k;
int a[N];

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	scanf("%d%d", &n, &k);
	for (int i(0); i < n; ++i)
		scanf("%d", &a[i]);

	sort(a, a + n);

	int l(0);
	int r(k + 1);
	while (r - l > 1)
	{
		int m = (l + r) / 2;

		int used(0);
		for (int j(0); j < n; ++j)
		{
			if (a[j] < m)
			{
				used = k + 1;
				break;
			}
			if (used + m > a[j])
			{
				used += m;
				if (used > k)
					break;
			}
			else
				used = a[j];
	    }

		if (used <= k)
			l = m;
		else
			r = m;
	}

	printf("%d\n", l);

	return 0;
}