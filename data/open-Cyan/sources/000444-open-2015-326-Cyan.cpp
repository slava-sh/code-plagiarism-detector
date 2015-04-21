#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ll, ll> pll;

ld sqr(ld a) {
	return a*a;
}

struct pt {
	ld x, y;

	pt() {
	}

	pt(ld _x, ld _y) : x(_x), y(_y) {
	}
};

istream &operator>>(istream &i, pt &x) {
	i >> x.x >> x.y;
	return i;
}

pt operator+(const pt &a, const pt &b) {
	return pt(a.x+b.x, a.y+b.y);
}

pt operator-(const pt &a, const pt &b) {
	return pt(a.x-b.x, a.y-b.y);
}

pt operator*(const pt &a, ld x) {
	return pt(a.x*x, a.y*x);
}

pt operator/(const pt &a, ld x) {
	return pt(a.x/x, a.y/x);
}

pt operator*(ld x, const pt &a) {
	return pt(a.x*x, a.y*x);
}

ld len(const pt &a) {
	return sqrtl(a.x*a.x + a.y*a.y);
}

pt norm(const pt &a) {
	ld l = len(a);
	if (l != 0) {
		return a/l;
	}
	return pt(0, 0);
}

ld cross(const pt &a, const pt &b) {
	return a.x*b.y-a.y*b.x;
}

ld dot(const pt &a, const pt &b) {
	return a.x*b.x+a.y*b.y;
}

ld area(const pt &a, const pt &b, const pt &c) {
	return fabsl(cross(b-a, c-a))/2;
}

struct line {
	pt a;
	pt b;
};

ld dist(const line &l, const pt &p) {
	return 2*area(l.a, l.b, p) / len(l.b-l.a);
}

pt toproj(const line &l, const pt &p) {
	pt L = norm(l.b-l.a);
	pt M = pt(L.y, -L.x);

	ld d = dist(l, p);
	pt p1, p2;
	p1 = p+d*M;
	p2 = p-d*M;

	if (dist(l, p1) < dist(l, p2)) {
		return d*M;
	} else {
		return -d*M;
	}
}

struct circle {
	pt c;
	ld r;
};

void intersect(const circle &c, const line &l, vector<pt> &res) {
	ld d = dist(l, c.c);
	pt dp = toproj(l, c.c);
	if (d>c.r+1e-5) {
		return;
	}
	pt zx = dp+c.c;
	if (fabsl(d-c.r)<1e-5) {
		res.push_back(zx);
		return;
	}	
	pt L = norm(l.b-l.a);
	ld ld = sqrt(c.r*c.r-d*d);
	res.push_back(zx+L*ld);
	res.push_back(zx-L*ld);
}

void intersect(const circle &a, const circle &b, vector<pt> &res) {
	ld A = 2*(a.c.x-b.c.x);
	ld B = 2*(a.c.y-b.c.y);
	ld C = sqr(b.r)-sqr(a.r)+sqr(a.c.x)-sqr(b.c.x)+sqr(a.c.y)-sqr(b.c.y);
	line l;
	if (fabsl(A) < 1e-5) {
		l.a = pt(-1, C/B);
		l.b = pt(+1, C/B);
	} else if (fabsl(B) < 1e-5) {
		l.a = pt(C/A, -1);
		l.b = pt(C/A, +1);
	} else {
		l.a = pt(-1, C/B+A/B);
		l.b = pt(+1, C/B-A/B);
	}
	intersect(a, l, res);
}

bool cmp(const pt &a, const pt &b) {
	if (fabsl(a.x-b.x)>1e-5) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

bool operator<(const pt &a, const pt &b) {
	return cmp(a, b);
}

bool cw(const pt &a, const pt &b, const pt &c) {
	return cross(c-b, a-b)<0;
}

bool ccw(const pt &a, const pt &b, const pt &c) {
	return cross(c-b, a-b)>0;
}

vector<pt> convex_hull(vector<pt> a) {
	sort(a.begin(), a.end(), cmp);
	pt p1 = a[0], p2 = a.back();
	vector<pt> d, u;
	d.push_back(p1);
	u.push_back(p1);
	for (ll i = 1; i < a.size(); ++i) {
		if (i == a.size()-1 || cw(p1, a[i], p2)) {
			while (u.size()>= 2 && !cw(u[u.size()-2],u[u.size()-1], a[i])) {
				u.pop_back();
			}
			u.push_back(a[i]);
		}
		if (i == a.size()-1 || ccw(p1, a[i], p2)) {
			while (d.size() >= 2 && !ccw(d[d.size()-2], d[d.size()-1], a[i])) {
				d.pop_back();
			}
			d.push_back(a[i]);
		}
	}
	a.clear();
	for (ll i = 0; i < d.size(); ++i) {
		a.push_back(d[i]);
	}
	for (ll i = u.size()-2; i >= 1; --i) {
		a.push_back(u[i]);
	}
	return a;
}

typedef pair<pt, ll> ev_t;

int main() {
 	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll A, B;
	cin >> A >> B;

	ll n;
	cin >> n;

	vector<vector<pt> > lev(n);
	vector<ld> cpos(n);
	vector<ll> lind(n);

	vector<ev_t> a;
	for (ll i = 0; i < n; ++i) {
		ll l;
		cin >> l;
		for (ll j = 0; j <= l; ++j) {
			pt x;
			cin >> x;
			lev[i].push_back(x);
			ev_t ev = ev_t(x, i);
			a.push_back(ev);
			if (j == 0) {
				cpos[i] = x.y;
				lind[i] = 0;
			}
		}
	}
	sort(a.begin(), a.end());

	vector<pll> perm, oldperm;
	for (ll j = 0; j < n; ++j) {
		perm.push_back(pair<ld, ll>(cpos[j], j));
	}
	sort(perm.begin(), perm.end());

	for (ll i = 0; i < a.size(); ++i) {		
		ld cx = a[i].first.x;
		oldperm = perm;
		if (cx > A) {			
			for (ll j = 0; j < n; ++j) {
				pt prv = lev[j][lind[j]];
				pt nxt = (lind[j] == lev[j].size()-1)?prv:lev[j][lind[j]+1];
				ld blend = (cx-prv.x)/(nxt.x-prv.x);
				ld cy = prv.y+(nxt.y-prv.y)*blend;
				cpos[j] = cy;
			}
			cpos[a[i].second] = a[i].first.y;
			++lind[a[i].second];

			perm.clear();
			for (ll j = 0; j < n; ++j) {
				perm.push_back(pair<ld, ll>(cpos[j], j));
			}
			sort(perm.begin(), perm.end());

			for (ll i = 0; i < perm.size(); ++i) {
				if (perm[i].second != oldperm[i].second && perm[i].first != oldperm[i].first) {
					cout << "No" << endl;
					cout << perm[i].second+1 << " " << oldperm[i].second+1 << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}