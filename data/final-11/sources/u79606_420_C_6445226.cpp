#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<algorithm>
#include<list>
#include<cstdio>
#include<stack>
#include<cstring>
#include <climits>
#include<cmath>
#include<string>
#include <functional>
#include<sstream>
#include<map>
#include<set>


#pragma comment(linker, "/STACK:100000000000000")

using namespace std;
#define     For(i,a,b)        for (int i=a; i<b; i++)
#define     Rep(i,a)          for (int i=0; i<a; i++)
#define     ALL(v)            (v).begin(),(v).end()
#define     Set(a,x)          memset((a),(x),sizeof(a))
#define     EXIST(a,b)        find(ALL(a),(b))!=(a).end()
#define     Sort(x)           sort(ALL(x))
#define     UNIQUE(v)         Sort(v); (v).resize(unique(ALL(v)) - (v).begin())
#define     MP                make_pair
#define     SF                scanf
#define     PF                printf
#define     MAXN              300311
#define     MAXM              1001
#define     MOD               1000000007
#define     Dbug             cout<<"";
#define     EPS              1e-15
typedef long long ll;
typedef pair<int,int> pii;
int n, m;
vector<pair<ll, int> > vec;
vector<int> adj[MAXN];
ll sum[MAXN];
int ii[MAXN];
int main(){
	//ios_base::sync_with_stdio(false);
//	freopen("a.in","r",stdin);
	ll ans=0;
	int a, b;
	SF("%d %d", &n, &m);
	Rep(i, n)
	{
		SF("%d %d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		sum[a]++, sum[b]++;
	}
	Rep(i, n) vec.push_back(MP(sum[i], i));
	Sort(vec);
	Rep(i, n) 
	{
		Sort(adj[i]);
		ii[vec[i].second]=i;
	}
	Rep(i, n)
	{
		int need=m-vec[i].first;
		if(need<=0)
		{
			ans+=n-1;
			continue;
		}
		int k=vec[i].second;
		int r=n, l=0, x=-1;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(vec[mid].first>=need)
			{
				r=x=mid;
			}
			else l=mid+1;
		}
		if(x==-1) continue;
		ll add=n-x;
		if(sum[k]>=need) add--;
		if(add==0) continue;
		Rep(j, adj[k].size())
		{
			int cnt=1;
			For(z, j+1, adj[k].size()) if(adj[k][j]==adj[k][z]) cnt++;
			else break;
			if(sum[adj[k][j]]>=need)
			{
				int t=sum[adj[k][j]]-cnt;
				if(t<need) add--;
			}
			j+=cnt-1;
		}
		ans+=add;
	}
	cout<<ans/2<<endl;
	return 0;
}