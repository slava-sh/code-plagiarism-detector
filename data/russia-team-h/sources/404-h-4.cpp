#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pii pair<int,int>
vector<vector<pii>>g;
vector<bool> can;
const long long inf64=1e16;
	int n,m;
vector<bool> c1,c2;
bool sw=0;
bool dfs(int v)
{
	can[v]=1;
	bool ret=0;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i].fr;
		if (!can[to])
		{
		 ret|=dfs(to);
		}
		else if ((sw==0&&c1[to])||(sw==1&&c2[to]))ret=1;
	}
	return ((((sw==0&&c1[v])||(sw==1&&c2[v])))?1:ret);
}
vector<long long>d;
void dj(int s)
{
	set<pair<long long,int>> q;
	//d.assign(n+1,inf64);
	d[s]=0;
	q.insert(mp(0LL,s));
	while (!q.empty())
	{
		pair<long long,int> y=*q.begin();
		int v=y.sc;
		long long l=y.fr;
		q.erase(q.begin());
		for (int i=0;i<g[v].size();i++)
		{
			int to=g[v][i].fr;
			int w=g[v][i].sc;
			if (d[to]>d[v]+w)
			{
				q.erase(mp(d[to],to));
				d[to]=d[v]+w;
				q.insert(mp(d[to],to));
			}
		}
	}
	d[s]=inf64;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);	

	scanf("%d%d",&n,&m);
		c1.resize(n+1,0);
	c2.resize(n+1,0);
	can.resize(n+1,0);
	vector<vector<int>>c(2);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (a==1)
		{
			c[0].pb(i+1);
			c1[i+1]=1;
		}
		else if (a==2)
		{
			c[1].pb(i+1);
			c2[i+1]=1;
		}
	}
	
	if (c[1].size()<c[0].size())
    sw=1;
	g.resize(n+1);
	for (int i=0;i<m;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		g[x].pb(mp(y,w));
		g[y].pb(mp(x,w));
	}
	int f=-1,t=-1;
	long long len=inf64;
	d.resize(n+1,inf64);
     for (int i=0;i<c[sw].size();i++)
	 {
		// can.assign(n+1,0);
		bool go=dfs(c[sw][i]);
		 
		 if (go)
		 {
			 dj(c[sw][i]);
			 for (int j=0;j<c[1-sw].size();j++)
			 {
				 if (len>d[c[1-sw][j]])
				 {
					 f=c[sw][i];
					 t=c[1-sw][j];
					 len=d[c[1-sw][j]];
				 }
			 }
		 }
	 }
	 if (f==-1)
	 {
		 printf("-1");
		 return 0;
	 }
	 if (sw)
	 {
		 swap(f,t);
	 }
	 cout<<f<<" "<<t<<" "<<len;
}
