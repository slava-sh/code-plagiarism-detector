#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const ld INF = 1e17;
struct pt {
	ld x, y;
	pt(){};
	pt(ld _x, ld _y)
	{
		x = _x;
		y = _y;
	}
};

struct circle {
	pt a;
	ld r;
};

ld vec(pt a, pt b) {
	return a.x * b.y - a.y * b.x;
}

ld dot(pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}

ld dist(pt a, pt b) {
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

pt to(pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);

}

ld dist(pt a, pt b, pt c) {
	return fabsl(vec(to(a, b), to(c, b))/dist(a, b)/2);
}

void tp(circle c, pt a, pt b, pt &t1, pt &t2) {
	ld k = dist(a, b, c.a);
	if (c.r < k)
	{
		t1 = t2 = pt(INF, INF);
		return;
	}
	pt A = pt(to(a, b).y, -to(a, b).x);
	A.y = A.y / (dist(A, pt(0, 0))) * k+c.a.y;
	A.x = A.x / (dist(A, pt(0, 0))) * k+c.a.x;
	ld d = sqrt(c.r * c.r - k * k);
	t1 = pt(A.x + to(a, b).x / (dist( to(a,b), pt(0, 0) ) ) * d,  A.y + to(a, b).y / (dist( to(a,b), pt(0, 0) ) ) * d);
	t2 = pt(A.x + to(b, a).x / (dist( to(b, a), pt(0, 0) ) ) * d,  A.y + to(b, a).y / (dist( to(b, a), pt(0, 0) ) ) * d);
}

bool inside(pt a, pt b, pt c) {
	bool x = true;
	bool y = true;
	if (min(a.x , b.x) > c.x || max(a.x, b.x) < c.x) {
		x = false;
	}
	if (min(a.y , b.y) > c.y || max(a.y, b.y) < c.y) {
		y = false;
	}
	return x && y;
}

circle cir;

bool operator <(const pt &a, const pt &b) {
	pt A(cir.a.x, cir.a.y - cir.r);
	ld v = vec(to(a, A), to(b, A));
	return v > 0;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	ll n;
	cin >> n;
	vector<pt> pts(n);
	vector<pair<pt, pt> > seg(n);
	for (int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y;
		if (i > 0) {
			seg[i] = make_pair(pts[i], pts[i-1]);
		}
	}
	seg[0] = make_pair(pts[0], pts[n-1]);

	ll m;
	cin >> m;
	for (int tn = 0; tn < m; tn++) {
		pt a;
		cin >> a.x >> a.y;

		circle c;
		c.a = pts[0];
		c.r = dist(pts[0], a);
		vector<pt> p;
		for (int i = 0; i < seg.size(); i++) {
			pt z, x;
			tp(c, seg[i].first, seg[i].second, z, x);
			if (z.x != INF) {
				if (inside(seg[i].first, seg[i].second, z)) {
					p.push_back(z);
				}
				if (inside(seg[i].first, seg[i].second, x)) {
					p.push_back(x);
				}
			}
		}
		cir = c;
		sort(p.begin(), p.end());

		cout.precision(20);
		if (p.size() == 0) {
			cout << 360 << " " << 360 << endl;
			continue;
		}

		int li = -1;
		int ri = -1;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] < a) {
				li = i;
			}
		}

		for (int i = p.size() - 1; i >= 0; i--) {
			if (a < p[i]) {
				ri = i;
			}
		}

		ld la = atan2(vec(to(p[li], c.a), to(a, c.a)), dot(to(p[li], c.a), to(a, c.a)));
		ld ra = atan2(vec(to(p[ri], c.a), to(a, c.a)), dot(to(p[ri], c.a), to(a, c.a)));

		la = la * 180 / M_PI;
		ra = ra * 180 / M_PI;

		if (la > 90) {
			la = 360 - la;
		} else if (la < 0) {
			if (la < -90) {
				la = 360+la;
			} else {
				la = -la;
			}
		}

		if (ra > 90) {
			ra = 360 - ra;
		} else if (ra < 0) {
			if (ra < -90) {
				ra = 360+ra;
			} else {
				ra = -ra;
			}
		}
		cout << ra << " " << la << endl;
	}
	return 0;
}