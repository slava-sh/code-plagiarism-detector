#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 2007
#define INF
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)

using namespace std;

typedef long long LL;  

//spojny graf

int n,m,a,b,il,ile,res,pom_res,akt_res,best_res,stale_res,pomile;
int ojc[MAXN],czas[MAXN],low[MAXN],f[MAXN],wartosc[MAXN],t[MAXN];
vector<int> v[MAXN],v2[MAXN];
bool most[MAXN],mozna[MAXN];
queue<int> kolej;

void dfs(int x) {
	czas[x] = low[x] = ++il;
	FOREACH(it,v[x]) if (!czas[*it]) {
		ojc[*it] = x; dfs(*it);
		low[x] = min(low[x],low[*it]);
	} 
	FOREACH(it,v[x]) if (ojc[*it] != x && ojc[x] != *it) low[x] = min(low[x],czas[*it]);
	FOREACH(it,v[x]) if (ojc[*it] == x && low[*it] > czas[x]) most[*it] = true; 
}

bool mosty(int a, int b) {
	return (ojc[a] == b && most[a]) || (ojc[b] == a && most[b]); 
}

void dfs2(int x, int nazwa) {
	f[x] = nazwa;
	++wartosc[nazwa];
	FOREACH(it,v[x]) if (!f[*it] && !mosty(x,*it)) dfs2(*it,nazwa);
}

int jazda_biala_gwiazda(int x, int f) {
	int pomix = wartosc[x];
	FOREACH(it,v2[x]) if (*it != f) {
		int pomix2 = jazda_biala_gwiazda(*it,x);
		pomix += pomix2;
		pom_res += wartosc[x]*pomix2;
	}
	return pomix;
}


int main(){
	scanf("%d%d",&n,&m);
	
	REP(i,m) {
		scanf("%d%d",&a,&b);
		v[a].PB(b);
		v[b].PB(a);
	}
	
	ojc[1] = -1;
	dfs(1);
	
	FOR(i,1,n) if (!f[i]) {
		ile++;
		dfs2(i,ile);
	}
	FOR(i,1,n) if (most[i] && ojc[i] != -1) {
		v2[f[i]].PB(f[ojc[i]]);
		v2[f[ojc[i]]].PB(f[i]);
	}
	
	FOR(i,1,ile)
		stale_res += wartosc[i]*wartosc[i];
	
	mozna[0] = true;
	FOR(i,1,ile) {
		akt_res = pomile = pom_res = 0;
		FOREACH(it,v2[i]) {
			t[pomile++] = jazda_biala_gwiazda(*it,i);
		}
		pom_res += wartosc[i]*(n-wartosc[i]);
	
		sort(t,t+pomile);
		if (t[pomile-1]*2 >= (n-wartosc[i])) {
			akt_res = max(akt_res,t[pomile-1]*(n-wartosc[i]-t[pomile-1]));
		}
		else {
			FOR(j,1,n-wartosc[i]) mozna[j] = false;
			REP(j,pomile) {
				FORD(k,n-wartosc[i]-t[j],0) if (mozna[k]) mozna[k+t[j]] = true;
			}
			FOR(j,0,n-wartosc[i]) if (mozna[j]) {
				akt_res = max(akt_res,j*(n-wartosc[i]-j));
			}
		}
		
		
		best_res = max(best_res,pom_res+akt_res);
	}

	printf("%d\n",best_res+stale_res);
	return 0;
}
