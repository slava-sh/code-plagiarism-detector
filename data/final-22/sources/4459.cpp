#pragma comment(linker,"/STACK:67108864")
#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>

using namespace std;

//#define DBUG

#ifdef DBUG
#define FNAME "temp"
#else
#define FNAME "graph"
#endif

const int inf=numeric_limits<int>::max();
const int OGO=(1<<19);
const int OGOGO=(1<<20);

vector<pair<int,int> > tree(OGOGO,make_pair(inf,0));
vector<int> d;
vector<vector<pair<int,int> > > g;
vector<bool> mark;
int cur,r;

void add(pair<int,int> a)
{
	cur=OGO+a.second;
	tree[cur]=a;
	cur/=2;
	while(cur>0)
	{
		r=tree[cur].first;
		tree[cur]=(tree[cur*2].first<tree[cur*2+1].first)?tree[cur*2]:tree[cur*2+1];
		if(tree[cur].first==r) 
			break;
		cur/=2;
	}
}

void del(int x)
{
	cur=OGO+x;
	tree[cur].first=inf;
	cur/=2;
	while(cur>0)
	{
		tree[cur]=(tree[cur*2].first<tree[cur*2+1].first)?tree[cur*2]:tree[cur*2+1];
		cur/=2;
	}
}

int main()
{
    freopen(FNAME".in","r",stdin);
#ifndef DBUG
    freopen(FNAME".out","w",stdout);
#endif
    int u,v,w,i,n,m;
    scanf("%d %d",&n,&m);
    g.resize(n);
    for (i=0;i<m;++i)
    {
        scanf("%d %d %d",&u,&v,&w);
        --u, --v;
        g[u].push_back(make_pair(v,12/w));
        g[v].push_back(make_pair(u,12/w));
    }
    d.assign(n,inf);
    d[0]=0;
    add(make_pair(0,0));
    mark.resize(n);
    for (i=0;i<n;++i)
    {
        v=tree[1].second;
        del(v);
        mark[v]=true;
        for (vector<pair<int,int> >::iterator it=g[v].begin();it!=g[v].end();++it)
        {
            u=it->first;
            if (!mark[u]&&d[u]>d[v]+it->second)
            {
                d[u]=d[v]+it->second;
                add(make_pair(d[u],u));
            }
        }
    }
    for (i=1;i<n;++i)
        printf("%.9lf\n",d[i]/12.0);
    return 0;
}
