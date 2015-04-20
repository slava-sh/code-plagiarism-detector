#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

const int brr=1010;
int n;
int color[brr];
vector<vector<pair<int, int>>> g;
int P=1000000007;
int ans=1;

void dfs(int v, int c)
{
	color[v]=c;
	for (int i=0; i<g[v].size(); i++)
		if (color[g[v][i].first]==0)
		{
			if (g[v][i].second==0)
				dfs(g[v][i].first, 3-c);
			else
				dfs(g[v][i].first, c);
		}
		else
		{
			if (g[v][i].second==0 && color[v]==color[g[v][i].first])
				ans=0;
			if (g[v][i].second==1 && color[v]!=color[g[v][i].first])
				ans=0;
		}
}



int main()
{
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);

	scanf("%i", &n);
	g.resize(n);

	int temp;
	scanf("%i", &temp);
	if (temp!=0 && temp!=-1)
	{
		cout<<0;
		return 0;
	}


	for (int i=1; i<n; i++)
	{
		int z;
		scanf("%i", &z);
		if (z==-1)
			continue;
		
		if (z+i>n)
		{
			printf("0");
			return 0;
		}

		for (int j=0; j<z; j++)
		{
			g[j].push_back(make_pair(i+j, 1));
			g[i+j].push_back(make_pair(j, 1));
		}

		if (i+z<n)
		{
			g[z].push_back(make_pair(z+i, 0));
			g[z+i].push_back(make_pair(z, 0));
		}
	}

	for (int i=0; i<n; i++)
		color[i]=0;


	for (int i=0; i<n; i++)
		if (color[i]==0)
		{
			ans=(ans*2)%P;
			dfs(i, 1);
		}


	printf("%i", ans);

	return 0;
}