#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <memory.h>
#include <time.h>
#include <list>
#include <deque>
#include <functional>
#include <iterator>

#define MX 2005
#define pb push_back
#define rep(i, n) for (int i = 0; i < n; i ++)

using namespace std;
 
int N, M, tot;
int con[MX][MX];
int size[MX], chk[MX], par[MX], num[MX], low[MX];
int ID[MX], n, m;
int C[MX];
int A[MX][MX], sz[MX], mark[MX][MX];
int rlt(0), chd[MX], a[MX];
int b[MX], bn;

int Dfs_num(int v) {
	int u;
	num[v] = tot ++;
	chk[v] = 1;
	rep(i, size[v]) {
		u = con[v][i];
		if (chk[u]) continue;
		par[u] = v;
		Dfs_num(u);
	}
}

int Dfs_low(int v) {
	int u;
	low[v] = num[v];
	rep(i, size[v]) {
		u = con[v][i];
		if (par[v] == u) continue;
		if (num[u] < num[v]) {
			low[v] = min(low[v], num[u]);
			continue;
		}
		if (par[u] != v) continue;
		Dfs_low(u);
		low[v] = min(low[v], low[u]);	
	}
}

int Dfs_bri(int v) {
	int u, en;
	ID[n ++] = v;
	rep(i, size[v]) {
		u = con[v][i];
		if (par[u] != v) continue;
		en = n;
		Dfs_bri(u);
		if (low[u] > num[v]) {
			for (int k = en; k < n; k ++) {
				C[ID[k]] = m;
			}
			a[m] = n - en;
			rlt += (n - en) * (n - en);
			n = en; m ++;
		}
	}
}

void make_link() {
	int v, x, y;
	rep(i, N) {
		rep(k, size[i]) {
			v = con[i][k];
			if (C[i] == C[v]) continue;	
			x = C[i], y = C[v];
			if (mark[x][y]) continue;
			A[x][sz[x] ++] = y;
			A[y][sz[y] ++] = x;
			mark[x][y] = mark[y][x] = 1;
		} 	
	}
}

int find() {
	Dfs_num(0);
	Dfs_low(0);	
	Dfs_bri(0);
	rep(i, n) C[ID[i]] = m;
	a[m] = n;
	m ++;
	rlt += n * n;
	make_link();
}

void dfs(int id) {
	chd[id] += a[id];
	chk[id] = 1;
	int v;
	rep(i, sz[id]) {
		v = A[id][i];
		if (chk[v]) continue;
		dfs(v);
		chd[id] += chd[v];	
	}
	tot += (chd[id] - a[id]) * a[id];
}

int calc() {
	int res(0);
	memset(chk, 0, sizeof(chk));
	int S(0); chk[0] = 1;
	rep(i, bn) {
		for (int k = S; k >= 0; k --) if (chk[k]) chk[k + b[i]] = 1;
		S += b[i];
	}
	rep(i, S + 1) if (chk[i]) res = max(res, i * (S - i));
	return res;
}

int main() {
	
	scanf("%d%d", &N, &M);
	int x, y;
		
	rep(i, M) {
		scanf("%d%d", &x, &y);
		x --, y --;
		con[x][size[x] ++] = y;
		con[y][size[y] ++] = x;
	}
	
	find();
	
	int cnt(0);
	rep(i, m) {
		tot = 0;
		memset(chk, 0, sizeof(chk));
		memset(chd, 0, sizeof(chd));
		dfs(i);
		bn = 0;
		rep(k, sz[i]) {
			int v = A[i][k];
			b[bn ++] = chd[v];
		}
		tot += calc();
		cnt = max(cnt, tot);
	}	
	rlt += cnt;
	cout << rlt << endl;
	return 0;
}

	