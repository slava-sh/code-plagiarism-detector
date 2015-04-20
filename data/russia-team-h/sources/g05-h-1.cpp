#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N=5007;
const int INF=1000000000;
int d[N],n,m,a[N];
bool mark[N];
priority_queue< pair <int, int> > q;
vector< pair <int , int > > graph[N];
int ee,ff,gg;
bool minus;
void deykstra(int x)
{
	ee=INF;
	ff=INF;
	gg=INF;
	int b,c,e,f,g,i;
	while(!q.empty())
		q.pop();
	q.push(make_pair(0,x));
	for(i=1;i<=n;i++)
	{
		d[i]=10000000;
		mark[i]=false;
	}
	d[x]=0;
	while(!q.empty())
	{
		b=-q.top().first;
		c=q.top().second;
		q.pop();
		if(a[c]==2)
		{
			ee=x;
			ff=c;
			gg=b;
			return ;
		}
		for(i=0;i<graph[c].size();i++)
		{
			e=graph[c][i].first;
			f=graph[c][i].second;
			if(mark[e]==false && d[e]>d[c]+f)
			{
				d[e]=d[c]+f;
				q.push(make_pair(-d[e],e));
			}
		}
	}
}
int main()
{
	freopen("secure.in","r",stdin);
	freopen("secure.out","w",stdout);
	int i,j,b,c,e,f,g,h;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e,&f,&g);
		graph[e].push_back(make_pair(f,g));
		graph[f].push_back(make_pair(e,g));
	}
	int ans1=INF,ans2=INF,ans3=INF;
	for(i=1;i<=n;i++)
		if(a[i]==1)
		{
			deykstra(i);
			if(gg<ans3)
			{
				ans1=ee;
				ans2=ff;
				ans3=gg;
			}
		}
	if(ans1==INF)
		printf("-1\n");
	else
	printf("%d %d %d\n",ans1,ans2,ans3);
	return 0;
}

	
	