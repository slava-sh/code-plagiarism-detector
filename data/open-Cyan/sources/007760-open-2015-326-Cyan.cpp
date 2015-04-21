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

inline
ll gcd(ll a, ll b) {
	while (b != 0) {
		ll t = b;
		b = a%b;
		a = t;
	}
	return a;
}

struct rn_t {
	ll p, q;

	rn_t() {
		p = 0;
		q = 1;
	}

	rn_t(ll x) {
		p = x;
		q = 1;
	}

	rn_t(ll _p, ll _q) {
		p = _p;
		q = _q;
		ll z = gcd(abs(p), abs(q));
		p /= z;
		q /= z;
	}
};

inline
rn_t operator+(const rn_t &a, const rn_t &b) {
	return rn_t(a.p*b.q+a.q*b.p, a.q*b.q);
}

inline
rn_t operator-(const rn_t &a, const rn_t &b) {
	return rn_t(a.p*b.q-a.q*b.p, a.q*b.q);
}

inline
rn_t operator-(const rn_t &a) {
	return rn_t(-a.p, a.q);
}

inline
rn_t operator*(const rn_t &a, const rn_t &b) {
	return rn_t(a.p*b.p, a.q*b.q);
}

inline
rn_t operator/(const rn_t &a, const rn_t &b) {
	return rn_t(a.p*b.q, a.q*b.p);
}

inline
bool operator<(const rn_t &a, const rn_t &b) {
	return a.p*b.q<b.p*a.q;
}

inline
bool operator<=(const rn_t &a, const rn_t &b) {
	return a.p*b.q<=b.p*a.q;
}

inline
bool operator>(const rn_t &a, const rn_t &b) {
	return a.p*b.q>b.p*a.q;
}

inline
bool operator>=(const rn_t &a, const rn_t &b) {
	return a.p*b.q>=b.p*a.q;
}

inline
bool operator==(const rn_t &a, const rn_t &b) {
	return a.p*b.q==b.p*a.q;
}

inline
bool operator!=(const rn_t &a, const rn_t &b) {
	return a.p*b.q!=b.p*a.q;
}

inline
istream &operator>>(istream &i, rn_t &x) {
	i >> x.p;
	x.q = 1;
	return i;
}

typedef rn_t ld;

typedef pair<ll, ll> pll;

struct pt {
	ld x, y;

	pt() {
	}

	pt(ld _x, ld _y) : x(_x), y(_y) {
	}
};

inline
istream &operator>>(istream &i, pt &x) {
	i >> x.x >> x.y;
	return i;
}

inline
pt operator+(const pt &a, const pt &b) {
	return pt(a.x+b.x, a.y+b.y);
}

inline
pt operator-(const pt &a, const pt &b) {
	return pt(a.x-b.x, a.y-b.y);
}

inline
pt operator*(const pt &a, ld x) {
	return pt(a.x*x, a.y*x);
}

inline
pt operator/(const pt &a, ld x) {
	return pt(a.x/x, a.y/x);
}

inline
pt operator*(ld x, const pt &a) {
	return pt(a.x*x, a.y*x);
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

	vector<ld> ev;
	
	for (ll i = 0; i < n; ++i) {
		ll l;
		cin >> l;
		ll cx = 0;
		for (ll j = 0; j <= l; ++j) {
			pt x;
			cin >> x;
			x.x = x.x - A;
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