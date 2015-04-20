#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#pragma comment(linker,"/STACK:67108864")
#define mp make_pair
using namespace std;

#define TASK "binary"
#define forn(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
int n;
const int maxn=1100;
vector<pair<int,int> > g[maxn];
vector<int> G[maxn];
vector<int> z;
ll MOD=1000000007;
vector<pair<int,int> > BAD;
int cl=0;
int color[maxn];
int color2[maxn];
void tlen()
{
	cout<<0;
	exit(0);
}
void dfs(int v)
{
	color[v]=cl;
	forn(j,g[v].size())
	{
		int u=g[v][j].first;
		int t=g[v][j].second;
		if(t==0&&color[u]==0)
			dfs(u);
	}
}
int usd[maxn];

void dfs2(int v,int cl)
{
	if(usd[v])
	{
		if(color2[v]!=cl)
		{
			tlen();
		}
		return;
	}
	usd[v]=1;
	color2[v]=cl;
	forn(i,G[v].size())
	{
		int u=G[v][i];
		dfs2(u,cl^1);
	}
}
int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	cin>>n;
	z.resize(n);
	forn(i,n)
		cin>>z[i];
	forn(i,n)
	{
		if(z[i]-1+i>=n)tlen();
		if(i==0&&z[0]!=0)tlen();
		if(i==0)continue;
		if(z[i]==-1)continue;
		forn(k,z[i])
		{
			if(k+i>=n)tlen();
			g[k].push_back(mp(k+i,0));
			g[k+i].push_back(mp(i,0));
		}
		if(i+z[i]<n)
		{
			g[i+z[i]].push_back(mp(z[i],1));
			g[z[i]].push_back(mp(z[i]+i,1));
			BAD.push_back(mp(z[i],z[i]+i));
		}
	}
	forn(i,n)if(color[i]==0)cl++,dfs(i);
	forn(j,BAD.size())
	{
		int v=BAD[j].first;
		int u=BAD[j].second;
		if(color[v]==color[u])tlen();
		G[v].push_back(u);
		G[u].push_back(v);
	}
	ll ans=1;
	forn(i,cl)
	{
		if(usd[i]==0)
		{
			dfs2(i,0);
			ans=(ans+ans)%MOD;
		}
	}
	cout<<ans;
	return 0;
}