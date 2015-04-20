#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

const long double pi = 3.141592653589793;
const long double inf = 1e18;

struct Point {
	long double x, y;
	Point (long double ix = 0, long double iy = 0): x(ix), y(iy) {}
	bool operator == (Point p) {
		return x == p.x && y == p.y;
	}
	bool operator != (Point p) {
		return x != p.x || y != p.y;
	}
};
vector <Point> Fig;
vector <Point> pts;

long double dist(Point A, Point B) {
	return sqrtl((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

struct Vector {
	long double x, y;
	Vector (long double ix = 0, long double iy = 0): x(ix), y(iy) {}
	Vector (Point p): x(p.x), y(p.y) {}
	Vector (Point p1, Point p2): x(p2.x - p1.x), y(p2.y - p1.y) {}
	Vector operator * (long double k) {
		return Vector(x * k, y * k);
	}
	Vector operator / (long double k) {
		return Vector(x / k, y / k);
	}
	long double size() {
		return sqrtl(x * x + y * y);
	}
};
long double crossProduct(Vector v1, Vector v2) {
	return v1.x * v2.y - v1.y * v2.x;
}
long double dotProduct(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

Point operator + (Point P, Vector V) {
	return Point(P.x + V.x, P.y + V.y);
}

struct Circle {
	Point c;
	long double r;
	Circle (Point ic = Point(), long double ir = 0): c(ic), r(ir) {}
};

long double distPointLine(Point P, Point A, Point B) {
	return crossProduct(Vector(P, A), Vector(P, B)) / dist(A, B);
}

bool isPointOnSegment(Point P, Point A, Point B) {
	return dotProduct(Vector(P, A), Vector(P, B)) <= 0;
}

void intersectionLineCircle (Point A, Point B, Circle C, Point &X, Point &Y) {
	X = Point(-inf, -inf);
	Y = Point(-inf, -inf);
	long double d = -distPointLine(C.c, A, B), l;
	l = sqrtl(C.r * C.r - d * d);
	if (abs(d) > C.r) return;
	Vector AB(A, B);
	Vector V(-AB.y, AB.x);
	Point P = C.c + ((V / V.size()) * d);
	if (abs(d) == C.r) {
		X = P;
	}
	else {
		X = P + (AB / AB.size()) * l;
		Y = P + (AB / AB.size()) * (-l);
	}
	if (X != Point(-inf, -inf) && (X == B || !isPointOnSegment(X, A, B))) X = Point(-inf, -inf);
	if (Y != Point(-inf, -inf) && (Y == B || !isPointOnSegment(Y, A, B))) Y = Point(-inf, -inf);
}

long double angle(Point A, Point B) {
	long double ans = atan2(crossProduct(Vector(A), Vector(B)), dotProduct(Vector(A), Vector(B)));
	if (ans < 0) ans += 2 * pi;
	return ans;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long double dx, dy;
	int n, m, i;
	cin >> n;
	Fig.resize(n + 1);
	for (i = 0; i < n; ++i) cin >> Fig[i].x >> Fig[i].y;
	Fig[n] = Fig[0];
	dx = Fig[0].x;
	dy = Fig[0].y;
	for (i = 0; i <= n; ++i) {
		Fig[i].x -= dx;
		Fig[i].y -= dy;
	}
	Point P, X, Y;
	long double aA, bA, nwA;
	Point aP, bP;
	for (cin >> m; m > 0; --m) {
		cin >> P.x >> P.y;
		P.x -= dx;
		P.y -= dy;
		pts.clear();
		for (i = 0; i < n; ++i) {
			intersectionLineCircle(Fig[i], Fig[i + 1], Circle(Point(), sqrtl(P.x * P.x + P.y * P.y)), X, Y);
			if (X.x != -inf) pts.push_back(X);
			if (Y.x != -inf) pts.push_back(Y);
		}

		aA = bA = 2 * pi;
		aP = bP = P;
		for (i = 0; i < pts.size(); ++i) {
			nwA = angle(P, pts[i]);
			if (nwA < aA) {
				aA = nwA;
				aP = pts[i];
			}
			nwA = angle(pts[i], P);
			if (nwA < bA) {
				bA = nwA;
				bP = pts[i];
			}
		}
		cout.precision(30);
		cout << aA * 180 / pi << " " << bA * 180 / pi << endl;
	}
	return 0;
}