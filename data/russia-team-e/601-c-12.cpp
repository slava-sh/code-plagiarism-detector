#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <stdio.h>
#pragma comment(linker,"/STACK:256108864")
using namespace std;

#define TASK "dwarfs"
#define forn(i,n) for(ll i=0;i<(ll)n;i++)
typedef long long ll;
const ll maxn=5100000;
ll h[maxn];
ll d[maxn];
ll ans=0;
ll S,T;
ll H;
ll way[maxn];
vector<ll> g[maxn];
bool dfsH(ll v,ll p)
{
	way[v]=(v==T);
	h[v]=1;
	forn(j,g[v].size())if(g[v][j]!=p)
	{
		ll u=g[v][j];
		way[v]|=dfsH(u,v);
		h[v]=max(h[v],h[u]+1);
	}
	d[v]=1;
	forn(j,g[v].size())if(g[v][j]!=p)
	{
		ll u=g[v][j];
		if(!way[u])
			d[v]=max(d[v],h[u]+1);
	}
	return way[v];
}
void dfs(ll v,ll p)
{
	if(!way[v])return;
	if(v!=S)
	{
		ans=max(ans,min(h[v]-h[T],H));
		forn(j,g[v].size())if(g[v][j]!=p)
		{
			ll u=g[v][j];
			if(way[u])continue;
			ans=max(ans,min(h[v]-h[T]+h[u],H));
		}
		H=max(H,h[S]-h[v]+d[v]-1);
	}
	
	forn(j,g[v].size())if(g[v][j]!=p)
	{
		ll u=g[v][j];
		dfs(u,v);
	}
}

int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ll n;
	cin>>n;
	ll x,y;
	forn(i,n-1)
	{
		cin>>x>>y;
	//	x--,y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin>>S>>T;
	//S--,T--;
	dfsH(S,-1);
	H=0;
	forn(j,g[S].size())
	{
		ll u=g[S][j];
		if(!way[u])
		H=max(H,h[u]);
	}
	dfs(S,-1);
	cout<<ans+1;
}