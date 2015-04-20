#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue> 
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define inf 2000000000
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define For(i,s,n) for (int i=s;i<=n;i++)
#define FOR(i,s,n) for (int i=s;i<n;i++)
#define Ford(i,s,n) for (int i=s;i>=n;i--)
#pragma comment(linker, "/STACK:16777216")


#define MD 1000000007


typedef long long ll;

using namespace std;

set <pair <int,int> > S;

int D[6000],P[6000],n,m,x,y,z;
vector <pair <int,int> > g[6000];


void dijkstra(){
	For(i,1,n+1) D[i]=inf,S.insert(mp(inf,i));
	S.insert(mp(0,0));
	while(!S.empty()){
		int v=S.begin()->s;
		S.erase(S.begin());
		FOR(i,0,g[v].size()){
			int to=g[v][i].f,len=g[v][i].s;
			if (D[v]+len<D[to]){
				S.erase(S.find(mp(D[to],to)));
				D[to]=D[v]+len;
				S.insert(mp(D[to],to));
				P[to]=v;
			}
		}
	}
}



int main(){
	freopen("secure.in","r",stdin);freopen("secure.out","w",stdout);
	scanf("%d%d",&n,&m);
	For(i,1,n){
		scanf("%d",&x);
		if (x==1) g[0].pb(mp(i,0));
		if (x==2) g[i].pb(mp(n+1,0));
	}
	For(i,1,m){
		scanf("%d%d%d",&x,&y,&z);
		g[x].pb(mp(y,z));
		g[y].pb(mp(x,z));
	}
	dijkstra();
	if (D[n+1]==inf){
		puts("-1");
		return 0;
	}
	int ans=0;
	for (int i=n+1;P[i];i=P[i])
		ans=P[i];
	printf("%d %d %d\n",ans,P[n+1],D[n+1]);
}