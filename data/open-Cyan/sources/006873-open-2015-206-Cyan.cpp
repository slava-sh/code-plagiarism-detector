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

using namespace std;

typedef long double ld;

const ld eps = 1e-10L;

int A, B;
int n, l;
int xx, yy;
ld a1, a2, b1, b2, c1, c2, del, pdel, s1, s2, oy;
vector < pair < int, int > > g[555];

ld getY(int X, pair < int, int > a, pair < int, int > b) {
	a1 = 1.0;
	b1 = 0.0;
	c1 = -1.0 * (ld)X;
	s1 = (ld)a.F * a1 + (ld)a.S * b1 + c1;
	s2 = (ld)b.F * a2 + (ld)b.S * b1 + c1;
	if (s1 * s2 > eps) return 2e9;
	a2 = (ld)a.S - (ld)b.S;
	b2 = (ld)b.F - (ld)a.F;
	c2 = -a2 * (ld)a.F - b2 * (ld)a.S;
	del = a1 * b2 - a2 * b1;
	if (del == 0.0) return 2e9;
	pdel = a1 * c2 - a2 * c1;
	pdel *= (-1.0);
	return pdel / del;
}		

bool inter(int a, int b) {
	bool f1, f2;
	f1 = f2 = false;
	for (size_t i = 0; i < g[a].size(); i++) {
		for (size_t j = 1; j < g[b].size(); j++) {
			oy = getY(g[a][i].F, g[b][j - 1], g[b][j]);
			if (oy + eps < (ld)(g[a][i].S)) {
				f1 = true;
				break;
			}
		}
		if (f1) break;
	}
	for (size_t i = 0; i < g[b].size(); i++) {
		for (size_t j = 1; j < g[a].size(); j++) {
			oy = getY(g[b][i].F, g[a][j - 1], g[a][j]);
			if (oy + eps < (ld)(g[b][i].S)) {
				f2 = true;
				break;
			}
		}
		if (f2) break;
	}
	return (f1 == f2 && f1 == true);
}
                     
int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d%d", &A, &B);
	scf("%d", &n);
	for (int i = 1; i <= n; i++) {	
		scf("%d", &l);
		for (int j = 0; j <= l; j++) {
			scf("%d%d", &xx, &yy);
			g[i].pb(mp(xx, yy));
		}
	}
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (inter(i, j)) {
		puts("No");
		prf("%d %d\n", i, j);
		return 0;
	}
	puts("Yes");
	return 0;
}