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

#define NAME "secure"

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

typedef pair<int, int> pii;

int const N = 5002 + 10;
int const INF = 2e9 + 10;

int n, m;
int d[N];
int prev[N];
bool was[N];
vector<pii> edges[N];
vector<int> ans;

set<pii> q;

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	scanf("%d%d", &n, &m);
	for (int i(1); i <= n; ++i)
	{	
		int a;
		scanf("%d", &a);
		eprintf("! READ %d-->%d\n", i, a);
		if (a == 1)
			edges[0].pb(mp(i, 0));
		if (a == 2)
			edges[i].pb(mp(n + 1, 0));
	}

	while (m --> 0)
	{
		int v, u, c;
		scanf("%d%d%d", &v, &u, &c);
		edges[v].pb(mp(u, c));
		edges[u].pb(mp(v, c));
	}

	#ifdef DEBUG
	for (int i(0); i <= n + 1; ++i)
		for (uint j(0); j < edges[i].size(); ++j)
			printf("! %d --- %d --> %d\n", i, edges[i][j].scn, edges[i][j].frs);
	#endif

	for (int i(0); i <= n + 1; ++i)
		d[i] = INF;

	q.ins(mp(0, 0));
	d[0] = 0;
	while (q.size())
	{
		pii r = *(q.begin());
		q.erase(q.begin());
		int v = r.scn;

		if (was[v])
			continue;
		was[v] = true;

		for (uint j(0); j < edges[v].size(); ++j)
		{
			int u = edges[v][j].frs;
			int c = edges[v][j].scn;
			if (d[u] <= d[v] + c)
				continue;
			d[u] = d[v] + c;
			prev[u] = v;
			q.ins(mp(d[u], u));
		}
	}

	if (d[n + 1] == INF)
	{
		printf("-1\n");
		return 0;
	}

	int v = n + 1;
	ans.pb(n + 1);
	while (v != 0)
	{
		ans.pb(prev[v]);
		v = prev[v];
	}

	#ifdef DEBUG
	for (uint i(0); i < ans.size(); ++i)
		printf("! %d\n", ans[i]);
	#endif

	printf("%d %d %d\n", ans[ans.size() - 2], ans[1], d[n + 1]);

	return 0;
}