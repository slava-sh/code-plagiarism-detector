#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define REP(i,n) for (int i=0; i<n; ++i)
#define CLR(c) memset(c,-1,sizeof(c))
int n, m;
char pic[32][32];
int g[32][32];
int p[28][2];
int c[14], ans=0;
int v[8];
void dp(int id, int u) {
	if (id==14) {
		CLR(v);
		bool valid=true;
		REP(i,28) {
			int a=c[p[i][0]], b=c[p[i][1]];
			if (a<b) swap(a,b);
			if (v[a]&(1<<b)) v[a]-=1<<b;
			else {valid=false; break;}
		}
		if (valid) {
			++ans;
			if (ans==1) {
				REP(i,n) REP(j,m) if (g[i][j]!=-1) pic[i][j]=c[g[i][j]]+'0';
			}
		}
		return;
	}
	if (c[id]!=-1) {
		dp(id+1,u);
		return;
	}
	c[id]=u;
	for (int j=id+1; j<14; ++j) if (c[j]==-1) {
		c[j]=u;
		dp(id+1,u+1);
		c[j]=-1;
	}
	c[id]=-1;
	return;
}
int main()
{
	cin>>n>>m;
	REP(i,n) cin>>pic[i];
	CLR(g);
	int ng=0;
	REP(i,n) REP(j,m) if (pic[i][j]!='.'&&g[i][j]==-1) g[i][j]=g[i+1][j]=g[i][j+1]=g[i+1][j+1]=ng++;
	CLR(p);
	REP(i,n) REP(j,m) if (g[i][j]!=-1) {
		int id=pic[i][j]-'a';
		if (pic[i][j]=='A') id=26;
		else if (pic[i][j]=='B') id=27;
		if (p[id][0]==-1) p[id][0]=g[i][j];
		else p[id][1]=g[i][j];
	}
	CLR(c);
	dp(0,0);
	cout << ans*5040 << endl;
	REP(i,n) cout << pic[i] << endl;
}
