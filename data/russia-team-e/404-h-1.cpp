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
void dfs(int v)
{
	can[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i].fr;
		if (!can[to])
		dfs(to);
	}
}
vector<long long>d;
void dj(int s)
{
	set<pair<long long,int>> q;
	d.assign(n+1,inf64);
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
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);	

	scanf("%d%d",&n,&m);
	vector<int>c1,c2;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (a==1)c1.pb(i+1);
		else if (a==2)c2.pb(i+1);
	}
	bool sw=0;
	if (c1.size()>c2.size()){swap(c1,c2);sw=1;}
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
     for (int i=0;i<c1.size();i++)
	 {
		 can.assign(n+1,0);
		 dfs(c1[i]);
		 int g=0;
		 for (int j=0;j<c2.size();j++)
		 {
			 if (can[c2[j]])
			 {
				 g=1;
				 break;
			 }
		 }
		 if (g)
		 {
			 dj(c1[i]);
			 for (int j=0;j<c2.size();j++)
			 {
				 if (len>d[c2[j]])
				 {
					 f=c1[i];
					 t=c2[j];
					 len=d[c2[j]];
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
