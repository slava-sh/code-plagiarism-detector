#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )

typedef long long int LL;

using namespace std;

struct M{
	int sc,st,ed;
	M(){}
	M(int s,int x,int y):sc(s),st(x),ed(y){}
	bool operator<(const M& b){
		return st<b.st;
	}
};

int hh1,hh2;
M uu[110],dd[110];
int uun,ddn;

bool cmp(const M& a,const M& b){
	return a.st<b.st;
}

void input(){
	scanf("%d%d",&hh1,&hh2);
	int n;
	scanf("%d",&n);
	uun=ddn=0;
	int x,y,s;
	char c;
	for(int i=0;i<n;i++){
		scanf("%d %c %d %d",&s,&c,&x,&y);
		if(c=='F') dd[ddn++]=M(s,x,y);
		else 	   uu[uun++]=M(s,x,y);
	}
	sort(dd,dd+ddn,cmp);
	sort(uu,uu+uun,cmp);
}

int hi(M u[],int un,M d[],int dn,int h1,int h2){
	int ans=0;

	for(int i=1;i<300;i++){
		//printf("\n-----------%d\n",i);
		int stg=100-h1,alg;
		if(i%2){
			alg=100-h1+100-h2+(i-1)*100;
		}
		else{
			alg=100-h1+h2+(i-1)*100;
		}
		
		int sw=1,sc=0;
		int ui=0,di=0;
		int good=1;
		for(int j=0;j<i;j++){
			double t=100000.0*stg/alg;	
			//printf("%.2lf",t);
			if(sw==1){
				while(ui<un && t>u[ui].ed)ui++;
				if(ui<un && u[ui].st<=t && t<=u[ui].ed){
					sc+=u[ui++].sc;
					//printf("[%d %d] ",u[ui].st,u[ui].ed);
				}
				else{
					good=false;
				}
			}
			else{
				while(di<dn && t>d[di].ed)di++;
				if(di<dn && d[di].st<=t && t<=d[di].ed){
					sc+=d[di++].sc;
					//printf("[%d %d] ",d[ui].st,d[ui].ed);
				}
				else{
					good=false;
				}
			}
			if(!good)break;
			sw=-sw;
			stg+=100;
		}
		if(!good)continue;
		//printf("work!%d\n",sc);
		ans=max(ans,sc);
	}
	return ans;
}

void solve(){
	int ans=max(hi(uu,uun,dd,ddn,hh1,hh2),hi(dd,ddn,uu,uun,100-hh1,100-hh2));
	printf("%d\n",ans);
}

int main(){
	input();
	solve();
	return 0;
}
