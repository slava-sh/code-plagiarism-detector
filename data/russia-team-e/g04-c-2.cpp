#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
//typedef __int64 llint;
typedef string str;
vector <int> G[200010];
int P[200010];
bool M[200010];
int DA[200010];
int EA[200010];
int DB[200010];
int EB[200010];
int dfsA(int g, int p)
{
	EA[g] = EA[p] + 1;
	int i, ans = 0;
	for(i = 0; i < G[g].size(); i++)
	{
		if(G[g][i] == p)
		{
			continue;
		}
		ans = max(ans, dfsA(G[g][i], g));
		if(P[G[g][i]] > 0)
		{
			P[g] = P[G[g][i]] + 1;
		}
	}
	return (DA[g] = ans + 1);
}
int dfsB(int g, int p)
{
	EB[g] = EB[p] + 1;
	int i, ans = 0;
	for(i = 0; i < G[g].size(); i++)
	{
		if(G[g][i] == p)
		{
			continue;
		}
		ans = max(ans, dfsB(G[g][i], g));
	}
	return (DB[g] = ans + 1);
}
int main()
{
	freopen("dwarfs.in", "r", stdin); freopen("dwarfs.out", "w", stdout);
	int n, i, a, b, j, h, z;
	scanf("%d", &n);
	for(i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	scanf("%d%d", &a, &b);
	P[b] = 1;
	EA[0] = EB[0] = -1;
	dfsA(a, 0);
	dfsB(b, 0);
	int ans = 0, ha, hb, hi, hj;
	for(i = 1; i <= n; i++)
	{
		ha = hb = 0;
		if(P[i] == 0)
		{
			continue;
		}
		for(j = 0; j < G[i].size(); j++)
		{
			if(P[ G[i][j] ] > 0)
			{
				break;
			}
		}
		j = G[i][j];
		hi = i; hj = j;
		if(P[hi] < P[hj])
		{
			swap(hi, hj);
		}
		ha = 0;
		for(z = 0; z < G[hi].size(); z++)
		{
			if(G[hi][z] == hj || P[G[hi][z]] > 0)
			{
				continue;
			}
			ha = max(ha, DA[G[hi][z]]);
		}
		ha += EA[hi];
		for(z = 0; z < G[hj].size(); z++)
		{
			if(G[hj][z] == hi || P[G[hj][z]] > 0)
			{
				continue;
			}
			hb = max(hb, DB[G[hj][z]]);
		}
		hb += EB[hj];
		ans = max(ans, min(ha, hb) + 1);
	}
	printf("%d\n", ans);
	return 0;
}