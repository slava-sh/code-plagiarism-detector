#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int maxn=100086*4;

struct T
{
	int a;
	int b;
	friend bool operator < (T a,T b){if(a.a==b.a)return a.b<b.b;return a.a<b.a;}
	friend bool operator == (T a,T b){if(a.a==b.a&&a.b==b.b)return 1;return 0;}
}z[maxn*2],last;

struct Edge
{
	int next;
	int to;
	int val;
}edge[maxn*2];

int head[maxn],n,p,num_edge,num_z,num,du[maxn],d[maxn];
long long ans;

void add_edge(int from,int to,int dis)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].val=dis;
	head[from]=num_edge;
	edge[++num_edge].next=head[to];
	edge[num_edge].to=from;
	edge[num_edge].val=dis;
	head[to]=num_edge;
}

int get_num(int key)
{
	//printf("get_num(%d):",key);
	int l=1,r=n,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(d[mid]>key)r=mid;
		else l=mid;
	}
	while(d[l]<=key)l++;
	//printf("%d\n",n-l+1);
	return n-l+1;
}

int main()
{
	scanf("%d %d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&z[i].a,&z[i].b);
		if(z[i].a>z[i].b)swap(z[i].a,z[i].b);
	}
	sort(z+1,z+1+n);
	last=z[0];
	for(int i=1;i<=n;i++)
	{
		if(last==z[i])num++;
		else
		{
			add_edge(last.a,last.b,num);
			du[last.a]+=num;
			du[last.b]+=num;
			last=z[i];
			num=1;
		}
	}
	add_edge(last.a,last.b,num);
	du[last.a]+=num;
	du[last.b]+=num;
	for(int i=1;i<=n;i++)d[i]=du[i];
	sort(d+1,d+1+n);
	//for(int i=1;i<=n;i++)printf("du[%d]=%d\n",i,du[i]);
	//for(int i=1;i<=n;i++)printf("d[%d]=%d\n",i,d[i]);
	d[n+1]=10000000;
	for(int i=1;i<=n;i++)
	{
		ans+=get_num(p-du[i]-1);
		if(du[i]*2>=p)ans--;
		for(int j=head[i];j!=0;j=edge[j].next)
		{
			if(du[i]+du[edge[j].to]>=p)ans--;
			if(du[i]+du[edge[j].to]-edge[j].val>=p)ans++;
		}
	}
	cout<<ans/2LL<<endl;
	//system("pause");
	return 0;
}
