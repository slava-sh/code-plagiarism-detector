#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#pragma comment(linker,"/STACK:67108864")
using namespace std;

#define TASK "dwarfs"
#define forn(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
const int maxn=210000;
int h[maxn];
int d[maxn];
int ans=0;
int S,T;
int H;
int way[maxn];
vector<int> g[maxn];
bool dfsH(int v,int p)
{
	way[v]=(v==T);
	h[v]=1;
	forn(j,g[v].size())if(g[v][j]!=p)
	{
		int u=g[v][j];
		way[v]|=dfsH(u,v);
		h[v]=max(h[v],h[u]+1);
	}
	d[v]=0;
	forn(j,g[v].size())if(g[v][j]!=p)
	{
		int u=g[v][j];
		if(!way[u])
			d[v]=max(d[v],h[u]+1);
	}
	return way[v];
}
void dfs(int v,int p)
{
	if(!way[v])return;
	if(v!=S)
	{
		ans=max(ans,min(h[v]-h[T],H));
		forn(j,g[v].size())if(g[v][j]!=p)
		{
			int u=g[v][j];
			if(way[u])continue;
			ans=max(ans,min(h[v]-h[T]+h[u],H));
		}
	}
	H=max(H,h[S]-h[v]+d[v]-1);
	forn(j,g[v].size())if(g[v][j]!=p)
	{
		int u=g[v][j];
		dfs(u,v);
	}
}

int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	int n;
	cin>>n;
	int x,y;
	forn(i,n-1)
	{
		cin>>x>>y;
		x--,y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin>>S>>T;
	S--,T--;
	dfsH(S,-1);
	H=0;
	forn(j,g[S].size())
	{
		int u=g[S][j];
		if(!way[u])
		H=max(H,h[u]);
	}
	dfs(S,-1);
	cout<<ans+1;
}