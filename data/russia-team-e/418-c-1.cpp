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

#define NAME "dwarfs"

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
typedef pair<bool, int> pbi;

int const N = 200000 + 10;
int const INF = 2e9 + 1e8;

int n;
int end[2];
vector<int> edges[N];
int d[N], e[2][N], next[N];
bool norm[N];

bool DFS(int v, int mp, int p = -1, int depth = 0, bool wasTrue = false)
{
	eprintf("! V = %d MP = %d P = %d Depth = %d wasTrue = %d\n", v, mp, p, depth, wasTrue);
	bool flag(false);		
	if (end[1 - mp] == v)
	{
		eprintf("!   OOUPS!\n");
		wasTrue = true;
		flag = true;
	}	

	d[v] = 0;
	e[mp][v] = 0;
	if (mp == 0)
		next[v] = -1;
	for (uint j(0); j < edges[v].size(); ++j)
	{
		int u = edges[v][j];
		if (u == p)
			continue;

		bool res = DFS(u, mp, v, depth + 1, wasTrue);
		if (res)
		{
			flag = true;
			if (mp == 0)
				next[v] = u;
		}
		else
			d[v] = max(d[v], d[u] + 1);
	}
	eprintf("! V = %d D = %d\n", v, d[v]);
	e[mp][v] = d[v] + depth;

	if (!flag || end[1 - mp] == v || wasTrue)
		e[mp][v] = -INF;
	norm[v] = flag;
	return flag;
}

void DFS2(int v, int mp, int p = -1)
{
	if (end[1 - mp] == v)
		return;
	if (p != -1)
		e[mp][v] = max(e[mp][v], e[mp][p]);
	for (uint j(0); j < edges[v].size(); ++j)
	{
		int u = edges[v][j];
		if (u == p)
			continue;

		DFS2(u, mp, v);
	}
}

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	scanf("%d", &n);
	for (int i(0); i < n - 1; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edges[v - 1].pb(u - 1);
		edges[u - 1].pb(v - 1);
	}
	for (int i(0); i < 2; ++i)
	{
		scanf("%d", &end[i]);
		end[i]--;
	}

	for (int i(0); i < 2; ++i)	
	{
		eprintf("! %d %d\n", end[i], i);
		DFS(end[i], i);
	}

	for (int i(0); i < 2; ++i)
		DFS2(end[i], i);
  
	for (int v(0); v < n; ++v)
		if (next[v] == -1)
			next[v] = next[end[0]];

	int ans = 0;
	for (int v(0); v < n; ++v)
	{
		eprintf("! i= %d | e = %d %d | %d | next=%d\n", v, e[0][v], e[1][v], e[1][next[v]], next[v]);
		if (norm[v])
			ans = max(ans, min(e[0][v], e[1][next[v]]));                 
	}

	printf("%d\n", ans + 1);

	return 0;
}