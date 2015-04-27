#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 1000005
using namespace std;

struct node{
	int k, p, l, r, s;
};

int n, m, rt, cnt;
node T[N];

void rotate(int x, int d){
	swap(T[x].l, T[x].r);
	int t = d ? T[x].r : T[x].l;
	swap(T[x].k, T[t].k);
	if (!d) swap(T[x].r, T[t].r);
	else swap(T[x].l, T[t].l);
	T[d ? T[x].l : T[x].r].p = x;
	T[d ? T[t].l : T[t].r].p = t;
	swap(T[t].l, T[t].r);
	T[t].s = T[T[t].l].s + T[T[t].r].s + 1;
}

void splay(int rt, int x){
	int p, g, c;
	while (x != rt){
		p = T[x].p;
		g = T[p].p;
		if (p == rt){
			rotate(p, x == T[p].l);
			x = p;
		}
		else{
			c = (x == T[p].l);
			if (c == (p == T[g].l)) rotate(g, c), rotate(T[x].p, c);
			else rotate(p, c), rotate(g, !c);
			x = g;
		}
	}
}

int insert(int p, int x, int k){
	if (!x){
		T[++cnt].k = k;
		T[cnt].p = p;
		T[cnt].s = 1;
		T[cnt].l = T[cnt].r = 0;
		return cnt;
	}
	if (k < T[x].k) T[x].l = insert(x, T[x].l, k);
	else T[x].r = insert(x, T[x].r, k);
	++T[x].s;
	return x;
}

void insert(int &rt, int k){
	rt = insert(0, rt, k);
	splay(rt, cnt);
}

void splayRank(int rt, int r){
	int t, x = rt;
	while (1){
		t = T[T[x].l].s;
		if (t == r) break;
		if (r > t) r -= t + 1, x = T[x].r;
		else x = T[x].l;
	}
	splay(rt, x);
}

void splayKey(int rt, int k){
	int x = rt;
	while (x && T[x].k != k){
		if (k > T[x].k) x = T[x].r;
		else x = T[x].l;
	}
	splay(rt, x);
}

int rankCut(int rt, int lo, int hi){
	splayRank(rt, lo - 1);
	int t = T[rt].r, r;
	splayRank(t, hi - lo + 1);
	T[r = T[t].l].p = 0;
	T[t].s -= T[r].s;
	T[t].l = 0;
	return r;
}

void link(int rt, int x, int d){
	if (!d) T[rt].l = x;
	else T[rt].r = x;
	T[rt].s += T[x].s;
	T[x].p = rt;
}


int cup, pos, map[N], rmap[N];

int main(){
	scanf("%d%d", &n, &m);
	insert(rt, -1);
	FOE(i,0,n) insert(rt, i);
	CLR(map, -1);
	CLR(rmap, -1);
	FOR(i,0,m){
		scanf("%d%d", &cup, &pos);
		int t = rankCut(rt, pos, pos);
		if (map[T[t].k] != -1 && map[T[t].k] != cup){
			puts("-1");
			return 0;
		}
		if (rmap[cup] != -1 && rmap[cup] != T[t].k){
			puts("-1");
			return 0;
		}
		map[T[t].k] = cup;
		rmap[cup] = T[t].k;
		splayRank(rt, 0);
		splayRank(T[rt].r, 0);
		link(T[rt].r, t, 0);
	}

	int t = 1;
	FOR(i,0,n){
		if (map[i] == -1){
			while (rmap[t] != -1) ++t;
			map[i] = t;
			rmap[t] = i;
		}
		printf("%d ", map[i]);
	}
	
	return 0;
}
