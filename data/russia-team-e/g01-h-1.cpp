#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
vector <pair <int, int> > g[5001];
queue <pair <int, int> > q;
queue <int> q1;
set <pair <int, pair <int, int> > > s;
int a,b,n,m,i,c,j,t,x,y;
long long ans=99999999999;
vector <int> z;
bool mark[5001];
int v[5001];
pair <int, int> zx[5001],zl[5001];
int main()
{
    freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++)
	{
		scanf("%d", &v[i]);
		if(v[i]==0)
			z.push_back(i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c));
	}
	for(i=1;i<=n;i++)
	{
			c=99999999;

		if(v[i]==0)
		{
			for(j=0;j<g[i].size();j++)
			{
				if(v[g[i][j].first]==2)
				{
					if(g[i][j].second<c)
					{
						c=g[i][j].second;
						x=g[i][j].first;
					}
				}
			}
			if(c!=99999999)
				s.insert(make_pair(c,make_pair(i,x)));
		}
	}
	while(!s.empty())
	{
		c=s.begin()->first;
		a=s.begin()->second.first;
		x=s.begin()->second.second;
		s.erase(s.begin());
		if(mark[a])
			continue;
		mark[a]=true;
		zx[a].first=c;
		zx[a].second=x;
		for(i=0;i<g[a].size();i++)
		{
			if(v[g[a][i].first]==0 && mark[g[a][i].first]==false)
			{
				s.insert(make_pair(c+g[a][i].second,make_pair(g[a][i].first,x)));
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(v[i]==1)
		{
			for(j=0;j<g[i].size();j++)
			{
				if(v[g[i][j].first]==2)
				{
					if(g[i][j].second<ans)
					{
						ans=g[i][j].second;
						x=i;y=g[i][j].first;
					}
				}
				if(v[g[i][j].first]==0 && mark[g[i][j].first])
				{
					if(zx[g[i][j].first].first+g[i][j].second<ans)
					{
						ans=zx[g[i][j].first].first+g[i][j].second;
						y=zx[g[i][j].first].second;
						x=i;
					}
				}
			}
		}
	}
	if(ans==99999999999)
	{
		cout<<"-1\n";
		return 0;
	}
	cout<<x<<" "<<y<<" "<<ans<<endl;
/*	for(i=1;i<=n;i++)
		cout<<i<<" "<<zx[i].first<<" "<<zx[i].second<<endl;*/
    return 0;
}
/*
6 7
1 0 1 2 2 0
1 3 3
1 2 4
2 3 3
2 4 2
1 6 5
3 5 6
5 6 1

/////////////////////

9 9
0 1 0 2 0 2 0 0 0
1 6 8
1 7 1
2 4 5
3 4 1
3 5 4
3 8 2
5 6 2
7 8 3
6 9 7
///
4 2
1 0 0 2
1 3 3
2 4 2


*/