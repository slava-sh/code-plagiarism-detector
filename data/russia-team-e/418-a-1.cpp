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

#define NAME "binary"

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

int const N = 1000 + 10;

int n;
vector<int> edges[3][N];
int color[N], color2[N], color3[N];
bool was[N], was2[N];

void DFS(int v, int c)
{
	if (was[v])
		return;
	was[v] = true;
	color[v] = c;
	for (uint j(0); j < edges[1][v].size(); ++j)
	{
		int u = edges[1][v][j];
		DFS(u, c);
	}		
}

void halt()
{
	printf("0\n");
	exit(0);
}

void DFS2(int v, int c2, int c = 0)
{
	if (was2[v])
	{
		if (c != color2[v])
			halt();
		return;
	}
	color3[v] = c2;
	color2[v] = c;
	was2[v] = true;
	for (uint j(0); j < edges[2][v].size(); ++j)
	{
		int u = edges[2][v][j];
		DFS2(u, c2, 1 - c);
	}		
}

int main()
{
	assert(freopen(NAME".in", "r", stdin));
	assert(freopen(NAME".out", "w", stdout));	

	scanf("%d", &n);
	for (int i(0); i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (i == 0)
			continue;
		if (a == -1)
			continue;
		if (a > n - i)
			halt();
		for (int j(0); j < a; ++j)
		{
			edges[1][j].pb(i + j);
			edges[1][i + j].pb(j);		
		}   
		edges[0][a].pb(i + a);
		edges[0][i + a].pb(a);
	}

	eprintf("! Age of 1st DFS\n");
	int maxcolor = 0;
	for (int i(0); i < n; ++i)
		if (!was[i])
			DFS(i, ++maxcolor);

	#ifdef DEBUG
	for (int v(0); v < n; ++v)
		printf("! V: ");
	#endif

	eprintf("! Age of rebuilding\n");
	for (int i(0); i < n; ++i)
	{
		for (uint j(0); j < edges[0][i].size(); ++j)
		{
			int u = edges[0][i][j];
			if (color[i] == color[u])
				halt();
			edges[2][color[i]].pb(color[u]);
			edges[2][color[u]].pb(color[i]);
		}
	}
	
	eprintf("! Age of 2nd DFS\n");
	ull ans = 1;
	for (int i(0); i < n; ++i)
	{
		if (!was2[i])
		{
			DFS2(i, i);
			ans = (ans * 2) % ull(1e9 + 7);
		}   
	}

	printf("%I64u\n", ans);

	return 0;
}