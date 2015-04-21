#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

long long n,m,dd;

struct edge
{
	long long from;
	long long temp;
	long long dist;
};


vector <vector <pair <long long,long long > > > g;
vector <vector <long long> > g1;
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>n>>m>>dd;
	g.resize(n);
	g1.resize(n);
	for (long long i=0;i<m;i++)
	{
		long long a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		g[a].push_back(make_pair(c,b));
		g[b].push_back(make_pair(c,a));
		g1[a].push_back(0);
		g1[b].push_back(0);
	}
	long long qq;
	cin>>qq;
	for (long long q=0;q<qq;q++)
	{
		long long st,fin;
		cin>>st>>fin;
		st--;
		fin--;
		for (long long i=0;i<n;i++)
			for (long long j=0;j<g1[i].size();j++)
				g1[i][j]=0;
		queue <edge > go;
		long long flag=0;
		edge x;

		for (long long i=0;i<g[st].size();i++)
		{
			x.from=g[st][i].second;
			x.temp=g[st][i].first;
			x.dist=1;
			go.push(x);
		}
		long long ans=-1;
		vector <long long> d(n,9999999);
		while (go.size()!=0)
		{
			edge x=go.front();
			go.pop();
			if (x.from==fin)
			{
				ans=x.dist;
				while (go.size()!=0)
					go.pop();
			}

			else
			{
				long long from=x.from;
				long long temp=x.temp;
				long long zz=x.temp-dd-1;

				for (long long i=0;i<g[from].size();i++)
				{
					long long gg=x.temp-g[from][i].first;
					if (gg<(-1)*d)
						break;
					gg=abs(gg);
					if ((gg<=dd)&&(g1[from][i]==0))
					{
						edge y;
						y.temp=g[from][i].first;
						y.from=g[from][i].second;
						y.dist=x.dist+1;
						go.push(y);
						g1[from][i]=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}