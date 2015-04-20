#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;



const int INF=1000000000;
const int brr=5010;

int n, m;
vector <vector<pair<int , int>>> g;
bool was[brr];
int d[brr];
int a[brr];
int who[brr];

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	
	scanf("%i %i", &n, &m);
	g.resize(n+1);

	a[0]=1;
	for (int i=1; i<=n; i++)
	{
		scanf("%i", &a[i]);
		if (a[i]==1)
			g[0].push_back(make_pair(i, 0));
	}

	for (int i=1; i<=m; i++)
	{
		int v, u, c;
		scanf("%i %i %i", &v, &u, &c);
		g[v].push_back(make_pair(u, c));
		g[u].push_back(make_pair(v, c));
	}
	
	d[0]=0;
	for (int i=1; i<=n; i++)
		d[i]=INF;


	for (int i=0; i<=n; i++)
		was[i]=0;

	while (1)
	{
		int v, bl=INF;
		for (int i=0; i<=n; i++)
			if (!was[i] && bl>d[i])
			{
				bl=d[i];
				v=i;
			}

		if (bl==INF)
			break;

		for (int i=0; i<g[v].size(); i++)
		if (d[g[v][i].first]>d[v]+g[v][i].second)
		{
			d[g[v][i].first] = d[v]+g[v][i].second;
			who[g[v][i].first]=v;
		}

		was[v]=1;
	}

	int bl=INF;
	int v;

	for (int i=1; i<=n; i++)
		if (a[i]==2 && d[i]<bl)
		{
			bl=d[i];
			v=i;
		}


	if (bl==INF)
	{
		printf("-1");
		return 0;
	}

	int v1=v;

	while (a[v1]!=1)
		v1=who[v1];

	printf("%i %i %i", v1, v, d[v]);



	return 0;
}