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

typedef int ll;
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
	vector<vector<ld> > real(n);

	vector<ll> ev;
	
	for (ll i = 0; i < n; ++i) {
		ll l;
		cin >> l;
		ll cx = 0;
		for (ll j = 0; j <= l; ++j) {
			pt x;
			cin >> x;
			x.x -= A;
			ev.push_back(x.x);
			lev[i].push_back(x);
		}
	}
	sort(ev.begin(), ev.end());
	ev.resize(distance(ev.begin(), unique(ev.begin(), ev.end())));
	vector<ll> lind(n);
	real.assign(n, vector<ld>(ev.size()));

	for (ll i = 0; i < ev.size(); ++i) {
		for (ll j = 0; j < n; ++j) {
			while (lev[j][lind[j]].x < ev[i] && lev[j][lind[j]+1].x <= ev[i]) {
				++lind[j];
			}
			if (lev[j][lind[j]].x == ev[i]) {
				real[j][i] = lev[j][lind[j]].y;
			} else if (lev[j][lind[j]].x < ev[i] && ev[i] < lev[j][lind[j]+1].x) {
				pt prv = lev[j][lind[j]];
				pt nxt = lev[j][lind[j]+1];
				ld blend = (ev[i]-prv.x)/(nxt.x-prv.x);
				ld cy = prv.y+(nxt.y-prv.y)*blend;
				real[j][i] = cy;
			}
		}
	}
	for (ll i = 0; i < n; ++i) {
		for (ll j = i+1; j < n; ++j) {
			bool undef = true;
			bool fisover = false;
			for (ll k = 0; k < real[i].size(); ++k) {
				if (real[i][k] != real[j][k] && undef) {
					fisover = real[i][k]>real[j][k];
					undef = false;
				}
				if (!undef && real[i][k] != real[j][k]) {
					if (fisover && real[i][k] < real[j][k]) {
						cout << "No" << endl;
						cout << i+1 << " " << j+1 << endl;
						return 0;
					}
					if (!fisover && real[i][k] > real[j][k]) {
						cout << "No" << endl;
						cout << i+1 << " " << j+1 << endl;
						return 0;
					}
				}
			}
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}