#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
#ifdef _WIN32
#define lng "%I64d"
#else
#define lng "%lld"
#endif 
 
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define db double 
 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
                        	
#define all(x) x.begin(),x.end()
#define ll long long
#define TASKNAME "graph"
struct data
{
	int v;
	int c;
	bool n;
	bool operator< (const data &a) const
	{
		if (v<a.v)
			return 1;
		else
			if (v > a.v)
				return 0;
			else
				return c < a.c;  	
	}
};
const double inf =9999999;
const int N=500000,M=800000;
vector<vector <data> > a;
vector <int> r;
int n,m;
void printALL()
{
	for (int i=0; i<n; ++i)
	{	
		printf("v == %d\n", i+1);
		for (int j=0; j<a[i].size(); ++j)
		{
			printf("==%d(%c)\n",a[i][j].v+1,(!a[i][j].n)?'Y':'N',1/db(5-a[i][j].c));
		}
		printf("===\n");
	}

}
void uniq()
{
	int ans=inf;
	for (int i=0; i<n; ++i)
	{
		sort(a[i].begin(),a[i].end());
		for (int j=0; j<a[i].size(); ++j)
		{
			int l=j+1;
			while(a[i][l].v == a[i][j].v)
				++l;
			if (l-j>1)
			{
				for (int ii=j+1; ii<l; ++ii)
					a[i][ii].n=1;
			}
		}
	}
}		
int p[4]={12,6,4,3};
int main()
{
    freopen(TASKNAME".in","rt",stdin); freopen(TASKNAME".out","wt",stdout);
    
    int x,y,w;
    data X;
    scanf("%d %d",&n,&m);
    a.reserve(n);
    a.resize(n);
    r.reserve(n);
    r.resize(n);
    for (int i=0; i<m; ++i)
    {
    	scanf("%d %d %d",&x,&y,&w);
    	--x;
    	--y;
    	X.n=0;
    	X.c=p[w-1];
    	X.v=y;
    	a[x].pb(X);
    	X.v=x;
    	a[y].pb(X);
    }
    //printALL();
    //uniq();            
    //printALL();
    int k=13;
    queue<int> Q[k];
	int first,count;
	for (int i=1; i<n; ++i)
		r[i]=inf;
	r[0]=0;
	first=0;
	Q[first].push(0);
	count=1;
	while(count)
	{
		while(!Q[first].empty())
		{
			int v=Q[first].front();
			Q[first].pop();
			--count;
			for (int u=0; u<a[v].size(); ++u)
				if ( !a[v][u].n && r[a[v][u].v] > r[v] + a[v][u].c)
				{
					r[a[v][u].v]= r[v] + a[v][u].c;
					Q[(first+a[v][u].c)%k].push(a[v][u].v);
					++count;
				}
		}
		++first%=k;
	}
	for (int i=1; i<n; ++i)
		printf("%.10f\n",db(r[i])/12);
	return 0;
}
