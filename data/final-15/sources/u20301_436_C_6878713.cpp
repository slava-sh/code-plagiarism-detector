#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <cstdlib>
#include <cctype>
#include <bitset>
#include <string>
#include <map>
#include <cassert>
#include <set>

#ifdef PEYEK 
	#define debugln {printf("----OK----\n");}
	#define debug(...) {printf(__VA_ARGS__);}
	#define debugs(...) {printf(":::::--->> ");printf(__VA_ARGS__);}
	#define TIME() printf("%.3lf\n",clock()/(double)CLOCKS_PER_SEC)
#else
	#define debugln {}
	#define debug(...) {}
	#define debugs(...) {}
	#define TIME() {}
#endif

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
 
using namespace std;
 
const int dr[]={ 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[]={ 0, 1, 0,-1, 1,-1,-1, 1};
const double eps=1e-9;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
const int INF=0x7FFFFFFF;
const ll INFLL=0x7FFFFFFFFFFFFFFFLL;
const double pi=acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar_unlocked()) && (!isdigit(c) && c!='-'));
	if (c=='-')
	{
		neg=1;
		c=getchar_unlocked();
	}
	do num=num*10+c-'0';
	while ((c=getchar_unlocked()) && isdigit(c));
	num*=(neg)?-1:1;
}

void OPEN(string in="input.txt",string out="output.txt")
{
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	return ;
}

//using sokokaleb's template v2.8

struct Edge
{
	int a,b,w;
	Edge(){}
	Edge(int _a,int _b,int _w)
	{
		a = _a;
		b = _b;
		w = _w;
	}

	bool operator < (const Edge &E) const
	{
		return w < E.w;
	}
};

char area[1005][15][15];
int r,c,n,w,ans,prev[1005],cost[1005][1005];
#define FAKE 1000
vector<Edge> vec;
vi adj[1005];
int papa[1005],rank[1005];

int cp(int x) {return papa[x] == x ? x : (papa[x] = cp(papa[x]));}
void join(int x,int y)
{
	x = cp(x);
	y = cp(y);
	if (x == y) return ;
	if (rank[y] < rank[x])
		papa[y] = x;
	else if (rank[x] < rank[y])
		papa[x] = y;
	else
	{
		++rank[x];
		papa[y] = x;
	}
	return ;
}

int calc(int a,int b)
{
	int cnt = 0;
	FOR (i,0,r)
		FOR (j,0,c)
			cnt += (area[a][i][j] != area[b][i][j]) * w;
	return cnt;
}

void dfs(int u,int par)
{
	prev[u] = par + 1;
	if (u != FAKE)
	{
		if (prev[u] == FAKE + 1) prev[u] = 0;
		printf("%d %d\n",u + 1,prev[u]);
	}
	FOR (i,0,SIZE(adj[u]))
	{
		int &v = adj[u][i];
		if (v != par)
			dfs(v,u);
	}
	return ;
}

int main()
{
	getint(r);getint(c);getint(n);getint(w);
	FOR (k,0,n)
		FOR (i,0,r)
			scanf("%s",area[k][i]);

	FOR (i,0,n)
	{
		papa[i] = i;
		FOR (j,0,i)
			vec.pb(Edge(i,j,calc(i,j)));
		vec.pb(Edge(FAKE,i,r*c));
	}
	papa[FAKE] = FAKE;

	VSORT(vec);

	FOR (i,0,SIZE(vec))
	{
		Edge &now = vec[i];
		if (cp(now.a) != cp(now.b))
		{
			join(now.a,now.b);
			ans += now.w;
			adj[now.a].pb(now.b);
			adj[now.b].pb(now.a);
		}
	}

	printf("%d\n",ans);
	dfs(FAKE,-1);
	return 0;
}