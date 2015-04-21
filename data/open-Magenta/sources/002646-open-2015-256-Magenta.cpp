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
	int S = 6100;
	vector <int> width(S);
	int all = 0;
	for (int h = 1; h <= S; ++h) {
		int w = S / h;
		all += 2 * w;
	}
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
	}
	cout << all << endl;
}