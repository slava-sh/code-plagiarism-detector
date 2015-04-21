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

const ld eps = 1e-9;

int ggg;
int l;
int own[300500];

struct pt {
	ld x, y;
};

int newNum;
int xx, yy;
pt points[500500];

struct seg {
	pt p, q;
	int id;
	ld get_y (ld x) const {
		if (abs(p.x - q.x) < eps) return p.y;
		return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
	}
	bool operator < (const seg &a) const {
		ld x = max(min(p.x, q.x), min(a.p.x, a.q.x));
		return get_y(x) < a.get_y(x) - eps;
	}
};

inline bool intersect1d(ld l1, ld r1, ld l2, ld r2) {
	if (l1 > r1) swap(l1, r1);
	if (l2 > r2) swap(l2, r2);
	return max(l1, l2) <= min(r1, r2) + eps;
}

inline int vec(const pt &a, const pt &b, const pt &c) {
	ld s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return abs(s) < eps ? 0 : s > 0 ? +1 : -1;
}

bool intersect (const seg &a, const seg &b) {
	return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x)
		&& intersect1d(a.p.y, a.q.y, b.p.y, b.q.y)
		&& vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) < 0
		&& vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) < 0;
}

/*bool operator < (const seg &a, const seg &b) {
	ld x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
	return a.get_y(x) < b.get_y(x) - eps;
} */
                                     

struct event {
	ld x;
	int tp, id;
	event () {}
	event (ld x, int tp, int id) : x(x), tp(tp), id(id) {}
	bool operator < (const event &e) const {
		if (fabs(x - e.x) > eps) return x < e.x;
		return tp > e.tp;
	}
};

set < seg > s;
vector < set < seg > :: iterator > where;

inline set < seg > :: iterator prev (set < seg> :: iterator it) {
	return it == s.begin() ? s.end() : --it;
}

inline set < seg > :: iterator next (set <seg> :: iterator it) {
	return ++it;
}

pair < int, int > solve(const vector < seg > &a) {
	int n = (int)a.size();
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n; j++)
			if (intersect(a[i], a[j])) return mp(a[i].id, a[j].id);
	return mp(-1, -1);
}
                     
int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	int l;
	scf("%d%d", &ggg, &ggg);
	int sz = 0;
	vector < seg > have;
	seg govno;
	scf("%d", &n);
/*	if (ggg == 3 && n == 2) {
		puts("Yes");
		return 0;
	} */
	for (int i = 1; i <= n; i++) {
		scf("%d", &l);
		for (int j = 0; j <= l; j++) {
			scf("%d%d", &xx, &yy);
			points[++sz].x = (ld)(xx);
			points[sz].y = (ld)(yy);
			if (j > 0) {
				newNum = (int)have.size() + 1;
				own[newNum] = i;
				govno.id = newNum;
				govno.p = points[sz - 1];
				govno.q = points[sz];
				have.pb(govno);
			} 
		}
	}
	pair < int, int > lol = solve(have);
	if (lol == mp(-1, -1)) puts("Yes");
		else prf("No\n%d %d\n", min(own[lol.F], own[lol.S]), max(own[lol.F], own[lol.S]));
	return 0;
}