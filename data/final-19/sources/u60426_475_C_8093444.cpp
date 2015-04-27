#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

int n, m;
char g[1234][1234];
int pd[1234][1234], pr[1234][1234];

int fr, fc;
int r, c;

int ans;

int lze(int ro, int co);

int main()
{
	scanf("%d %d\n", &n, &m);
	for(int i=0; i<n; i++) scanf("%s\n", g[i]);

	for(int i=n-1; i>=0; i--) {
		for(int j=0; j<m; j++) {
			pd[i][j]=pd[i+1][j]+(g[i][j]=='X');
		}
	}

	for(int j=m-1; j>=0; j--) {
		for(int i=0; i<n; i++) {
			pr[i][j]=pr[i][j+1]+(g[i][j]=='X');
		}
	}

	ans=-1;

	fr=fc=-1;
	for(int i=0; fr==-1 && i<n; i++) {
		for(int j=0; fr==-1 && j<m; j++) {
			if(g[i][j]=='X') {
				fr=i;
				fc=j;
			}
		}
	}

	for(r=1; fr+r<n; r++) {
		if(g[fr+r][fc]=='.') break;
	}
	for(c=1; fc+c<m; c++) {
		if(g[fr][fc+c]=='.') break;
	}

	if(lze(r, c) && (ans==-1 || ans>r*c)) ans=r*c;

	int rr, cc;
	int frr, fcc;

	cc=c;
	for(frr=fr+1; frr<n; frr++) {
		if(pr[frr][fc]-pr[frr][fc+c]!=c) break;
	}
	if(g[frr-1][fc+c]=='X') {
		for(rr=1; rr+1<=frr-fr; rr++) {
			if(g[frr-(rr+1)][fc+c]!='X') {
				if(lze(rr, cc) && (ans==-1 || ans>rr*cc)) ans=rr*cc;
				break;
			}
		}
	} else {
		rr=1;
		if(lze(rr, cc) && (ans==-1 || ans>rr*cc)) ans=rr*cc;
	}

	rr=r;
	for(fcc=fc+1; fcc<m; fcc++) {
		if(pd[fr][fcc]-pd[fr+r][fcc]!=r) break;
	}
	if(g[fr+r][fcc-1]=='X') {
		for(cc=1; cc+1<=fcc-fc; cc++) {
			if(g[fr+r][fcc-(cc+1)]!='X') {
				if(lze(rr, cc) && (ans==-1 || ans>rr*cc)) ans=rr*cc;
				break;
			}
		}
	} else {
		cc=1;
		if(lze(rr, cc) && (ans==-1 || ans>rr*cc)) ans=rr*cc;
	}

	printf("%d\n", ans);

	return 0;
}

int lze(int ro, int co)
{
	static int vis[1234][1234];
	int akt_r=fr, akt_c=fc;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) vis[i][j]=0;
	}
	for(int i=akt_r; i<akt_r+ro; i++) {
		for(int j=akt_c; j<akt_c+co; j++) {
			vis[i][j]=1;
		}
	}
	while(1) {
		if(akt_r+ro<n && pr[akt_r+ro][akt_c]-pr[akt_r+ro][akt_c+co]==co) {
			for(int j=akt_c; j<akt_c+co; j++) vis[akt_r+ro][j]=1;
			akt_r++;
		}
		else if(akt_c+co<m && pd[akt_r][akt_c+co]-pd[akt_r+ro][akt_c+co]==ro) {
			for(int i=akt_r; i<akt_r+ro; i++) vis[i][akt_c+co]=1;
			akt_c++;
		}
		else {
			break;
		}
	}
	int ok=1;
	for(int i=0; ok && i<n; i++) {
		for(int j=0; ok && j<m; j++) {
			if(vis[i][j]!=(g[i][j]=='X')) {
				ok=0;
			}
		}
	}
	return ok;
}
