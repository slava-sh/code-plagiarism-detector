#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <set>
#include <map>

#define SC(x) scanf("%d",&x)
#define mp make_pair
#define next success

using namespace std;
const int inf=2147483647, md=1e9+7;
const double eps=1e-7;

int n,m,i,j,k,tt,ttt,s[400500],f[400500],head[400500],next[400500],t[400500],A,B,D,qb,qe,u,temp,d;
map<pair<int, int>, int> fl;
struct _q{
	int u,temp,d;
} q[800500];

void add(int u, int temp, int d){
	if (fl[mp(u,temp)]==tt || (u==A && temp!=inf)) return;
	++qe;
	q[qe].u=u;
	q[qe].temp=temp;
	q[qe].d=d;
	fl[mp(u,temp)]=tt;
}

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	SC(n); SC(m); SC(D);
	for (i=1; i<=m; ++i){
		SC(s[i]);
		SC(f[i]);
		SC(t[i]);
		s[i+m]=f[i];
		f[i+m]=s[i];
		t[i+m]=t[i];
	}
	m=m*2;
	for (i=1; i<=m; ++i){
		next[i]=head[s[i]];
		head[s[i]]=i;
	}
	SC(ttt);
	for (tt=1; tt<=ttt; ++tt){
		SC(A); SC(B);
		qb=qe=0;
		add(A,inf,0);
		bool ans=0;
		while (qb<qe){
			++qb;
			u=q[qb].u;
			temp=q[qb].temp;
			d=q[qb].d;
			if (u==B){
				printf("%d\n",d);
				ans=1;
				break;
			}
			for (j=head[u]; j; j=next[j]){
				if (abs(t[j]-temp)<=D || temp==inf) add(f[j],t[j],d+1);
			}
		}
		if (!ans) printf("-1\n");
	}
	return 0;
}
