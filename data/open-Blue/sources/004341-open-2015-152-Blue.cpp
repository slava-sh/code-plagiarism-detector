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

int n,m,dd;

struct edge
{
	int from;
	int temp;
	int dist;
};


vector <vector <pair <int,int > > > g;
vector <vector <int> > g1;
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>n>>m>>dd;
	g.resize(n);
	g1.resize(n);
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		g[a].push_back(make_pair(c,b));
		g[b].push_back(make_pair(c,a));
		g1[a].push_back(0);
		g1[b].push_back(0);
	}
	for (int i=0;i<n;i++)
	{
		sort(g[i].begin(),g[i].end());
	}
	int qq;
	cin>>qq;
	for (int q=0;q<qq;q++)
	{
		int st,fin;
		cin>>st>>fin;
		st--;
		fin--;
		for (int i=0;i<n;i++)
			for (int j=0;j<g1[i].size();j++)
				g1[i][j]=0;
		queue <edge > go;
		int flag=0;
		edge x;

		for (int i=0;i<g[st].size();i++)
		{
			x.from=g[st][i].second;
			x.temp=g[st][i].first;
			x.dist=1;
			go.push(x);
		}
		int ans=-1;
		vector <int> d(n,9999999);
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
				int from=x.from;
				int temp=x.temp;
				int zz=x.temp-dd-1;
				int ll=0,rr=g[from].size();
				int least=x.temp-dd;
				while (rr-ll>2)
				{
					int mid=(rr+ll)/2;
					if (g[from][mid].first>=least)
					{
						rr=mid;
					}
					else
						ll=mid;
				}
				for (int i=ll;i<g[from].size();i++)
				{
					int gg=x.temp-g[from][i].first;
					if (gg<(-1)*dd)
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