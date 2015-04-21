#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define pp pop_back

const ll INF = 1LL << 62LL;

struct Point {
	ld x, y;
	Point(ld=0, ld=0);
	Point operator-(const Point &) const;
	ld len() const;
};

Point::Point(ld x, ld y): x(x), y(y)
{}

Point Point::operator-(const Point &p) const {
	return Point(x - p.x, y - p.y);
}

ld Point::len() const {
	return sqrt(x*x + y*y);
}

//const int S = 6100;

void togo(char c) {
	cout << c << endl;
	cin >> c;
	if (c != 'N')
		exit(0);
}


void Left() {
	togo('L');
}

void Down() {
	togo('D');
}

void Up() {
	togo('U');
}

int main() {
	//freopen("input.txt", "r", stdin);
	int S = 302;
	int all = 0;
	for (int h = 1; h <= S; ++h) {
		int w = S / h;
		all += 4 * w;
	}
	for (int i = 1; i <= S; i+= 2) {
		for (int j = 0; j < 2 * S; ++j)
			Up();
		Left();
		for (int j = 0; j < 2 * S; ++j)
			Down();
		Left();
	}
	//cout << all << endl;
	/*
	int posx = 6005;
	int posy = 0;
	for (int w = S; w >= 1; --w) {
		int hnext = S / (w - 1);
		int h = S / w;
		if (posy < 0) {
			while (-posy < hnext) {
				--posy;
				Down();
			}
			Left();
			while (posy < hnext) {
				++posy;
				Up();
			}
		} else {
			while (posy < hnext) {
				++posy;
				Up();
			}
			Left();
			while (-posy < hnext) {
				--posy;
				Down();
			}

		}
	}*/
	for (int w = S, i = 0, add = -1; i <= 2 * S; ++i, w += add) {
		if (w == 0)
			w = 1,
			add = 1;
		int h = S / w;
		for (int j = 0; j < h; ++j)
			;//Up();
		for (int j = 0; j < 2 * h; ++j)
			;//Down();
		for (int j = 0; j < h; ++j)
			;//Up();
		;//Left();
		cout << w << endl;
	}
	cout << all << endl;
}