#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pii> edge;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define ed first
#define eu second.first
#define ev second.second

#define pb push_back

const int inv=1000000000;
const int minv=-inv;

// Codechunk

const int max_dsun=1010;

int dsun;
int dsup[max_dsun], dsur[max_dsun];

void dsuinit(int dsun_)
{
	dsun=dsun_;
	for(int i=0; i<dsun; ++i)
	{
		dsup[i]=i;
		dsur[i]=0;
	}
}

int dsufindset(int vt)
{
	if(dsup[vt]!=vt)
		dsup[vt]=dsufindset(dsup[vt]);
	return dsup[vt];
}

void dsuunify(int hd1, int hd2)
{
	if(dsur[hd1]<dsur[hd2])
		dsup[hd1]=hd2;
	else if(dsur[hd1]>dsur[hd2])
		dsup[hd2]=hd1;
	else
	{
		dsup[hd2]=hd1;
		++dsur[hd1];
	}
}

// End of Codechunk

const int max_m=10+5;
const int max_n=10+5;
const int max_k=1000+5;

int m,n,k,w;
char level[max_k][max_m][max_n];
vector<edge> edges;

vector<int> adjl[max_k];
bool visited[max_k]={0};
int par[max_k];
void DFS(int vt)
{
	visited[vt]=true;

	int nb;
	rep(i,(int)adjl[vt].size())
	{
		nb=adjl[vt][i];
		if(not visited[nb])
		{
			pis(nb+1); pin(vt+1);
			DFS(nb);
		}
	}
}

void msDFS()
{
	rep(i,k)
		if(not visited[i])
		{
			pis(i+1); pin(0);
			DFS(i);
		}
}

int main()
{
	gi(m); gi(n); gi(k); gi(w);

	rep(l,k)
		rep(i,m)
		{
			gs(level[l][i]);

			/*rep(j,n)
				cout<<k<<" "<<i<<" "<<j<<" :: "<<level[k][i][j]<<"\n";*/
		}

	rep(l1,k)
		rep(l2,l1)
		{
			int diff=0;
			rep(i,m)
				rep(j,n)
				{
					//cout<<l1<<" "<<i<<" "<<j<<" : "<<level[l1][i][j]<<"\n";
					diff+=(level[l1][i][j]!=level[l2][i][j]);
				}
			//cout<<"@@ "<<l2<<" "<<l1<<" :: "<<diff<<"\n";
			edges.pb(edge(diff,pii(l2,l1)));
		}
	sort(edges.begin(),edges.end());

	int cost=m*n*k;

	dsuinit(k);
	rep(i,(int)edges.size())
	{
		int cd=edges[i].ed, cu=edges[i].eu, cv=edges[i].ev;
		//cout<<cu<<" "<<cv<<" :: "<<cd<<"\n";

		if(cd*w>=m*n) break;

		int hd1=dsufindset(cu), hd2=dsufindset(cv);
		if(hd1!=hd2)
		{
			cost-=m*n; cost+=cd*w;
			dsuunify(hd1,hd2);
			adjl[cu].pb(cv);
			adjl[cv].pb(cu);
		}
	}

	pin(cost);
	msDFS();
	
	return 0;
}