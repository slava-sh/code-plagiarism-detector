#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <time.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define INF 2e9
#define mod 1000000007
#define fi first
#define se second
#define fname "dwarfs"
#define re return

typedef long long ll;

ll n, m, a[11111], x, y, z,u,v,p[222222],pp[222222],tin[222222],tout[222222],tinn[222222],toutt[222222],t,d[222222],dd[222222],l[222222],r[222222],ans;
vector < ll > g[222222];
map<pair<ll,ll>,ll>uu,vv;
void dfs(ll x, ll pr)
{
	d[x]=1;
	t++;
	tin[x]=t;
	p[x]=pr;
	for(ll i=0;i<g[x].size();i++)
	{
		ll to=g[x][i];
		if(to!=pr)
		dfs(to,x),d[x]=max(d[x],d[to]+1);
	}
	t++;
	tout[x]=t;
}
void dfss(ll x, ll pr)
{
	t++;
	dd[x]=1;
	tinn[x]=t;
	pp[x]=pr;
	for(ll i=0;i<g[x].size();i++)
	{
		ll to=g[x][i];
		if(to!=pr)
		dfss(to,x),dd[x]=max(dd[x],dd[to]+1);
	}
	t++;
	toutt[x]=t;
}
void dfs1(ll x, ll pr, ll con, ll gm)
{
	ll ma1=1,ma2=0;
	for(ll i=0;i<g[x].size();i++)
	{
		ll to=g[x][i];
		if(to!=pr)
		{
			if(ma1<d[to]+1)
			ma2=ma1,ma1=d[to]+1;
			else if(ma2<d[to]+1)
			ma2=d[to]+1;
			else if(ma1==d[to]+1)
			ma2=d[to]+1;
		}
	}
	for(ll i=0;i<g[x].size();i++)
	{
		ll to=g[x][i];
		if(to!=pr&&tin[v]>=tin[to]&&tout[v]<=tout[to])
		{
			if(d[to]+1==ma1)
			uu[mp(x,to)]=uu[mp(to,x)]=max(ma2+con,gm);
			else
			uu[mp(x,to)]=uu[mp(to,x)]=max(ma1+con,gm);
			dfs1(to,x,con+1,max(gm,uu[mp(x,to)]));
		}
	}
}
void dfs2(ll x, ll pr, ll con, ll gm)
{
	ll ma1=1,ma2=0;
	for(ll i=0;i<g[x].size();i++)
	{
		ll to=g[x][i];
		if(to!=pr)
		{
			if(ma1<dd[to]+1)
			ma2=ma1,ma1=dd[to]+1;
			else if(ma2<dd[to]+1)
			ma2=dd[to]+1;
			else if(ma1==dd[to]+1)
			ma2=dd[to]+1;
		}
	}
	for(ll i=0;i<g[x].size();i++)
	{
		ll to=g[x][i];
		if(to!=pr&&tinn[to]<=tinn[u]&&toutt[to]>=toutt[u])
		{
			if(dd[to]+1==ma1)
			vv[mp(x,to)]=vv[mp(to,x)]=max(ma2+con,gm);
			else
			vv[mp(x,to)]=vv[mp(to,x)]=max(ma1+con,gm);
			dfs2(to,x,con+1,max(gm,vv[mp(x,to)]));
		}
	}
}

int main() {
	
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);

	cin >> n;
	for(ll i=1;i<=n-1;i++)
	scanf("%d%d",&x,&y),g[x].pb(y),g[y].pb(x),l[i]=x,r[i]=y;
	cin>>u>>v;
	dfs(u,0);
	t=0;
	dfss(v,0);
	dfs1(u,0,0,1);
	dfs2(v,0,0,1);
	for(ll i=1;i<=n-1;i++)
	ans=max(ans,min(uu[mp(l[i],r[i])],vv[mp(l[i],r[i])]));
	cout<<ans;
}