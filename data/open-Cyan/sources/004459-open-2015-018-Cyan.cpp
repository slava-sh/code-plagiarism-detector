#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const double EPS = 1e-6;

struct Point {
	double x, y;
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
};

struct Line {
	double a, b, c;
	Line (double _a, double _b, double _c) {
		a = _a;
		b = _b;
		c = _c;
	}
	Line (double x1, double y1, double x2, double y2) {
		a = y1 - y2;
		b = x2 - x1;
		c = x1 * y2 - x2 * y1;
	}
};

vector<vector<Line> > lines;
vector<vector<double> > dots;

bool getPer(Line l1, Line l2, Point &p) {
	if (l1.a == 0 && l2.a == 0) return false;
	if (l1.a == 0) {
		p = Point((-l2.c + (l2.b * l1.c) / l1.b) / l2.a, -l1.c / l1.b);
		return true;
	}
	if (l2.a == 0) {
		p = Point((-l1.c + (l1.b * l2.c) / l2.b) / l1.a, -l2.c / l2.b);
	}

	if (abs(l1.a * l2.b - l2.a * l2.b) < EPS) {
		return false;
	} else {
		p = Point((l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b), 
			      (l2.a * l1.c - l1.a * l2.c) / (l1.a * l2.b - l2.a * l1.b));

		return true;
	}
}

bool meg(double x, double l, double r) {
	if (x - l > EPS && r - x > EPS) {
		return true;
	}
	return false;
}


double a, b;

bool check(int numL1, int num1, int numL2, int num2) {
	Point p = Point(0, 0);
	if (getPer(lines[numL1][num1], lines[numL2][num2], p)) {

		if (meg(p.x, dots[numL1][num1], dots[numL1][num1 + 1])
			meg(p.x, dots[numL2][num2], dots[numL2][num2 + 1])) {
			return true;
		}

	}

	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> a >> b;

	int c;
	cin >> c;
	lines.resize(c);
	dots.resize(c);
	for (int i = 0; i < c; ++i) {
		int k;
		cin >> k;
		int x, y;
		cin >> x >> y;
		dots[i].push_back(x);
		for (int j = 0; j < k; ++j) {
			int x2, y2;
			cin >> x2 >> y2;
			lines[i].push_back(Line(x, y, x2, y2));
			x = x2;
			y = y2;
			dots[i].push_back(x);
		}
	}

	for (int i = 0; i < c; ++i) {
		for (int j = i + 1; j < c; ++j) {
			int indLF = 0;
			int indLS = 0;

			int i1 = 1, i2 = 1;
			for (int indLF = 0; indLF < (int)lines[i].size(); ++indLF) {
				for (int indLS = 0; indLS < (int)lines[j].size(); ++indLS) {
					if (check(i, indLF, j, indLS)) {
						cout << "No" << endl;
						cout << i + 1 << " " << j + 1 << endl;
						return 0;
					}
				}
			}

			/*while (i1 < (int)dots[i].size() && i2 < (int)dots[j].size()) {
				if (check(i, indLF, j, indLS)) {
					cout << "No" << endl;
					cout << i + 1 << " " << j + 1 << endl;
					return 0;
				}
				if (dots[i][i1] < dots[j][i2]) {
					i1++;
					indLF++;
				} else {
					i2++;
					indLS++;
				}
			}*/
		}
	}
	cout << "Yes" << endl;
	return 0;
}