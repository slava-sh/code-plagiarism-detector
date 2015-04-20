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

#define NAME "che"

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

int const N = 300000 + 10;
int const INF = 2e9 + 10;

int n, r;
int a[N];

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	scanf("%d%d", &n, &r);
	for (int i(0); i < n; ++i)
		scanf("%d", &a[i]);
	a[n] = INF;
	++n;

	int p1(-1), p2(0);
	ull ans(0);
	
	for (p1 = 0; p1 < n - 1; ++p1)
	{
		while (p2 + 1 < n && (a[p1] + r >= a[p2]))
			++p2;
		eprintf("! %d %d\n", p1, p2);
		ans += n - p2 - 1;
	}

	printf("%I64u\n", ans);

	return 0;
}