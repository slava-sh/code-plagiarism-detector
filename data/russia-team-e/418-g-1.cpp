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

#define NAME "prizes"

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

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	int n, m;
	scanf("%d%d", &n, &m);
	if (n == 1 || m == 1)
	{
		printf("%d\n", (max(n, m) + 1) / 4);
	}
	else if (n == 2 || m == 2)
	{
		printf("0\n");
	}
	else
		printf("1\n");

	return 0;
}