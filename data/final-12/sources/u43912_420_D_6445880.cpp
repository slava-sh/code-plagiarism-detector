#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define REP(i,n) for (int i=1;i<=(n);++i)
#define FOR(i,a,b) for (int i=(a);i<=(b);++i)
#define ROF(i,a,b) for (int i=(a);i>=(b);--i)
#define FEC(p,u) for (edge*p=head[u];p;p=p->nxt)
using namespace std;
typedef long long LL;
#define lch x<<1
#define rch x<<1|1

int n, m, a[1100000], b[1100000], c[2100000];

struct node{
	int l, r, s;
}T[8000000];
void Build(int L, int R, int x){
	T[x].l = L, T[x].r = R;
	if (L == R) T[x].s = L > m;
	else{
		Build(L, L+R>>1, lch);
		Build((L+R>>1)+1, R, rch);
		T[x].s = T[lch].s+T[rch].s;
	}
}
int find(int y){
	int x(1);
	while (T[x].l < T[x].r){
		if (T[lch].s >= y) x = lch;
		else{ y -= T[lch].s; x = rch; }
	}
	return T[x].l;
}
void Modify(int y, int d){
	int x(1);
	while (T[x].l < T[x].r){
		T[x].s += d;
		x = y <= T[lch].r ? lch : rch;
	}
	T[x].s += d;
}

int main(){
	scanf("%d%d", &n, &m);
	REP(i,n) c[m+i] = i;
	Build(1, n+m, 1);
	int x, y, t;
	ROF(i,m,1){
		scanf("%d%d", &x, &y);
		t = find(y);
		c[i] = c[t];
		Modify(t, -1); Modify(i, 1);
		if (a[c[i]] && a[c[i]] != x){ printf("-1\n"); return 0; }
		a[c[i]] = x;
		if (b[x] && b[x] != c[i]){ printf("-1\n"); return 0; }
		b[x] = c[i];
	}
	
	t = 1;
	REP(i,n) if (!a[i]){
		while (b[t]) ++t;
		a[i] = t;
		++t;
	}
	REP(i,n-1) printf("%d ", a[i]); printf("%d\n", a[n]);
	return 0;
}

