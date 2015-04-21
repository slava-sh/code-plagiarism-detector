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

typedef double ld;

const ld eps = 1e-7;

int A, B;
int n, l;
int xx, yy;                                      
vector < pair < int, int > > g[555];

/*ld getY(int X, pair < int, int > a, pair < int, int > b) {
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
} */

struct pt {
	ld x, y;
	pt () {x = y = 0.0;}
	pt (int x, int y) : x(1.0 * x), y(1.0 * y) {}
	bool operator < (const pt &p) const {
		return x < p.x - eps || abs(x - p.x) < eps && y < p.y - eps;
	}
};

struct line {
	ld a, b, c;
	line () {}
	line (pt p, pt q) {
		a = (q.y - p.y) / (q.x - p.x);
		b = -1.0;
		c = p.y - a * p.x;
	}
/*	void norm() {
		ld z = sqrt(a * a + b * b);
		if (abs(z) > eps) a /= z, b /= z, c /= z;
	}
	ld dist(pt p) const {
		return a * p.x + b * p.y + c;
	}*/
};	

#define det(a, b, c, d) (a * d - b * c)

inline bool betw(ld l, ld r, ld x) {
	return min(l, r) < x + eps && x < max(l, r) + eps;
}

inline bool in(ld a, ld b, ld c, ld d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a,c ) <= min(b, d) + eps;
}

bool into(pt a, pt b, pt c, pt d) {
	pt le, ri;
	line m(a, b);
	line n(c, d);
	ld s1 = m.a * c.x + m.b * c.y + m.c;
	ld s2 = m.a * d.x + m.b * d.y + m.c;
	if (s1 * s2 >= 0) return false;
	s1 = n.a * a.x + n.b * a.y + n.c;
	s2 = n.a * b.x + n.b * b.y + n.c;
	if (s1 * s2 >= 0) return false;
	return true;
}

bool inter(int a, int b) {
	bool f1, f2;
	for (size_t i = 1; i < g[a].size(); i++)
		for (size_t j = 1; j < g[b].size(); j++) {
			pt t1, t2, t3, t4;
			t1 = pt(g[a][i - 1].F, g[a][i - 1].S);
			
			t2 = pt(g[a][i].F, g[a][i].S);
			
			t3 = pt(g[b][j - 1].F, g[b][j - 1].S);
			           
			t4 = pt(g[b][j].F, g[b][j].S); 
			if (into(t1, t2, t3, t4)) return true;
		}
	return false;	
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