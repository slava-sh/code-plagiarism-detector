#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include <set>
using namespace std;
vector <int> g[200000];
int n,a,i,j,v,u,b,c,time,par[200001],t[200001],esim[200001];
bool mark[200001];
long long ans;
set <int> s;
set <int>::iterator it;
void dfst(int x)
{
	mark[x]=true;
	for(int i1=0;i1<g[x].size();i1++)
	{
		if(!mark[g[x][i1]])
		{
			t[g[x][i1]]=x;
			dfst(g[x][i1]);
		}
	}
}
int dfs(int x,int r)
{
	if(g[x].size()==1)
		return 1;
	int k=0;
	for(int i1=0;i1<g[x].size();i1++)
	{
		if(t[x]!=g[x][i1] && g[x][i1]!=r)
		{
			if(dfs(g[x][i1],r)>k)
				k=dfs(g[x][i1],r);
		}
	}
	return k+1;
}
int main()
{
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	scanf("%d", &n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin>>v>>u;
	dfst(v);
	for(i=0;i<=n;i++)
		mark[i]=false;
	int p=u;
	while(t[p]!=0)
	{
		esim[t[p]]=p;
		p=t[p];
	}
	p=u;
	while(t[p]!=0)
	{
		par[t[p]]=dfs(t[p],esim[t[p]]);
		p=t[p];
	}
	par[u]=dfs(u,v);
	p=u;
	a=0;
	while(t[p]!=0)
	{
		s.insert(par[p]+a);
		a++;
		p=t[p];
	}
	b=a;
	p=v;a=0;
	long long mi;
	while(p!=u)
	{
		it=s.end();
		if(a+par[p]<*(--it))
			mi=a+par[p];
		else
			mi=*(it);
		if(mi>ans)
			ans=mi;
		s.erase(par[esim[p]]+b-a-1);
		a++;
		p=esim[p];
	}
	cout<<ans<<endl;
	return 0;
}
/*
6
1 2
2 3
3 4
4 5
5 6
4 5

//////////////
8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

*/
