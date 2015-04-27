#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#ifndef for
	#define for if (0) ; else for
#endif
#ifndef ONLINE_JUDGE
	#define DEBUG
#endif
//This file only works in GNU C++
#ifdef DEBUG
	int _CALL_DEPTH=0;
	struct _CALL_STACK
	{
		_CALL_STACK();
		~_CALL_STACK();
	};
	#define _PRINT_STACK_TAB(number) if (number) printf("%5d:\t",__LINE__); else printf("\t"); for (int i=0;i<_CALL_DEPTH;i++) printf("\t");
	#define VAR(f,x) _PRINT_STACK_TAB(true); printf("%s=\t" f "\n",#x,x);
	#define MSG(format,...) _PRINT_STACK_TAB(true); printf(format "\n",##__VA_ARGS__);
	#define FUNC _PRINT_STACK_TAB(true); printf("%s\n",__PRETTY_FUNCTION__); _CALL_STACK _call_stack; 
	_CALL_STACK::_CALL_STACK()
	{
		_PRINT_STACK_TAB(false);
		printf("{\n");
		_CALL_DEPTH++;
	}
	_CALL_STACK::~_CALL_STACK()
	{
		_CALL_DEPTH--;
		_PRINT_STACK_TAB(false);
		printf("}\n");
	}
	void _REDIRECT(bool in,bool out)
	{
		const char * f=__FILE__;
		int i;
		for (i=strlen(f)-1;i>=0;i--)
		{
			if (f[i]=='.')
			{
				break;
			}
		}
		char *p=new char[strlen(f)+10];
		strncpy(p,f,i);
		if (in)
		{
			strcpy(p+i,".in");
			freopen(p,"r",stdin);
		}
		if (out)
		{
			strcpy(p+i,".out");
			freopen(p,"w",stdout);
		}
		delete[] p;
	}
#else
	//display a single variable, like
	//	VAR("%d",x);
	#define VAR
	//display a message, like
	//	MSG("a[%d]=%d",i,a[i]);
	#define MSG
	//put this line at the beginning of a function in order to update the indent of call stack
	#define FUNC
#endif

inline void swap(int &a,int &b)
{
	int k=a;
	a=b;
	b=k;
}

struct UnionFind
{
	public:
	UnionFind(int n)
	{
		father=new int[n];
		int i;
		for (i=0;i<n;i++)
		{
			father[i]=i;
		}
		set=n;
	}
	int getFather(int x)
	{
		int &f=father[x];
		if (f!=x)
		{
			f=getFather(f);
		}
		return f;
	}
	bool setFather(int y,int x)
	{
		int fy=getFather(y);
		int fx=getFather(x);
		if (fy==fx)
		{
			return false;
		}
		else
		{
			father[fx]=fy;
			set--;
			return true;
		}
	}
	int getSetCount() const
	{
		return set;
	}
	~UnionFind()
	{
		delete[] father;
	}
	private:
	int *father;
	int set;
};

struct AbstractGraph
{
	public:
	//node information begins
	int N;//max number of node
	int n;//number of node
	int *head; //head of edge linked list
	//node information ends
	//edge information begins
	int M;// max number of edge;
	int m;// number of edge
	int *next; //next edge in linked list
	int *src; //source of edge
	int *dst; //destination of edge
	//edge information ends
	void clear(int node=-1)
	{
		if (node==-1)
		{
			n=N;
		}
		else
		{
			n=node;
		}
		int i;
		for (i=0;i<n;i++)
		{
			head[i]=-1;
		}
		m=0;
	}
	protected:
	AbstractGraph(int node,int edge)
	{
		N=node;
		M=edge;
		head=new int[N];
		next=new int[M];
		src=new int[M];
		dst=new int[M];
		clear();
	}
	int addEdge(int s,int t)
	{
		next[m]=head[s];
		src[m]=s;
		dst[m]=t;
		head[s]=m;
		m++;
	}
	~AbstractGraph()
	{
		delete[] head;
		delete[] next;
		delete[] src;
		delete[] dst;
	}
};
struct DirectedGraph: public AbstractGraph
{
	DirectedGraph(int n,int m):AbstractGraph(n,m)
	{
	}
	void addEdge(int s,int t)
	{
		AbstractGraph::addEdge(s,t);
	}
};
struct StronglyConnectedComponent: public DirectedGraph
{
	public:
	StronglyConnectedComponent(int n,int m):DirectedGraph(n,m)
	{
		dfi=new int[N];
		low=new int[N];
		stacked=new bool[N];
		componentId=new int[N];
	}
	~StronglyConnectedComponent()
	{
		delete[] dfi;
		delete[] low;
		delete[] stacked;
		delete[] componentId;
	}
	int totalComponent;
	int *componentId;
	void calc()
	{
		int i;
		for (i=0;i<n;i++)
		{
			dfi[i]=-1;
			stacked[i]=false;
		}
		while (!s.empty())
		{
			s.pop();
		}
		nn=0;
		nc=0;
		for (i=0;i<n;i++)
		{
			if (dfi[i]==-1)
			{
				scc_dfs(i);
			}
		}
		totalComponent=nc;
	}
	private:
	//node information begins
	int *dfi;
	int *low;
	bool *stacked;
	//node information ends
	int nn,nc;
	stack<int> s;
	void scc_dfs(int v)
	{
		dfi[v]=nn++;
		low[v]=dfi[v];
		s.push(v);
		stacked[v]=true;
		int i;
		for (i=head[v];i!=-1;i=next[i])
		{
			int t=dst[i];
			if (dfi[t]==-1)
			{
				scc_dfs(t);
				low[v]=min(low[v],low[t]);
			}
			else if (dfi[t]<dfi[v]&&stacked[t])
			{
				low[v]=min(low[v],dfi[t]);
			}
		}
		if (low[v]==dfi[v])
		{
			while (1)
			{
				int t=s.top();
				s.pop();
				stacked[t]=false;
				componentId[t]=nc;
				if (t==v)
				{
					break;
				}
			}
			nc++;
		}
	}
};
struct UndirectedGraph: public AbstractGraph
{
	public:
	//node information begins
	//node information ends
	//edge information begins
	int *inv;
	//edge information ends
	UndirectedGraph(int n,int m):AbstractGraph(n,2*m)
	{
		inv=new int[M];
	}
	~UndirectedGraph()
	{
		delete[] inv;
	}
	void addEdge(int s,int t)
	{
		AbstractGraph::addEdge(s,t);
		AbstractGraph::addEdge(t,s);
		inv[m-2]=m-1;
		inv[m-1]=m-2;
	}
};
struct Block:public UndirectedGraph
{
	public:
	//edge information begins
	int *blockId;
	//edge information ends
	Block(int n,int m):UndirectedGraph(n,2*m)
	{
		blockId=new int[M];
		dfi=new int[N];
		father=new int[N];
		low=new int[N];
		stacked=new bool[M];
	}
	~Block()
	{
	}
	int block()
	{
		int i;
		for (i=0;i<n;i++)
		{
			dfi[i]=-1;
		}
		for (i=0;i<m;i++)
		{
			stacked[i]=false;
		}
		nn=0;
		nb=0;
		for (i=0;i<n;i++)
		{
			if (dfi[i]==-1)
			{
				block_dfs(i);
			}
		}
		return nb;
	}
	private:
	int nn,nb;
	//node information begins
	int *dfi;
	int *father;
	int *low;
	//node information ends
	//edge information begins
	bool *stacked;
	//edge information ends
	stack<int> s;
	void block_dfs(int v)
	{
		dfi[v]=nn++;
		low[v]=dfi[v];
		int i;
		for (i=head[v];i!=-1;i=next[i])
		{
			int t=dst[i];
			if (!stacked[i])
			{
				s.push(i);
				stacked[i]=true;
				s.push(inv[i]);
				stacked[inv[i]]=true;
			}
			if (dfi[t]==-1)
			{
				father[t]=v;
				block_dfs(t);
				if (low[t]>=dfi[v])
				{
					while (1)
					{
						int t=s.top();
						s.pop();
						stacked[t]=false;
						blockId[t]=nb;
						if (t==i)
						{
							break;
						}
					}
					nb++;
				}
				low[v]=min(low[v],low[t]);
			}
			else if (t!=father[v])
			{
				low[v]=min(low[v],dfi[v]);
			}
		}
	}
};

template<typename NUMBER>
struct MinimumSpanningTree: public UndirectedGraph
{
	public:
	//edge information begins
	NUMBER *cost;
	bool *selected;
	NUMBER minimumCost;
	int totalTree;
	//edge information ends
	MinimumSpanningTree(int n,int m):UndirectedGraph(n,m)
	{
		cost=new NUMBER[M];
		selected=new bool[M];
	}
	~MinimumSpanningTree()
	{
		delete[] cost;
		delete[] selected;
	}
	void addEdge(int s,int t,NUMBER c)
	{
		UndirectedGraph::addEdge(s,t);
		cost[m-2]=c;
		cost[m-1]=c;
	}
	void calc()
	{
		minimumCost=0;
		totalTree=n;
		UnionFind u(n);
		vector< pair<NUMBER,int> > a;
		int i;
		for (i=0;i<n;i++)
		{
			int j;
			for (j=head[i];j!=-1;j=next[j])
			{
				a.push_back(make_pair(cost[j],j));
				selected[j]=false;
			}
		}
		sort(a.begin(),a.end());
		for (i=0;i<(int)a.size();i++)
		{
			int e=a[i].second;
			if (selected[e])
			{
				continue;
			}
			if (u.setFather(src[e],dst[e]))
			{
				selected[e]=true;
				selected[inv[e]]=true;
				minimumCost+=a[i].first;
				totalTree--;
			}
		}
	}
};

template<typename NUMBER>
struct MaximumFlow: public DirectedGraph
{
	public:
	NUMBER EPS;
	bool undirected;
	//node information begins
	//node information ends
	//edge information begins
	NUMBER *capacity;
	bool *origin;
	int *inv;
	//edge information ends
	MaximumFlow(int n,int m,bool undirected=false,NUMBER eps=0):DirectedGraph(n,2*m),undirected(undirected),EPS(eps)
	{
		capacity=new NUMBER[M];
		origin=new bool[M];
		inv=new int[M];
		distance=new int[N];
		current=new int[N];
		parent=new int[N];
		count=new int[N];
	}
	~MaximumFlow()
	{
		delete[] capacity;
		delete[] origin;
		delete[] inv;
		delete[] distance;
		delete[] current;
		delete[] parent;
		delete[] count;
	}
	void addEdge(int s,int t,NUMBER c)
	{
		DirectedGraph::addEdge(s,t);
		DirectedGraph::addEdge(t,s);
		capacity[m-2]=c;
		origin[m-2]=true;
		if (undirected)
		{
			capacity[m-1]=c;
			origin[m-1]=true;
		}
		else
		{
			capacity[m-1]=0;
			origin[m-1]=false;
		}
		inv[m-2]=m-1;
		inv[m-1]=m-2;
	}
	NUMBER maxFlow;
	void calc(int s,int t)
	{
		int i;
		for (i=0;i<n;i++)
		{
			distance[i]=n;
			current[i]=head[i];
			count[i]=0;
		}
		queue<int> q;
		q.push(t);
		distance[t]=0;
		count[0]=1;
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			int d=distance[u];
			for (i=head[u];i!=-1;i=next[i])
			{
				if (capacity[inv[i]]>EPS)
				{
					int t=dst[i];
					if (distance[t]==n)
					{
						distance[t]=distance[u]+1;
						q.push(t);
						count[distance[t]]++;
					}
				}
			}
		}
		maxFlow=0;
		int u=s;
		while (distance[s]<n)
		{
			if (u==t)
			{
				NUMBER f=capacity[current[s]];
				for (i=s;i!=t;i=dst[current[i]])
				{
					if (capacity[current[i]]<f)
					{
						f=capacity[current[i]];
					}
				}
				for (i=s;i!=t;i=dst[current[i]])
				{
					capacity[current[i]]-=f;
					capacity[inv[current[i]]]+=f;
				}
				maxFlow+=f;
				u=s;
				continue;
			}
			for (i=current[u];i!=-1;i=next[i])
			{
				if (capacity[i]>EPS&&distance[u]==distance[dst[i]]+1)
				{
					break;
				}
			}
			if (i!=-1)
			{
				current[u]=i;
				parent[dst[i]]=u;
				u=dst[i];
			}
			else
			{
				count[distance[u]]--;
				if (count[distance[u]]==0)
				{
					break;
				}
				NUMBER min=n;
				int minEdge;
				for (i=head[u];i!=-1;i=next[i])
				{
					if (capacity[i]>EPS&&distance[dst[i]]<min)
					{
						min=distance[dst[i]];
						minEdge=i;
					}
				}
				current[u]=minEdge;
				distance[u]=min+1;
				count[distance[u]]++;
				if (u!=s)
				{
					u=parent[u];
				}
				else
				{
					current[u]=head[u];
				}
			}
		}
	}
	private:
	//node information begins
	int *distance;
	int *current;
	int *parent;
	//node information ends
	//edge information begins
	//edge information ends
	int *count;
};

const int N=1100;
char s[N][110];
bool visited[N];
void dfs(MinimumSpanningTree<long long> &g,int v)
{
	if (visited[v])
	{
		return ;
	}
	visited[v]=true;
	int i;
	for (i=g.head[v];i!=-1;i=g.next[i])
	{
		if (!g.selected[i])
		{
			continue;
		}
		int t=g.dst[i];
		if (visited[t])
		{
			continue;
		}
		cout<<t<<' '<<v<<endl;
		dfs(g,t);
	}
}
int main()
{
	#ifdef DEBUG
	_REDIRECT(0,0);
	#else
	ios::sync_with_stdio(false);
	#endif
	int n,m,k,w;
	cin>>n>>m>>k>>w;
	int i,j;
	for (i=0;i<k;i++)
	{
		for (j=0;j<n;j++)
		{
			cin>>(s[i]+j*m);
		}
	}
	MinimumSpanningTree<long long> g(k+1,k*(k+1)/2);
	for (i=0;i<k;i++)
	{
		g.addEdge(0,i+1,n*m);
		for (j=i+1;j<k;j++)
		{
			int c=0;
			int x;
			for (x=n*m-1;x>=0;x--)
			{
				if (s[i][x]!=s[j][x])
				{
					c++;
				}
			}
			g.addEdge(i+1,j+1,(long long)c*w);
		}
	}
	g.calc();
	long long ans=g.minimumCost;
	cout<<ans<<endl;
	dfs(g,0);
	return 0;
}

