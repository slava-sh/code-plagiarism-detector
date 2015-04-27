#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<string>
#include<queue>
#include<sstream>
#include<cstring>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define PB push_back
#define FORE(i,t) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define SZ(x) int((x).size())

const int INF=1000111222;

int rh[202][2],rt[202][2];

int g[202][202];

int h,t,r,n,m;

vector<pii> v[202][202];

inline bool ok(int x, int y) {
	return (x+y<=r);
}

bool ok2(int px, int py, int x, int y) {
	if(x+y>r) {
		v[201][201].PB(pii(px,py));
	} else {
		v[x][y].PB(pii(px,py));
	}
	return (x+y<=r);
}

bool dfs(int x, int y) {
	g[x][y]=1;
	for(int i=1;i<=min(n,x);++i) {
		int nx=x-i+rh[i][0];
		int ny=y+rh[i][1];
		if(!ok(nx,ny))
			continue;
		if(g[nx][ny]==1)
			return true;
		if(g[nx][ny]==0) {
			if(dfs(nx,ny))
				return true;
		}
	}
	for(int i=1;i<=min(m,y);++i) {
		int nx=x+rt[i][0];
		int ny=y-i+rt[i][1];
		if(!ok(nx,ny))
			continue;
		if(g[nx][ny]==1)
			return true;
		if(g[nx][ny]==0) {
			if(dfs(nx,ny)) {
				return true;
			}
		}
	}
	g[x][y]=2;
	return false;
}

int najd(int x, int y) {
	if(g[x][y]!=-1)
		return g[x][y];
	int w=0;
	FORE(it, v[x][y]) {
		int nx=it->first,ny=it->second;
		w=max(w,1+najd(nx,ny));
	}
	return g[x][y]=w;
}

int main() {
	scanf("%d%d%d%d",&h,&t,&r,&n);
	for(int i=1;i<=n;++i) {
		scanf("%d%d",rh[i]+0, rh[i]+1);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i) {
		scanf("%d%d",rt[i]+0, rt[i]+1);
	}
	for(int i=0;i<=r;++i) {
		for(int j=0;j<=r;++j) {
			g[i][j]=INF;
		}
	}
	g[h][t]=0;
	queue<pii> q;
	q.push(pii(h,t));
	while(!q.empty()) {
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(x==0 && y==0) {
			break;
		}
		for(int i=1;i<=min(x,n);++i) {
			int nx=x-i+rh[i][0];
			int ny=y+rh[i][1];
			if(!ok(nx,ny))
				continue;
			if(g[x][y]+1 < g[nx][ny]) {
				g[nx][ny]=g[x][y]+1;
				q.push(pii(nx,ny));
			}
		}
		for(int i=1;i<=min(y,m);++i) {
			int nx=x+rt[i][0];
			int ny=y-i+rt[i][1];
			if(!ok(nx,ny))
				continue;
			if(g[x][y]+1 < g[nx][ny]) {
				g[nx][ny]=g[x][y]+1;
				q.push(pii(nx,ny));
			}
		}
	}
	if(g[0][0]!=INF) {
		printf("Ivan\n%d\n",g[0][0]);
		return 0;
	}
	for(int i=0;i<=r;++i) {
		for(int j=0;j<=r;++j) {
			g[i][j]=0;
		}
	}
	if(dfs(h,t)) {
		puts("Draw");
		return 0;
	}
	
	
	//bfs2
	
	
	for(int i=0;i<=r;++i) {
		for(int j=0;j<=r;++j) {
			g[i][j]=INF;
		}
	}
	g[h][t]=0;
	while(!q.empty()) {
		q.pop();
	}
	q.push(pii(h,t));
	while(!q.empty()) {
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(x==0 && y==0) {
			break;
		}
		for(int i=1;i<=min(n,x);++i) {
			int nx=x-i+rh[i][0];
			int ny=y+rh[i][1];
			if(!ok2(x,y,nx,ny))
				continue;
			if(g[x][y]+1 < g[nx][ny]) {
				g[nx][ny]=g[x][y]+1;
				q.push(pii(nx,ny));
			}
		}
		for(int i=1;i<=min(m,y);++i) {
			int nx=x+rt[i][0];
			int ny=y-i+rt[i][1];
			if(!ok2(x,y,nx,ny))
				continue;
			if(g[x][y]+1 < g[nx][ny]) {
				g[nx][ny]=g[x][y]+1;
				q.push(pii(nx,ny));
			}
		}
	}
	for(int i=0;i<=r;++i) {
		for(int j=0;j<=r;++j) {
			g[i][j]=-1;
		}
	}
	g[h][t]=0;
	g[201][201]=-1;
	printf("Zmey\n%d\n",najd(201,201));
}
