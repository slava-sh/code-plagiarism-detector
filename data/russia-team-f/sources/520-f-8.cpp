#pragma comment(linker, "/STACK:0x04000000")
#include <algorithm>
#include <cmath>
#include <math.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const long double EPS = 1e-10;

bool Equal(long double a, long double b) {
	return fabs(a - b) < EPS;
}

bool Less(long double a, long double b) {
	return b - a > EPS;
}

bool LessEq(long double a, long double b) {
	return Less(a, b) || Equal(a, b);
}

struct Point {
	long double x;
	long double y;

	Point(long double x = 0, long double y = 0) : x(x), y(y) {
	}

	Point Normal() const {
		return Point(-y, x);
	}

	long double Length() const {
		return sqrt(x * x + y * y);
	}
};

Point operator+(const Point &a, const Point &b) {
	return Point(a.x + b.x, a.y + b.y);
}

Point operator-(const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}

Point operator*(const Point &a, long double k) {
	return Point(a.x * k, a.y * k);
}

Point operator/(const Point &a, long double k) {
	return Point(a.x / k, a.y / k);
}

istream &operator>>(istream &in, Point &p) {
	in >> p.x >> p.y;
	return in;
}

Point q;
vector<Point> ps;
int n;

long double Cross(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

long double Dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

long double Distance(const Point &c, const Point &a, const Point &b) {
	Point ac = c - a;
	Point ab = b - a;
	return fabs(Cross(ab, ac)) / ab.Length();
}

bool OnLine(const Point &c, const Point &a, const Point &b) {
	Point ca = a - c;
	Point cb = b - c;
	return Equal(Cross(ca, cb), 0);
}

bool OnSegment(const Point &c, const Point &a, const Point &b) {
	Point ca = a - c;
	Point cb = b - c;
	return Equal(Cross(ca, cb), 0) && LessEq(Dot(ca, cb), 0);
}

vector<long double> ang;

long double Norm(long double a) {
	while (Less(a, 0)) {
		a += 360;
	}
	while (!LessEq(a, 360)) {
		a -= 360;
	}
	return a;
}

const long double PI = acos(-1.0);

long double ToDeg(long double a) {
	return a / PI * 180;
}

void Proc(const Point &a) {
	ang.push_back(Norm(ToDeg(atan2(Cross(a, q), Dot(a, q)))));
}

pair<long double, long double> F() {
	ang.clear();
	long double r = q.Length();
	for (int i = 0; i < n; i++) {
		long double h = Distance(ps[0], ps[i], ps[i + 1]);
		if (LessEq(h, r)) {
			Point t = ps[i] - ps[i + 1];
			t = t.Normal();
			t = t / t.Length();
			if (OnLine(t * h, ps[i], ps[i + 1])) {
				t = t * h;
			} else {
				t = t * -h;
			}
			long double g = sqrt(r * r - h * h);
			Point s = ps[i] - ps[i + 1];
			s = s / s.Length();
			if (OnSegment(t + s * g, ps[i], ps[i + 1])) {
				Proc(t + s * g);
			}
			if (OnSegment(t - s * g, ps[i], ps[i + 1])) {
				Proc(t - s * g);
			}
		}
	}
	if (ang.empty()) {
		return make_pair(360, 360);
	}
	sort(ang.begin(), ang.end());
	return make_pair(Norm(360 - ang.back()), Norm(ang[0]));
}

int main() {
#ifdef NAVI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
#endif
	cin >> n;
	ps.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> ps[i];
	}
	Point t = ps[0];
	for (int i = 0; i < n; i++) {
		ps[i] = ps[i] - t;
	}
	ps.push_back(ps[0]);
	int m;
	cin >> m;
	cout.setf(cout.fixed);
	cout.precision(20);
	for (int i = 0; i < m; i++) {
		cin >> q;
		q = q - t;
		auto res = F();
		cout << res.first << " " << res.second << "\n";
	}
}