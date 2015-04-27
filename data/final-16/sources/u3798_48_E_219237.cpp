#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
typedef __int64 ll;
const int inf=1e9;
struct Z {
	int h,t;
} q[10000000];
int h,t,R,n,m,st,en,nh[1300],nt[1300],mh[1300],mt[1300],dwin[1250][1250],
	u[1250][1250],dlose,cycle,mark[1250][1250];
void dfs (int h, int t) {
	u[h][t]=1;
	Z nw;
		for (int i=1; i<=min(n,h); i++) {
			nw.h=h-i+nh[i];
			nw.t=t+nt[i];
			if (nw.h>=0 && nw.t>=0) {
			if (nw.h+nw.t<=R) {
				if (u[nw.h][nw.t]==1) cycle=1;
				if (u[nw.h][nw.t]==0) dfs(nw.h,nw.t);
			}
			}
		}
		for (int i=1; i<=min(m,t); i++) {
			nw.h=h+mh[i];
			nw.t=t-i+mt[i];
			if (nw.h>=0 && nw.t>=0) {
			if (nw.h+nw.t<=R) {
				if (u[nw.h][nw.t]==1) cycle=1;
				if (u[nw.h][nw.t]==0) dfs(nw.h,nw.t);
			}
		}
		}
		u[h][t]=2;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
#endif
	cin>>h>>t>>R;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>nh[i]>>nt[i];
	cin>>m;
	for (int i=1; i<=m; i++) cin>>mh[i]>>mt[i];
	for (int i=0; i<=R+210; i++)
		for (int j=0; j<=R+210; j++)
			dwin[i][j]=inf;
	dfs(h,t);
	Z g;
	g.h=h;
	g.t=t;
	q[en++]=g;
	dwin[h][t]=0;
	while (st<en) {
		Z cur=q[st++];
		Z nw;
		for (int i=1; i<=min(n,cur.h); i++) {
			nw.h=cur.h-i+nh[i];
			nw.t=cur.t+nt[i];
			if (nw.h>=0 && nw.t>=0) {
			if (nw.h+nw.t<=R) {
				if (dwin[nw.h][nw.t]==inf) {
					dwin[nw.h][nw.t]=dwin[cur.h][cur.t]+1;
					q[en++]=nw;
				}
			}
			}
		}
		for (int i=1; i<=min(m,cur.t); i++) {
			nw.h=cur.h+mh[i];
			nw.t=cur.t-i+mt[i];
			if (nw.h>=0 && nw.t>=0) {
			if (nw.h+nw.t<=R) {
				if (dwin[nw.h][nw.t]==inf) {
					dwin[nw.h][nw.t]=dwin[cur.h][cur.t]+1;
					q[en++]=nw;
				}
			} 
			}
		}
	}
	if (dwin[0][0]!=inf) {
		puts("Ivan");
		printf("%d",dwin[0][0]);
	} else {
		if (cycle) puts("Draw");
		else {



for (int i=0; i<=R+210; i++)
		for (int j=0; j<=R+210; j++)
			dwin[i][j]=0;
	Z g;
	g.h=h;
	g.t=t;
	q[en++]=g;
	dwin[h][t]=0;
	mark[h][t]=1;
	while (st<en) {
		Z cur=q[st++];
		mark[cur.h][cur.t]=0;
		Z nw;
		for (int i=1; i<=min(n,cur.h); i++) {
			nw.h=cur.h-i+nh[i];
			nw.t=cur.t+nt[i];
			if (nw.h>=0 && nw.t>=0) {
			if (nw.h+nw.t<=R) {
				if (dwin[cur.h][cur.t]-1<dwin[nw.h][nw.t]) {
					dwin[nw.h][nw.t]=dwin[cur.h][cur.t]-1;
					if (!mark[nw.h][nw.t]) {
						q[en++]=nw;
						mark[nw.h][nw.t]=1;
					}
				}
			} else {
				if (dwin[cur.h][cur.t]-1<dlose) {
					dlose=dwin[cur.h][cur.t]-1;
				}
			}
			}
		}
		for (int i=1; i<=min(m,cur.t); i++) {
			nw.h=cur.h+mh[i];
			nw.t=cur.t-i+mt[i];
			if (nw.h>=0 && nw.t>=0) {
			if (nw.h+nw.t<=R) {
				if (dwin[cur.h][cur.t]-1<dwin[nw.h][nw.t]) {
					dwin[nw.h][nw.t]=dwin[cur.h][cur.t]-1;
					if (!mark[nw.h][nw.t]) {
						q[en++]=nw;
						mark[nw.h][nw.t]=1;
					}
				}
			} else {
				if (dwin[cur.h][cur.t]-1<dlose) {
					dlose=dwin[cur.h][cur.t]-1;
				}
			}
			}
		}
	}














			puts("Zmey");
			printf("%d",-dlose);
		}
	}
	}