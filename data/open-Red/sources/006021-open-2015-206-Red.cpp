#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf
#define prev gkldnhkldrgjhdfkgndhjk

using namespace std;

char mem[50000000];
size_t used_mem = 0;

void * operator new (size_t sz) {
	void * res = mem + used_mem;
	used_mem += sz;
	return res;
}

void operator delete (void * p) {}

int n, m, d, q;
int from, to, cost;
int dist, ver, prev, delta;
int * dp[100500];
vector < pair < int, int > > g[100500];
vector < int > num[100500];
queue < pair < int, pair < int, int > > > pq;


int get(int A, int B) {
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < (int)g[i].size() + 2; j++) 
			dp[i][j] = (int)2e9; 
	for (int j = 0; j < (int)g[A].size() + 2; j++) dp[A][j] = 0;
	for (int i = 0; i < g[A].size(); i++) {
		to = g[A][i].F;
		dp[to][num[A][i]] = 1;
		pq.push(mp(-1, mp(to, num[A][i])));
	}
	while (!pq.empty()) {
		dist = -pq.front().F;
		ver = pq.front().S.F;
		prev = pq.front().S.S;
		pq.pop();
		if (dp[ver][prev] < dist) continue;
		for (size_t i = 0; i < g[ver].size(); i++) {
			to = g[ver][i].F;
			delta = abs(g[ver][prev].S - g[ver][i].S);
			if (delta <= d && dp[to][num[ver][i]] > dist + 1) {
				dp[to][num[ver][i]] = dist + 1;
				pq.push(mp(-dist - 1, mp(to, num[ver][i])));
			}
		}
	}
	int res = (int)2e9;
	for (int j = 0; j < (int)g[B].size() + 2; j++)
		res = min(res, dp[B][j]);
	if (res == (int)2e9) res = -1;
	return res;
}
    	

int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; i++) {
		scf("%d%d%d", &from, &to, &cost); 
		g[from].pb(mp(to, cost));
		g[to].pb(mp(from, cost));
		num[from].pb((int)g[to].size() - 1);
		num[to].pb((int)g[from].size() - 1);	
	}
	for (int i = 1; i <= n; i++) {
		prev = (int)g[i].size() + 2;
		dp[i] = new int[prev];
	}
	scf("%d", &q);
	while (q--) {
		scf("%d%d", &from, &to);
		prf("%d\n", get(from, to));
	} 
	return 0;
}