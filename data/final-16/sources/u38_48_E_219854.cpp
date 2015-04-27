#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <cstdarg>

#ifndef DBG
#define	DBG	0
#endif

//#define	DBG(f,x)	if(_____debug & f) { x; }
using namespace std;

#define	rep(i,n)	for((i) = 0; (i) < (n); (i)++)
#define	rab(i,a,b)	for((i) = (a); (i) <= (b); (i)++)
#define all(v)		(v).begin(),(v).end()
#define	Fi(n)		rep(i,n)
#define	Fj(n)		rep(j,n)
#define	Fk(n)		rep(k,n)
#define	sz(v)		(v).size()

// {{{ gprintf for debugging
bool gprintf(int debug,const char *format,...) {
	if(DBG & debug) {
		va_list	listpointer;

		va_start(listpointer, format);
		vfprintf(stderr,format,listpointer);
		va_end(listpointer);

		return true;
	}
	else
		return false;
}
// }}}

vector <int>	edges[40500];
int		vertices;

int	hh[201],ht[201];
int	th[201],tt[201];
int	n,m;

int	cost[40500];

void bfs(int source) {
	memset(cost,-1,sizeof(cost));

	queue <int>	Q;
	int	e;

	Q.push(source);
	cost[source] = 0;

	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();

		rep(e,sz(edges[u])) {
			int v = edges[u][e];

			if(cost[v] == -1) {
				/*if(v == 20) printf("u = %d v = %d\n",u,v);
				if(v == 12) printf("u = %d v = %d\n",u,v);
				if(v == 7) printf("u = %d v = %d\n",u,v);
				if(v == 0) printf("u = %d v = %d\n",u,v);
				if(v == 1) printf("u = %d v = %d\n",u,v);*/
				cost[v] = cost[u] + 1;
				Q.push(v);
			}
		}
	}
}

int color[40500];

int	worst[40500];
int	end_vert;

int get_worst(int u) {
	int	&r = worst[u];

	if(r >= 0) return r;
	if(u == end_vert) return (r = 0);

	int	i,v;

	r = 0;

	Fi(sz(edges[u])) {
		v = edges[u][i];
		int	p = 1 + get_worst(v);

		r = max(r,p);
	}

	return r;
}

bool cycle(int u) {
	int	i,v;

	if(color[u] == 1) {
		//printf("%d ",u);
		return true;
	}
	if(color[u] == 2) return false;
	color[u] = 1;

	Fi(sz(edges[u])) {
		if(cycle(edges[u][i])) {
			//printf("%d -> %d ",u,edges[u][i]);
			return true;
		}
	}

	color[u] = 2;
	return false;
}

int main()
{
	int	h,t,r;
	int	i,j,k;

	scanf("%d %d %d",&h,&t,&r);

	rab(i,0,r) rab(j,0,r) edges[i * (r+1) + j].clear();
	vertices = r * (r+1) + r + 2;

	//printf("r = %d vertices = %d\n",r,vertices);
	edges[vertices-1].clear();

	scanf("%d",&n);

	rab(i,1,n) {
		scanf("%d %d",&hh[i],&ht[i]);
	}

	scanf("%d",&m);
	rab(i,1,m) {
		scanf("%d %d",&th[i],&tt[i]);
	}

	rab(i,0,r) rab(j,0,r) {
		int	e;

		rab(k,1,n) {
			if(k > i) break;

			int	nh,nt;

			nh = (i - k + hh[k]);
			nt = j + ht[k];

			//printf("head: %d %d to %d %d --- k = %d %d %d\n",i,j,nh,nt,k,hh[k],ht[k]);

			if(nh + nt > r) {
				e = vertices - 1;
			} else
				e = nh * (r + 1) + nt;

			edges[i * (r + 1) + j].push_back(e);
		}

		rab(k,1,m) {
			if(k > j) break;

			int	nh,nt;

			nh = (i + th[k]);
			nt = j - k + tt[k];

			//printf("tail: %d %d to %d %d\n",i,j,nh,nt);


			if(nh + nt > r) {
				e = vertices - 1;
			} else
				e = nh * (r + 1) + nt;

			edges[i * (r + 1) + j].push_back(e);
		}

	}


	int	src = h * (r + 1) + t;
	int	win = 0;
	int	lost = vertices - 1;

	bfs(src);

	//printf("vertices = %d lost = %d\n",vertices,lost);

	//printf("h = %d t = %d r = %d src = %d\n",h,t,r,src);

	if(cost[win] != -1) {
		printf("Ivan\n");
		printf("%d\n",cost[win]);
	} else {
		memset(color,0,sizeof(color));

		if(cycle(src))
			printf("Draw\n");
		else {
			printf("Zmey\n");
			memset(worst,-1,sizeof(worst));
			printf("%d\n",get_worst(src));
		}
	}
		

	return 0;
}
